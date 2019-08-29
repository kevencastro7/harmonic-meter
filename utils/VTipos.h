
/**************************************************************************************************
  Nome do Arquivo:  VTipos.h
Vers�o: 
  Autor:            Joaci Morais 
  Descri��o:        Cont�m os tipos de vari�veis primitivas do sistema.

**************************************************************************************************/

#ifndef VTIPOS_H
#define VTIPOS_H

#include <stdint.h>

/*************************************************************************************************/
/*                                               TIPOS                                           */
/*************************************************************************************************/

typedef uint16_t (*task_routine_t)( uint16_t Tipo , void *Payload );
#define WFB_ELEMENT_ARRAY_SIZE 3200
#define ESPECTRO_ARRAY_SIZE WFB_ELEMENT_ARRAY_SIZE/4
typedef enum
{
	OK = 0,
	ERR,
	TIMEOUT
}return_codes_t;

typedef struct
{
	char ID;
	char Tamanho;
	char ValorADC_1;
	char ValorADC_2;
	char ValorADC_3;
	char ValorADC_4;
}msg_protocol;

/*************************************************************************************************/
/*                                               DEFINI��ES                                      */
/*************************************************************************************************/


#ifndef TRUE
  #define TRUE 1
#endif

#ifndef FALSE
  #define FALSE 0
#endif

#ifndef ZERO
  #define ZERO 0
#endif

#ifndef NULL
  #define NULL 0
#endif


#endif // VTIPOS_H
