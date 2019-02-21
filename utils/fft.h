/*
 * fft.h
 *
 *  Created on: 21 de fev de 2019
 *      Author: Keven
 */

#ifndef FFT_H_
#define FFT_H_
#include "kiss_fft.h"
#include "kiss_fftr.h"
#include "math.h"

#define PI 3.14159265359
#define SAMPLES 1536

kiss_fftr_cfg cfg;
kiss_fft_scalar* cx_in;
kiss_fft_cpx* cx_out;

void init_fft ( void );

#endif /* FFT_H_ */
