#include <stdio.h>

int main(){

    int notas[5];

    for(int i=0; i<5; i++){

        printf("Digite as suas notas\n");
        scanf("%d", &notas[i]);
    }


    int *pt=notas;

    for(int i=0; i<5; i++){

        if(*(pt+i) < 6.0){
            *(pt+i)=6.0;
        }
    }

    printf("Notas corrigidas\n");

    for(int i=0; i<5; i++){

        printf(" %d ", notas[i]);
    }

    return 0;
}
