#include <stdio.h>


float calcularvalormedio( int t, int vetor[], float media);
void reorganzar( int t, int vetor[], float r1); 

int main( ){

    int n;
   float media=0;
   float s=0;
    do{

        printf("Digite o tamanho do vetor\n");
        scanf("%d", &n);

        if( n >=1000){
            printf("Numero maior que 1000, digite novamente\n");
            
        } 

    } while( n >=1000);

     int vet[n]; //  aqui meu vetor é  criado com n tamanho 

    for( int i=0; i<n; i++){

        printf("Digite os elementos do vetor\n");
        scanf("%d", &vet[i]);
        s=s+vet[i];
    }

    media=s/n;
    
       
     float r1=calcularvalormedio(n, vet,media);
      reorganzar(n, vet,media);
      
      printf("\n"); 

     printf("%.2f\n", r1);

    return 0;
    
}

float calcularvalormedio(int t, int vetor[], float media){
    float soma=0;
   media=0;

    for( int i=0; i<t; i++){
        soma=soma+vetor[i];  // [4 8 6 10 2 6]
    }

     printf("Soma de todos os elementos %.2f\n", soma);
    media=soma/t;

    return media;
}


void reorganzar( int t, int vetor[], float r1){

     int distancia1, distancia2;
     int j=0; int i=0;

        
   distancia1=vetor[i] - r1;
   distancia2=vetor[j] - r1;
   if( distancia1 <0){ 
    distancia1=distancia1 * -1; // irei transformar negativo em positivo se tiver algum caso.
   }

   if(distancia2 < 0){
    distancia2=distancia2 * -1; 
   }
    

     int ax=0;
    for( int i=0; i<t; i++){

        for( int j=0; j<t; j++){

            distancia1=vetor[i]-r1;
            if( distancia1 <0){
                distancia1=distancia1 * -1;
                        }
                        distancia2=vetor[j]-r1;
                        if( distancia2 < 0){
                            distancia2=distancia2 * -1;
                        }

            if(distancia1>distancia2){
              ax= vetor[i];
              vetor[i]=vetor[j];
              vetor[j]=ax;
            } else if( distancia1 == distancia2){
                if(vetor[i] > vetor[j]){
                    ax= vetor[i];
                    vetor[i]=vetor[j];
                    vetor[j]=ax;
                }
            }
        }
    }

    for( int i=t-1; i>=0; i--){
        printf("\n");
        printf("%d", vetor[i]);
    }

}



