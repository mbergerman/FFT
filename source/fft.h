#include <complex.h>
#include <stddef.h>

/**
 * Computar la transformada rápida de fourier.
 *
 * @param[out] in Puntero al buffer con datos de entrada. 
 * @param[out] out Puntero al buffer con datos de salida.
 * @param[in] N Cantidad de puntos. En caso de no ser una potencia de dos, el comportamiento es indeterminado.
 */
void fft(float complex *in, float complex *out, size_t N);