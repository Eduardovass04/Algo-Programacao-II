#include <stdio.h>

int main(){

    int vetor1[5]={1,2,3,4,5};
    int vetor2[5]={6,7,8,9,10};

    int *p1=vetor1;

    int *p2=vetor2;

    int aux[5];
    int c=0;

    for(int i=0; i<5; i++){

        aux[c++]=vetor1[i];
    }

    //trocas
            
       
    for(int j=0; j<5; j++){

        *(p1+j)=*(p2+j);
    }
     

    for(int i=0; i<5; i++){


        *(p2+i)=aux[i];
         }
    
 
         printf("\n");
         
    printf("Vetor 1 apos a troca:\n");
    for(int i=0; i<5; i++){

        printf(" %d ", vetor1[i]);
    }

    printf("\n");

        printf("Vetor 2 apos a troca\n");
    for(int j=0; j<5; j++){

        printf(" %d ", vetor2[j]);
    }

    return 0;
}
