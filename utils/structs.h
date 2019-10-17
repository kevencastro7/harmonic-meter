/*
 * structs.h
 *
 *  Created on: 7 de mai de 2018
 *      Author: giovanni
 */

#ifndef INC_STRUCTS_H_
#define INC_STRUCTS_H_

#include "VTipos.h"
#include "stm32f4xx.h"
#include "kiss_fft.h"

typedef struct {
	float V;
	float I;
	float resampled_V;
	float resampled_I;
}cte_ade_t;

typedef struct{
	uint8_t 			comp_freq; 			//compensar_frequencia_modo_fabrica
	float 			v_nominal;			//tensao_nominal
	float 			v_full_scale;		//fundo_de_escala_tensao
	float 			i_full_scale;		//fundo_de_escala_corrente
	char* 	spi_ade;  			//porta_spi_ade
	GPIO_InitTypeDef		pin_irq_ade;		//pino_irq_ade
	GPIO_InitTypeDef 		pin_energy_arm;		//pino_energy_arm
	GPIO_InitTypeDef 		pin_mode;			//pino modo ur ou modo fabrica
}meter_json_t;

typedef struct{
	int		tp;
	int		tc;
	int 	multiplicidade;
	int 	tc_type;
}device_json_t;

typedef struct {
	float VA;
	float VB;
	float VC;
	float IA;
	float IB;
	float IC;
}calibration_wfb_json_t;

typedef struct {
	kiss_fft_scalar* VA;
	kiss_fft_scalar* IA;
	kiss_fft_scalar* VB;
	kiss_fft_scalar* IB;
	kiss_fft_scalar* VC;
	kiss_fft_scalar* IC;
}buffer_read_t;

typedef struct {
	kiss_fft_cpx* VA;
	kiss_fft_cpx* IA;
	kiss_fft_cpx* VB;
	kiss_fft_cpx* IB;
	kiss_fft_cpx* VC;
	kiss_fft_cpx* IC;

}espectro_t;

typedef struct{
	cte_ade_t 				cte_ade;
	meter_json_t 			meter_json;
	device_json_t			device_json;
	calibration_wfb_json_t 	calibration_wfb_json;
	buffer_read_t			buffer_read;
	espectro_t				espectro;
	uint32_t 				burst_read[1025];
	int 					count;
	int 					full_buffer;
	int                     buffer;
}controller;
#endif /* INC_STRUCTS_H_ */
