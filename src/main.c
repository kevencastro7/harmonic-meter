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
#define PI 3.14159265359

int main(void)
{
	port_init();
	led_init();
	uint32_t tempo = port_micros();

	int tam = 128 * 12;
	int nc = tam/2 + 1;
	kiss_fftr_cfg cfg = kiss_fftr_alloc( tam ,0 ,NULL,NULL );
	kiss_fft_scalar* cx_in = (kiss_fft_scalar *) malloc(tam * sizeof(kiss_fft_scalar));
	kiss_fft_cpx* cx_out = (kiss_fft_cpx *) malloc(nc * sizeof(kiss_fft_cpx));

	for (int i = 0; i<tam;i++)
	{
		cx_in[i] = cos(2*PI*i/128) + 0.5*cos(4*PI*i/128);
	}

	while (1)
	{
		tempo = port_micros();

		led_write(GPIO_Pin_All,1);
		for(int i = 0;i<6;i++)
		{
			kiss_fftr( cfg , cx_in , cx_out );
		}
		led_write(GPIO_Pin_All,0);
		tempo = port_micros()-tempo;

		port_sleep_ms(500);
	}

	free(cx_in);
	free(cx_out);
	free(cfg);
}
