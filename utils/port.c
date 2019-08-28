/*
 * port.c
 *
 *  Created on: Mar 21, 2018
 *      Author: kevencastro7
 */

#include <port.h>

																	//------------------COMENTÃ�RIOS-------------------//
void port_init(void)												// InicializaÃ§Ã£o
{
	RCC_ClocksTypeDef RCC_Clocks;									// VariÃ¡vel referente ao clock
	RCC_GetClocksFreq (&RCC_Clocks);								// Receber o valor do clock
	(void) SysTick_Config (RCC_Clocks.HCLK_Frequency / (1000));	// Um tick a cada 1 micro segundo
}

void SysTick_Handler (void)											// Handler do Systick
{
	micros++;														// Incrementa a variÃ¡vel micros
}

uint32_t port_micros( void )										// FunÃ§Ã£o port_micros
{
	return micros;													// Retorna micros
}

void port_sleep_us( uint32_t delay )								// Delay em microsegundos
{
	uint32_t start = micros;										// Temporizador
	while((micros - start) <= delay);								// Espera o tempo da variÃ¡vel delay em microsegundos
}

void port_sleep_ms( uint32_t delay )								// Delay em milisegundos
{
	uint32_t start = micros;										// Temporizador
	while((micros - start) <= delay*1000);							// Espera o tempo da variÃ¡vel delay em milisegundos
}
