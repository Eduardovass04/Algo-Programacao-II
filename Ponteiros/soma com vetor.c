// usando é ponteiro

#include <stdio.h>

void soma(int t,  int *ptr);

int main(){

    int tamanho;

    printf("Digite o tamanho do vetor\n");
    scanf("%d", &tamanho);

    int vet[tamanho];

    for(int i=0; i<tamanho; i++){
        printf("Digite os elementos do vetor\n");
        scanf("%d", &vet[i]);
    }

    int *ponteiro=vet;

    soma(tamanho, ponteiro);

    return 0;
}

void soma(int t,  int *ptr){

    int soma=0;

    for( int i=0; i<t; i++){  
          soma=soma+*(ptr+i);
    }

    printf(" soma :%d\n", soma);
}
