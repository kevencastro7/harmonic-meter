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
#include "tm_stm32f4_spi.h"
#define PI 3.14159265359

int main(void)
{
	port_init();
	led_init();
	uint16_t Data_in[3];
	uint16_t Data_out[] = {0x00B7, 0x0001, 0xFFFE};
	uint16_t dummy = 0x00BF;
	led_write(GPIO_Pin_5, 1);
	/* SCK = PA5, MOSI = PA7, MISO = PA6 */
	TM_SPI_Init(SPI1, TM_SPI_PinsPack_1);

	while (1)
	{
		led_write(GPIO_Pin_5, 0);
		TM_SPI_WriteMulti16(SPI1, Data_out, 3);
		led_write(GPIO_Pin_5, 1);
		//port_sleep_ms(1);
		led_write(GPIO_Pin_5, 0);
		TM_SPI_ReadMulti16(SPI1, Data_in, dummy, 3);
		led_write(GPIO_Pin_5, 1);
		//port_sleep_us(5);
	}
	free(Data_in);
}
