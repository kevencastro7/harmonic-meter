/*
 * fft.c
 *
 *  Created on: 21 de fev de 2019
 *      Author: Keven
 */
#include "fft.h"

void init_fft ( controller* ct )
{
	cfg = kiss_fftr_alloc( WFB_ELEMENT_ARRAY_SIZE/2 ,0 ,NULL,NULL );
}

void burst_to_buffer( controller* ct)
{
	for(int i = 0; i < 897; i+= 7)
	{
		ct->buffer_read.IA[ct->count] = sinc4_decoder(ct->burst_read[i]);
		ct->buffer_read.VA[ct->count] = sinc4_decoder(ct->burst_read[i+1]);
		ct->buffer_read.IB[ct->count] = sinc4_decoder(ct->burst_read[i+2]);
		ct->buffer_read.VB[ct->count] = sinc4_decoder(ct->burst_read[i+3]);
		/*ct->buffer_read.IC[ct->count] = sinc4_decoder(ct->burst_read[i+4]);
		ct->buffer_read.VC[ct->count] = sinc4_decoder(ct->burst_read[i+5]);*/

		ct->count++;
		if(ct->count == 1600)
		{
			ct->buffer = 0;
			ct->full_buffer = 1;
		}
		else if (ct->count >= 3200)
		{
			ct->buffer = 1;
			ct->full_buffer = 1;
			ct->count = 0;
		}
	}
}

kiss_fft_scalar sinc4_decoder(uint32_t burst)
{
	kiss_fft_scalar temp = 0.0;
	int signal = (burst & 0x80000000) >> 31;
	int32_t man = (burst >> 4);
	if (signal == 1)
	{
		man |=  0xFF000000;
	}
	temp = ((float) man);
	return temp/1300000;
}

void calc_fft( controller* ct)
{
	if (ct->buffer == 0)
	{
		kiss_fftr( cfg , ct->buffer_read.IA , ct->espectro.IA );
		kiss_fftr( cfg , ct->buffer_read.VA , ct->espectro.VA );
		kiss_fftr( cfg , ct->buffer_read.IB , ct->espectro.IB );
		kiss_fftr( cfg , ct->buffer_read.VB , ct->espectro.VB );
		/*kiss_fftr( cfg , ct->buffer_read.IC , ct->espectro.IC );
		kiss_fftr( cfg , ct->buffer_read.VC , ct->espectro.VC );*/
	}
	else
	{
		kiss_fftr( cfg , &ct->buffer_read.IA[1600] , ct->espectro.IA );
		kiss_fftr( cfg , &ct->buffer_read.VA[1600] , ct->espectro.VA );
		kiss_fftr( cfg , &ct->buffer_read.IB[1600] , ct->espectro.IB );
		kiss_fftr( cfg , &ct->buffer_read.VB[1600] , ct->espectro.VB );
		/*kiss_fftr( cfg , &ct->buffer_read.IC[1600] , ct->espectro.IC );
		kiss_fftr( cfg , &ct->buffer_read.VC[1600] , ct->espectro.VC );*/
	}

}
