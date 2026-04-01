#include <stdio.h>

 int main(){

   int mat[3][3];

    for( int i=0 ;i<3; i++){

       for( int j=0; j<3; j++){

        printf("Digite os elementos\n");
        scanf("%d", &mat[i][j]);
       }

    }

     for( int i=0; i<3; i++){
      for( int j=0; j<3; j++){
        if( i+j==0  || i+j==2  || i+j==4){
          mat[i][j]=0;
        }
      }
     }

      for( int i=0; i<3; i++){
        
        for( int j=0; j<3; j++){
          if( mat[i][j]==0){
            printf("%4c", 'x');
          } else{
            printf("%4d",mat[i][j]);
          }
      }
      printf("\n");
    }



       return 0;
 }
