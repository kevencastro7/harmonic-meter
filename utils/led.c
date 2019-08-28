/*
 * led.c
 *
 *  Created on: 24 de set de 2018
 *      Author: kevencastro7
 */
#include "led.h"

																	//------------------COMENTÃ�RIOS-------------------//

void led_init ( void )												// InicializaÃ§Ã£o
{
		GPIO_InitTypeDef gpio;										// Struct da GPIO
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);		// Ativar clock da GPIO
		gpio.GPIO_Pin = LED4_PIN | LED3_PIN | LED5_PIN | LED6_PIN;  // Pinos utilizados
		gpio.GPIO_Mode = GPIO_Mode_OUT;								// Modo de saÃ­da
		gpio.GPIO_Speed = GPIO_Speed_50MHz;							// Velocidade do GPIO
		GPIO_Init(GPIOD, &gpio);									// InicializaÃ§Ã£o da GPIO

}

void led_write(uint16_t GPIO_Pin, BitAction BitVal)					// Escrita no led
{
	GPIO_WriteBit(GPIOD, GPIO_Pin, BitVal);							// Escreve no Pino GPIO_Pin o valor BitVal
}

