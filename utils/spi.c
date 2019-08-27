/*
 * spi.c
 *
 *  Created on: 27 de ago de 2019
 *      Author: Keven
 */

#include <spi.h>

void spi_init( void )
{
	SPI_InitTypeDef SPI_InitStruct;

	/* Set default settings */
	SPI_StructInit(&SPI_InitStruct);
	/* Enable SPI clock */
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

	/* Init pins */
	gpio_init(GPIOA, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_High_Speed, GPIO_AF_SPI1);

	/* Set options */
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_16b;

	/* Fill SPI settings */
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;

	/* SPI mode */
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge;

	/* Disable first */
	SPI1->CR1 &= ~SPI_CR1_SPE;

	/* Init SPI */
	SPI_Init(SPI1, &SPI_InitStruct);

	/* Enable SPI */
	SPI1->CR1 |= SPI_CR1_SPE;

}

void gpio_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed, uint8_t Alternate)
{
	uint32_t pinpos;

	/* Check input */
	if (GPIO_Pin == 0x00) {
		return;
	}

	/* Enable GPIOx clock */
	RCC->AHB1ENR |= (1 << ((uint32_t)GPIOx - (GPIOA_BASE)) / ((GPIOB_BASE) - (GPIOA_BASE)));

	/* Set alternate functions for all pins */
	for (pinpos = 0; pinpos < 0x10; pinpos++) {
		/* Check pin */
		if ((GPIO_Pin & (1 << pinpos)) == 0) {
			continue;
		}

		/* Set alternate function */
		GPIOx->AFR[pinpos >> 0x03] = (GPIOx->AFR[pinpos >> 0x03] & ~(0x0F << (4 * (pinpos & 0x07)))) | (Alternate << (4 * (pinpos & 0x07)));
	}

	/* Do initialization */
	gpio_int_init(GPIOx, GPIO_Pin, GPIO_Mode_AF, GPIO_OType, GPIO_PuPd, GPIO_Speed);
}

void gpio_int_init (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed)
{
	uint8_t pinpos;
	uint8_t ptr = ((uint32_t)GPIOx - (GPIOA_BASE)) / ((GPIOB_BASE) - (GPIOA_BASE));
	uint16_t GPIO_UsedPins[11] = {0,0,0,0,0,0,0,0,0,0,0};

	/* Go through all pins */
	for (pinpos = 0; pinpos < 0x10; pinpos++) {
		/* Check if pin available */
		if ((GPIO_Pin & (1 << pinpos)) == 0) {
			continue;
		}

		/* Pin is used */
		GPIO_UsedPins[ptr] |= 1 << pinpos;

		/* Set GPIO PUPD register */
		GPIOx->PUPDR = (GPIOx->PUPDR & ~(0x03 << (2 * pinpos))) | ((uint32_t)(GPIO_PuPd << (2 * pinpos)));

		/* Set GPIO MODE register */
		GPIOx->MODER = (GPIOx->MODER & ~((uint32_t)(0x03 << (2 * pinpos)))) | ((uint32_t)(GPIO_Mode << (2 * pinpos)));

		/* Set GPIO OTYPE register */
		GPIOx->OTYPER = (GPIOx->OTYPER & ~(uint16_t)(0x01 << pinpos)) | ((uint16_t)(GPIO_OType << pinpos));

		/* Set GPIO OSPEED register */
		GPIOx->OSPEEDR = (GPIOx->OSPEEDR & ~((uint32_t)(0x03 << (2 * pinpos)))) | ((uint32_t)(GPIO_Speed << (2 * pinpos)));
	}
}

void SPI_WriteMulti16(SPI_TypeDef* SPIx, uint16_t* dataOut, uint32_t count) {
	uint32_t i;

	/* Check if SPI is enabled */
	SPI_CHECK_ENABLED(SPIx);

	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);

	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dataOut[i];

		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);

		/* Read data register */
		(void)SPIx->DR;
	}
}

void SPI_ReadMulti16(SPI_TypeDef* SPIx, uint16_t* dataIn, uint16_t dummy, uint32_t count) {
	uint32_t i;

	/* Check if SPI is enabled */
	SPI_CHECK_ENABLED(SPIx);

	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPIx);

	for (i = 0; i < count; i++) {
		/* Fill output buffer with data */
		SPIx->DR = dummy;

		/* Wait for SPI to end everything */
		SPI_WAIT(SPIx);

		/* Save data to buffer */
		dataIn[i] = SPIx->DR;
	}
}
