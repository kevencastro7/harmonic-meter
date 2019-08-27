/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "port.h"
#include "led.h"
#include "kiss_fft.h"
#include "kiss_fftr.h"
#include "math.h"
#include "structs.h"
#include "spi.h"
#include "ADE9000_Defines.h"
#define PI 3.14159265359
uint32_t tempo;
int main(void)
{
	port_init();
	led_init();
	spi_init();
	uint16_t Data_in[2];
	uint16_t Data_out[] = {0x00B0, 0xABCD, 0x5678};
	uint16_t dummy = 0x00B8;
	//led_write(GPIO_Pin_5, 1);
	/* SCK = PA5, MOSI = PA7, MISO = PA6 */

	while (1)
	{
		set_registrador(USER_PERIOD, TAM_USER_PERIOD, DEFAULT_USER_PERIOD);
		get_registrador(USER_PERIOD, TAM_USER_PERIOD, Data_in);
	}
	free(Data_in);
}

void DMA2_Stream2_IRQHandler(void)
{
/* Test on DMA Stream Transfer Complete interrupt */
if(DMA_GetITStatus(DMA2_Stream2, DMA_FLAG_TCIF2))
{
/* Clear DMA Stream Transfer Complete interrupt pending bit */
DMA_ClearITPendingBit(DMA2_Stream2, DMA_FLAG_TCIF2);
// Add code here to process buffer
}
}
