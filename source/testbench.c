#include <stdio.h>
#include <stdlib.h>
#include "fft.h"

void printComplexVector(float complex* z, int n);

int main() {

    FILE* fp;
    if ((fp = fopen("../data/input.txt","r")) == NULL){
       printf("Error opening input file");
       return 1;
    }
    
    int n;
    fscanf(fp,"%d", &n);
    printf("\nLa cantidad de muestras es: %d\n", n);
    
    float complex *input = (float complex*)malloc(sizeof(float complex)*n);
    float complex *output = (float complex*)malloc(sizeof(float complex)*n);

    for(int i = 0; i < n; i++){
        fscanf(fp, "%f", (input+i));
    }

    fclose(fp);

    fft(input, output, n);

    if ((fp = fopen("../data/output.txt","w+")) == NULL){
       printf("Error opening output file");
       return 1;
    }

    for(int i = 0; i < n; i++){
        fprintf(fp, "%.10f + %.10fj\n", creal(output[i]), cimag(output[i]));
    }

    fclose(fp);

    free(input);
    free(output);

    return 0;
}

void printComplexVector(float complex* z, int n){
    for(int i = 0; i < n; i++){
        printf("Value #%d = %.2f + %.2fi\n", i, creal(z[i]), cimag(z[i]));
    }
}