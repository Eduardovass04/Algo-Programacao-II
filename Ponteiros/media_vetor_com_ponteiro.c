#include <stdio.h>

float media_vetor(int t, float *v);

int main(){

    int n;

    printf("Digite o t do vetor\n");
    scanf("%d", &n);

    float vetor[n];

    for(int i=0; i<n; i++){

        printf("Digite os elementos do vetor\n");
        scanf("%f", &vetor[i]);
    }

    float r= media_vetor(n, vetor);


    printf("%.2f\n", r);

    return 0;

}

float media_vetor(int t, float *v){

    float soma=0; float media=0;

    for( int i=0; i<t; i++){
        soma=soma  + *(v+i);
    }
    media=soma/t;

    return media;
}
