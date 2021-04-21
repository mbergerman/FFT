#include <complex.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int uint;

/**
 * Computar la transformada rápida de fourier.
 *
 * @param[out] in Puntero al buffer con datos de entrada. 
 * @param[out] out Puntero al buffer con datos de salida.
 * @param[in] N Cantidad de puntos. En caso de no ser una potencia de dos, el comportamiento es indeterminado.
 */
void fft(float complex *in, float complex *out, size_t N);

/**
 * Computar la transformada de de fourier por definición.
 *
 * @param[out] in Puntero al buffer con datos de entrada. 
 * @param[out] out Puntero al buffer con datos de salida.
 * @param[in] N Cantidad de puntos. En caso de no ser una potencia de dos, el comportamiento es indeterminado.
 */
void dft(float complex *in, float complex *out, size_t N);

float complex W(uint i, size_t N);

uint bitrev(uint bits, uint n);