// matriz de triangulo

#include <stdio.h>

int main(){

     int n1;


     do{

        printf("Digite um numero\n");
        scanf("%d", &n1);
     } while( n1 %2 ==0 || n1 <0);

          
     int mat[n1][n1];

      for( int i=0; i<n1; i++){

        for( int j=0; j<n1; j++){

            if( j>=(n1-1)/2-i  && j<=(n1-1)/2+i && i<=(n1-1)/2){
                mat[i][j]=1;
            } else{
                mat[i][j]=0;
            }
        }
      }

       for( int i=0; i<n1; i++){

        for( int j=0; j<n1; j++){

            printf("%4d", mat[i][j]);
        }
        printf("\n");
       }

        return 0;
}
