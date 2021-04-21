#include "fft.h"

#define PI 3.14159265358979

float complex W(uint i, size_t N){
    return cexpf(-I*2*PI*(i)/N);
}

uint bitrev(uint bits, uint n){
    uint r = 0;
    for(uint i = 0; i < n; i++){
        r += ((bits>>i) & 0b1)<<(n-i-1);
    }
    return r;
}

void fft(float complex *in, float complex *out, size_t N){
    uint GA = log2(N);

    if(out != in){
        for(uint n = 0; n < N; n++){
            *(out + n) = *(in + n);
        }
    }

    uint gr = 1; //Número de grupos por etapas
    uint mar = N/2; //Número de mariposas por grupo
    for(uint r = 0; r < GA; r++){
        for(uint g = 0; g < gr; g++){
            for(uint m = 0; m < mar; m++){
                float complex A = *(out + m + 2*mar*g);
                float complex B = *(out + m + 2*mar*g + (N>>(r+1)));
                float complex C = W(bitrev( 2*g ,GA), N);
                float complex T = B*C;
                *(out + m + 2*mar*g) = A+T;
                *(out + m + 2*mar*g + (N>>(r+1))) = A-T;
            }
        }
        mar = (mar>>1);
        gr = (gr<<1);
    }

    
    for(uint k = 0; k < N; k++){
        uint i = bitrev(k, GA);
        if(i > k){
            float complex aux = *(out + k);
            *(out + k) = *(out + i);
            *(out + i) = aux;
        }
    }
}

void dft(float complex *in, float complex *out, size_t N){
    float complex *output = (float complex*)malloc(sizeof(float complex)*N);
    for(uint k = 0; k < N; k++){
        output[k] = 0;
        for(uint n = 0; n < N; n++){
            output[k] += in[n] * cexpf(-2*PI*I*k*n/N);
        }
    }
    for(uint k = 0; k < N; k++){
        out[k] = output[k];
    }
    free(output);
}