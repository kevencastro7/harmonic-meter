/*
 * debug.c
 *
 *  Created on: 6 de nov de 2015
 *      Author: ox_jodm_xo
 */

#include "debug.h"
																	//------------------COMENTÃ�RIOS-------------------//

void Delay ( __IO uint32_t nCount )									// delay
{
		while ( nCount-- )
				;
}

void debug_init ( void )											// InicializaÃ§Ã£o
{
		GPIO_InitTypeDef GPIO_InitStruct;							// Struct da GPIO
		USART_InitTypeDef USART_InitStruct;							// Struct da USART

	 	 	 	 													//-------------ConfiguraÃ§Ã£o do Clock--------------//
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 , ENABLE );	// Ativar clock da USART
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB , ENABLE );	// Ativar clock da GPIO
	 	 	 	 													//------------------------------------------------//

	 	 	 	 													//--------------ConfiguraÃ§Ã£o dos Pinos------------//
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;			// Pinos de TX e RX
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;					// Modo de OperaÃ§Ã£o
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;				// Velocidade da GPIO
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;					// Tipo de saÃ­da
		GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;					// Pull-UP
		GPIO_Init( GPIOB , &GPIO_InitStruct );						// InicializaÃ§Ã£o da GPIO
	 	 	 	 													//------------------------------------------------//

		GPIO_PinAFConfig( GPIOB , GPIO_PinSource6 , GPIO_AF_USART1 );// TX
		GPIO_PinAFConfig( GPIOB , GPIO_PinSource7 , GPIO_AF_USART1 );// RX

		USART_InitStruct.USART_BaudRate = 115200;					// Baudrate
		USART_InitStruct.USART_WordLength = USART_WordLength_8b;	// Tamanho da palavra
		USART_InitStruct.USART_StopBits = USART_StopBits_1;			// 1 bit de stop
		USART_InitStruct.USART_Parity = USART_Parity_No;			// Sem bit de paridade
		USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // Sem Flow Control
		USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;// Modo de Transmissor e Receptor
		USART_Init( USART1 , &USART_InitStruct );					// InicializaÃ§Ã£o da USART

		USART_Cmd( USART1 , ENABLE );								// AtivaÃ§Ã£o da USART
}

void debug_write_msg_string(char *ID,uint16_t *info)				// Enviar mensagem
{
	msg_protocol msg;												// Cria struct msg_protocol
	msg.ID = 254;													// Atribui o ID
	msg.Tamanho = 4;												// Atribui Tamanho
	msg.ValorADC_1 = info[0]/16;									// Atribui o valor
	msg.ValorADC_2 = info[2]/16;									// Atribui o valor
	msg.ValorADC_3 = info[4]/16;									// Atribui o valor
	msg.ValorADC_4 = info[6]/16;									// Atribui o valor
	debug_write_protocol_string(msg);								// Enviar protocolo
}

void debug_write_protocol_string ( msg_protocol info )				// Enviar protocolo
{
	debug_write_string(&info.ID);									// Envar ID
	debug_write_string(&info.Tamanho);								// Enviar Tamanho
	debug_write_string(&info.ValorADC_1);							// Enviar valor do ADC
	debug_write_string(&info.ValorADC_2);							// Enviar valor do ADC
	debug_write_string(&info.ValorADC_3);							// Enviar valor do ADC
	debug_write_string(&info.ValorADC_4);							// Enviar valor do ADC
}

void debug_write_string ( volatile char *info )						// Enviar String
{
		while ( *info  != 0)										// Enquanto a string nÃ£o acabar
		{
				while ( ! ( USART1->SR & 0x00000040 ) )				// Espera o registrador de dados esvaziar
						;
				USART_SendData( USART1 , *info );					// Enviar 1 byte
				info++;												// Incrementa o ponteiro
		}
}


uint16_t debug_read()												// Leitura de dados
{
    if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE))				// Se tiver dados pra receber
    {
    	return USART_ReceiveData(USART1);							// Retorna o valor lido
    }
     return 0;
}

void debug_PutChar(char c)
{
    // Wait until transmit data register is empty
    while (!USART_GetFlagStatus(USART1, USART_FLAG_TXE));
    // Send a char using USART1
    USART_SendData(USART1, c);
}

void debug_PutString(char *s)
{
    // Send a string
    while (*s)
    {
       debug_PutChar(*s++);
    }
}

void debug_PutUint16(uint16_t c)
{
    // Wait until transmit data register is empty
    while (!USART_GetFlagStatus(USART1, USART_FLAG_TXE));
    // Send a char using USART1
    USART_SendData(USART1, c);
}
uint16_t debug_GetChar()
{
    // Wait until data is received
    while (!USART_GetFlagStatus(USART1, USART_FLAG_RXNE));
    // Read received char
    return USART_ReceiveData(USART1);
}
