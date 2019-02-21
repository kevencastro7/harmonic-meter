/*
 * led.h
 *
 *  Created on: 24 de set de 2018
 *      Author: kevencastro7
 */

#ifndef LED_H_
#define LED_H_
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void led_init ( void );
void led_write(uint16_t GPIO_Pin, BitAction BitVal);

#endif /* LED_H_ */
