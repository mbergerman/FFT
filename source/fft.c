#include "fft.h"

#define PI 3.14159265358979

typedef unsigned int uint;

void fft(float complex *in, float complex *out, size_t N){
    for(uint k = 0; k < N; k++){
        out[k] = 0;
        for(uint n = 0; n < N; n++){
            out[k] += in[n] * cexpf(-2*PI*I*k*n/N);
        }
    }
}