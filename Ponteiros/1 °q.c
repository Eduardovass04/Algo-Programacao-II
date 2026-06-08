#include <stdio.h>

//[10 15 20 25 30 12 18]
// distância: 130 km

void somaDistancias( int *distancia, int *total);
int main(){

int vet[7]={10,15,20,25,30,12,18};

int total=0;
int *t=&total;


somaDistancias( vet, t);

return 0;
}


void somaDistancias( int *distancia, int *total){

for( int i=0; i<7; i++){

    *total+=distancia[i];
}

printf("Total de distancia percorrida durante a semana: %d\n", *total);
}
