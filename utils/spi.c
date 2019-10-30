/*
 * spi.c
 *
 *  Created on: 27 de ago de 2019
 *      Author: Keven
 */

#include <spi.h>
#include "ADE9000_Defines.h"

void spi_init( void )
{
	SPI_InitTypeDef SPI_InitStruct;

	/* Set default settings */
	SPI_StructInit(&SPI_InitStruct);
	/* Enable SPI clock */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_SPI1, ENABLE);

	/* Init pins */
	gpio_init(GPIOA, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_High_Speed, GPIO_AF_SPI1);
	irq0_gpio_init();
	GPIOx_CS = GPIOC;
	GPIO_Pin_CS = GPIO_Pin_5;
	chip_select_init();
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

void chip_select_init()
{
	GPIO_InitTypeDef gpio;
	if(GPIOx_CS == GPIOA)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	else if(GPIOx_CS == GPIOB)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	else if(GPIOx_CS == GPIOC)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	else if(GPIOx_CS == GPIOD)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	gpio.GPIO_Pin = GPIO_Pin_CS;
	gpio.GPIO_Mode = GPIO_Mode_OUT;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx_CS, &gpio);
}

void chip_select()
{
	GPIO_WriteBit(GPIOx_CS, GPIO_Pin_CS, 0);
}

void chip_deselect()
{
	GPIO_WriteBit(GPIOx_CS, GPIO_Pin_CS, 1);
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

void dma_init(uint32_t* pTmpBuf1 , int page)
{
	chip_select();
	if (page == 0)
		pTmpBuf1[0] = 0x8008;
	else
		pTmpBuf1[0] = 0xC008;

	DMA_InitTypeDef DMA_InitStructure;

	/* Set default settings */
	DMA_StructInit(&DMA_InitStructure);
	/* Enable DMA clock */
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_DMA2, ENABLE);

	/* Deinitialize DMA Streams */
	DMA_DeInit(DMA2_Stream3); //SPI1_TX_DMA_STREAM
	DMA_DeInit(DMA2_Stream2); //SPI1_RX_DMA_STREAM

	DMA_InitStructure.DMA_BufferSize = (uint16_t)2050;

	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable ;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull ;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single ;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;

	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&(SPI1->DR));
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;

	/* Configure Tx DMA */
	DMA_InitStructure.DMA_Channel = DMA_Channel_3;
	DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) pTmpBuf1;
	DMA_Init(DMA2_Stream3, &DMA_InitStructure);

	/* Configure Rx DMA */
	DMA_InitStructure.DMA_Channel = DMA_Channel_3;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) pTmpBuf1;
	DMA_Init(DMA2_Stream2, &DMA_InitStructure);

	DMA_Cmd(DMA2_Stream3, ENABLE); /* Enable the DMA SPI TX Stream */
	DMA_Cmd(DMA2_Stream2, ENABLE); /* Enable the DMA SPI RX Stream */

	/*Configure Interrupt */
	DMA_ITConfig(DMA2_Stream2, DMA_IT_TC, ENABLE);
	NVIC_InitTypeDef   NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the SPI Rx/Tx DMA request */
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Rx, ENABLE);
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Tx, ENABLE);

	SPI_Cmd(SPI1, ENABLE);

}

int configuracao_default()
{
	uint16_t temp[2];
	set_registrador(USER_PERIOD, TAM_USER_PERIOD, DEFAULT_USER_PERIOD);
	get_registrador(USER_PERIOD, TAM_USER_PERIOD, temp);
	for (int i = 0; i < TAM_USER_PERIOD; i++)
	{
		if(temp[i] != DEFAULT_USER_PERIOD[i])
			return 0;
	}
	set_registrador(VLEVEL, TAM_VLEVEL, DEFAULT_VLEVEL);
	get_registrador(VLEVEL, TAM_VLEVEL, temp);
	for (int i = 0; i < TAM_VLEVEL; i++)
	{
		if(temp[i] != DEFAULT_VLEVEL[i])
			return 0;
	}
	set_registrador(DIP_LVL, TAM_DIP_LVL, DEFAULT_DIP_LVL);
	get_registrador(DIP_LVL, TAM_DIP_LVL, temp);
	for (int i = 0; i < TAM_DIP_LVL; i++)
	{
		if(temp[i] != DEFAULT_DIP_LVL[i])
			return 0;
	}
	set_registrador(SWELL_LVL, TAM_SWELL_LVL, DEFAULT_SWELL_LVL);
	get_registrador(SWELL_LVL, TAM_SWELL_LVL, temp);
	for (int i = 0; i < TAM_SWELL_LVL; i++)
	{
		if(temp[i] != DEFAULT_SWELL_LVL[i])
			return 0;
	}
	set_registrador(RUN, TAM_RUN, DEFAULT_RUN);
	get_registrador(RUN, TAM_RUN, temp);
	for (int i = 0; i < TAM_RUN; i++)
	{
		if(temp[i] != DEFAULT_RUN[i])
			return 0;
	}
	set_registrador(CONFIG1, TAM_CONFIG1, DEFAULT_CONFIG1);
	get_registrador(CONFIG1, TAM_CONFIG1, temp);
	for (int i = 0; i < TAM_CONFIG1; i++)
	{
		if(temp[i] != DEFAULT_CONFIG1[i])
			return 0;
	}
	set_registrador(CFMODE, TAM_CFMODE, DEFAULT_CFMODE);
	get_registrador(CFMODE, TAM_CFMODE, temp);
	for (int i = 0; i < TAM_CFMODE; i++)
	{
		if(temp[i] != DEFAULT_CFMODE[i])
			return 0;
	}
	set_registrador(ACCMODE, TAM_ACCMODE, DEFAULT_ACCMODE);
	get_registrador(ACCMODE, TAM_ACCMODE, temp);
	for (int i = 0; i < TAM_ACCMODE; i++)
	{
		if(temp[i] != DEFAULT_ACCMODE[i])
			return 0;
	}
	set_registrador(CONFIG3, TAM_CONFIG3, DEFAULT_CONFIG3);
	get_registrador(CONFIG3, TAM_CONFIG3, temp);
	for (int i = 0; i < TAM_CONFIG3; i++)
	{
		if(temp[i] != DEFAULT_CONFIG3[i])
			return 0;
	}
	set_registrador(WFB_CFG, TAM_WFB_CFG, DEFAULT_WFB_CFG);
	get_registrador(WFB_CFG, TAM_WFB_CFG, temp);
	for (int i = 0; i < TAM_WFB_CFG; i++)
	{
		if(temp[i] != DEFAULT_WFB_CFG[i])
			return 0;
	}
	set_registrador(EP_CFG, TAM_EP_CFG, DEFAULT_EP_CFG);
	get_registrador(EP_CFG, TAM_EP_CFG, temp);
	for (int i = 0; i < TAM_EP_CFG; i++)
	{
		if(temp[i] != DEFAULT_EP_CFG[i])
			return 0;
	}
	set_registrador(WFB_PG_IRQEN, TAM_WFB_PG_IRQEN, DEFAULT_WFB_PG_IRQEN);
	get_registrador(WFB_PG_IRQEN, TAM_WFB_PG_IRQEN, temp);
	for (int i = 0; i < TAM_WFB_PG_IRQEN; i++)
	{
		if(temp[i] != DEFAULT_WFB_PG_IRQEN[i])
			return 0;
	}
	set_registrador(MASK0, TAM_MASK0, DEFAULT_MASK0);
	get_registrador(MASK0, TAM_MASK0, temp);
	for (int i = 0; i < TAM_MASK0; i++)
	{
		if(temp[i] != DEFAULT_MASK0[i])
			return 0;
	}
	return 1;
}

void set_registrador(uint16_t endereco_registrador, uint32_t tamanho_dado, uint16_t* dado)

{
	chip_select();
	endereco_registrador = ((endereco_registrador << 4) & 0xFFF0); //Desloca o endereço para a esquerda e configura o bit 4 como 0

	uint32_t i;

	/* Check if SPI is enabled */
	SPI_CHECK_ENABLED(SPI1);

	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPI1);

	SPI1->DR = endereco_registrador;

	/* Wait for SPI to end everything */
	SPI_WAIT(SPI1);

	/* Read data register */
	(void)SPI1->DR;

	for (i = 0; i < tamanho_dado; i++) {
		/* Fill output buffer with data */
		SPI1->DR = dado[i];

		/* Wait for SPI to end everything */
		SPI_WAIT(SPI1);

		/* Read data register */
		(void)SPI1->DR;
	}
	chip_deselect();

}

void get_registrador(uint16_t endereco_registrador, uint32_t tamanho_dado, uint16_t* dado)
{
	chip_select();
	endereco_registrador = (((endereco_registrador << 4) & 0xFFF0)+8); //Desloca o endereço para a esquerda e configura o bit 4 como 1

	uint32_t i;

	/* Check if SPI is enabled */
	SPI_CHECK_ENABLED(SPI1);

	/* Wait for previous transmissions to complete if DMA TX enabled for SPI */
	SPI_WAIT(SPI1);

	SPI1->DR = endereco_registrador;

	/* Wait for SPI to end everything */
	SPI_WAIT(SPI1);

	/* Read data register */
	(void)SPI1->DR;

	for (i = 0; i < tamanho_dado; i++) {
		/* Fill output buffer with data */
		SPI1->DR = endereco_registrador;

		/* Wait for SPI to end everything */
		SPI_WAIT(SPI1);

		/* Read data register */
		dado[i] = SPI1->DR;
	}
	chip_deselect();
}

void irq0_gpio_init( void )
{
    GPIO_InitTypeDef GPIO_InitStruct;

    /* Enable clock for GPIOD */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    /* Enable clock for SYSCFG */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    /* Set pin as input */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void irq0_init( void )
{
    clear_interrupt();
    /* Set variables used */
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    /* Tell system that you will use PD0 for EXTI_Line0 */
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource0);

    /* PD0 is connected to EXTI_Line0 */
    EXTI_InitStruct.EXTI_Line = EXTI_Line0;
    /* Enable interrupt */
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    /* Interrupt mode */
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    /* Triggers on rising and falling edge */
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    /* Add to EXTI */
    EXTI_Init(&EXTI_InitStruct);

    /* Add IRQ vector to NVIC */
    /* PD0 is connected to EXTI_Line0, which has EXTI0_IRQn vector */
    NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
    /* Set priority */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    /* Set sub priority */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    /* Enable interrupt */
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct);
}

void clear_interrupt( void )
{
	set_registrador(STATUS0, TAM_STATUS0, DEFAULT_MASK0);
}

int get_last_page ( void )
{
	uint16_t temp[TAM_WFB_TRG_STAT];
	get_registrador(WFB_TRG_STAT, TAM_WFB_TRG_STAT, temp);
	int page = (temp[0] & 0xF000) >> 12;
	if (page < 8) return 0;
	else return 1;
}
