/*
 * debug.h
 *
 *  Created on: 6 de nov de 2015
 *      Author: ox_jodm_xo
 */

#ifndef DEBUG_H_
#define DEBUG_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "VTipos.h"

void Delay ( __IO uint32_t nCount );
void debug_init ( void );
void debug_write_string ( volatile char *info );
void debug_write_protocol_string ( msg_protocol info );
void debug_write_int_to_string(uint16_t info,int complete);
void debug_write_msg_string(char* ID, uint16_t *info);
uint16_t debug_read();
void debug_PutChar(char c);
void debug_PutString(char *s);
uint16_t debug_GetChar();
void debug_PutUint16(uint16_t c);

#endif /* DEBUG_H_ */
