/*
 * port.h
 *
 *  Created on: Mar 19, 2018
 *      Author: jmorais
 */

#ifndef PORT_H_
#define PORT_H_

#include "stm32f4xx.h"
#include <VTipos.h>

uint32_t micros;

void port_init( void );

uint32_t port_micros( void );

void port_sleep_us( uint32_t delay );
void port_sleep_ms( uint32_t delay );


#endif /* PORT_H_ */
