/*
 * fft.c
 *
 *  Created on: 21 de fev de 2019
 *      Author: Keven
 */
#include "fft.h"

void init_fft ( void )
{
	cfg = kiss_fftr_alloc( SAMPLES ,0 ,NULL,NULL );
	cx_in = (kiss_fft_scalar *) malloc(SAMPLES * sizeof(kiss_fft_scalar));
	cx_out = (kiss_fft_cpx *) malloc(SAMPLES * sizeof(kiss_fft_cpx));
}
