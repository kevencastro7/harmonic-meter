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
	float IN;
}calibration_wfb_json_t;

typedef struct {
  int16_t VA[WFB_ELEMENT_ARRAY_SIZE];
  int16_t IA[WFB_ELEMENT_ARRAY_SIZE];
  int16_t VB[WFB_ELEMENT_ARRAY_SIZE];
  int16_t IB[WFB_ELEMENT_ARRAY_SIZE];
  int16_t VC[WFB_ELEMENT_ARRAY_SIZE];
  int16_t IC[WFB_ELEMENT_ARRAY_SIZE];
  int16_t IN[WFB_ELEMENT_ARRAY_SIZE];
}burst_read_t;

typedef struct {
	int    VA_CONT;
	float VA_ABS[ESPECTRO_ARRAY_SIZE];
	float VA_ANG[ESPECTRO_ARRAY_SIZE];

	int    IA_CONT;
	float IA_ABS[ESPECTRO_ARRAY_SIZE];
	float IA_ANG[ESPECTRO_ARRAY_SIZE];

	int    VB_CONT;
	float VB_ABS[ESPECTRO_ARRAY_SIZE];
	float VB_ANG[ESPECTRO_ARRAY_SIZE];

	int    IB_CONT;
	float IB_ABS[ESPECTRO_ARRAY_SIZE];
	float IB_ANG[ESPECTRO_ARRAY_SIZE];

	int    VC_CONT;
	float VC_ABS[ESPECTRO_ARRAY_SIZE];
	float VC_ANG[ESPECTRO_ARRAY_SIZE];

	int    IC_CONT;
	float IC_ABS[ESPECTRO_ARRAY_SIZE];
	float IC_ANG[ESPECTRO_ARRAY_SIZE];

	int    IN_CONT;
	float IN_ABS[ESPECTRO_ARRAY_SIZE];
	float IN_ANG[ESPECTRO_ARRAY_SIZE];
}espectro_t;

typedef struct{
	cte_ade_t 				cte_ade;
	meter_json_t 			meter_json;
	device_json_t			device_json;
	calibration_wfb_json_t 	calibration_wfb_json;
	burst_read_t			burst_read;
	espectro_t				espectro;
}controller;

#endif /* INC_STRUCTS_H_ */
