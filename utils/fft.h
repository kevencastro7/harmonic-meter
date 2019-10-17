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
#include "VTipos.h"
#include "structs.h"

#define PI 3.14159265359

kiss_fftr_cfg cfg;

void init_fft ( controller* ct );
void burst_to_buffer( controller* ct);
kiss_fft_scalar sinc4_decoder(uint32_t burst);
void calc_fft( controller* ct);

#endif /* FFT_H_ */
