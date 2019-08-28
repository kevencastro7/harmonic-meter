/*
 * spi.h
 *
 *  Created on: 27 de ago de 2019
 *      Author: Keven
 */

#ifndef SPI_H_
#define SPI_H_

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_dma.h"
#include "string.h"

/**
 * @brief  Check SPI busy status
 */
#define SPI_IS_BUSY(SPIx) (((SPIx)->SR & (SPI_SR_TXE | SPI_SR_RXNE)) == 0 || ((SPIx)->SR & SPI_SR_BSY))

/**
 * @brief  SPI wait till end
 */
#define SPI_WAIT(SPIx)            while (SPI_IS_BUSY(SPIx))

/**
 * @brief  Checks if SPI is enabled
 */
#define SPI_CHECK_ENABLED(SPIx)   if (!((SPIx)->CR1 & SPI_CR1_SPE)) {return;}

/**
 * @brief  Checks if SPI is enabled and returns value from function if not
 */
#define SPI_CHECK_ENABLED_RESP(SPIx, val)   if (!((SPIx)->CR1 & SPI_CR1_SPE)) {return (val);}
uint32_t pTmpBuf1[2048];
GPIO_TypeDef* GPIOx_CS;
uint16_t GPIO_Pin_CS;
void spi_init( void );
void chip_select_init();
void chip_select();
void chip_deselect();
void gpio_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed, uint8_t Alternate);
void gpio_int_init (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed);
void dma_init( void );
int configuracao_default();
void set_registrador(uint16_t endereco_registrador, uint32_t tamanho_dado,  uint16_t* dado);
void get_registrador(uint16_t endereco_registrador, uint32_t tamanho_dado, uint16_t* dado);
void irq0_gpio_init( void );
void irq0_init( void );
void clear_interrupt( void );
#endif /* SPI_H_ */
