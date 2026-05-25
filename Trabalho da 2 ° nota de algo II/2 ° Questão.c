#include <stdio.h>

void iniciamvogais(int m1, int n ,char m[m1][n][25]);
void iniciam_com_letra_maiusculas(int m1, int n ,char m[m1][n][25]);
void iniciam_com_numeros(int m1, int n ,char m[m1][n][25]);
void iniciam_com_vogais_letras_maiusculas(int m1, int n ,char m[m1][n][25]);

int main(){
 
    int n,m; // dimensão das matrizes

    int op;
    
    printf("Digite o tamanho M e N da matriz\n");
    scanf("%d %d", &m, &n);
   
    char matriz[m][n][25];

    for( int i=0; i<m; i++){
        for( int j=0; j<n; j++){
            printf("Digite uma string\n");
            scanf(" %[^\n]", matriz[i][j]);
        }
    }

    do{

        printf("Escolha uma opcao:\n");
        printf("1: Quantidade de strings que  iniciam com vogal\n ");
        printf("2: Quantidade de strings que iniciam com letras maiusculas\n");
        printf("3: Quantidade de strings que iniciam com numeros\n");
        printf("4: Quantidade de strings que iniciam com vogais e letras maiusculas\n");
        printf("0: para sair\n");
        scanf("%d", &op);

        if(op==1){

            iniciamvogais(m, n, matriz);
        
        } else if( op==2){

            iniciam_com_letra_maiusculas(m, n, matriz);
        
        } else if( op==3){
            
             iniciam_com_numeros(m, n, matriz);
             
        } else if( op==4){

           iniciam_com_vogais_letras_maiusculas(m, n, matriz);
             
        } else if( op==0){

            printf("Encerrando....\n");

        } else{

            printf("Opcao invalida, tente novamente \n");
        }
    } while(op !=0 );

    return 0;

}

void iniciamvogais(int m1, int n ,char m[m1][n][25] ){

    // [a][e] [i] [o] [u]
    // [a n a]
    // [0] verdadeiro
    
    for( int i=0; i<m1; i++){
          int c=0;

        for( int j=0; j<n; j++){

            if( m[i][j][0] == 'a' || m[i][j][0]=='e' || m[i][j][0]=='i'
            || m[i][j][0]=='o' || m[i][j][0]=='u' ||  m[i][j][0] == 'A' || m[i][j][0]=='E' || m[i][j][0]=='I'
            || m[i][j][0]=='O' || m[i][j][0]=='U')
            c++;
        }
        printf("Linha %d: %d iniciam com vogais\n", i,c);
    }

   
}
void iniciam_com_letra_maiusculas(int m1, int n ,char m[m1][n][25]){
    

    for( int i=0; i<m1;i++){
        int c1=0; // meu contador para strings que  iniciam com letras maiúsculas
        for( int j=0; j<n; j++){
            if(m[i][j][0]>= 'A' && m[i][j][0] <='Z' ){ //[P i a u í ]
                                                    //  [{0} 1 2 3 4 ]
             
                c1++;
            }
          
        }
          printf("Linha %d:  %d  iniciam com letras maiusculas\n", i, c1);
    }
    
}

void iniciam_com_numeros(int m1, int n ,char m[m1][n][25]){

  

    for( int i=0; i<m1; i++){
          int c2=0;
        for( int j=0; j<n; j++){
            if(m[i][j][0] >= '0' && m[i][j][0] <='9'){ //[ 4 e d u a r d o]
                                                       //[ 0 1 2 3 4 5 6 7]
                c2++;
            }
          
        }
          printf("Linha %d: %d  que iniciam com numeros\n", i, c2);
    }
 
}
void iniciam_com_vogais_letras_maiusculas(int m1, int n ,char m[m1][n][25]){
    
   

    for( int i=0; i<m1; i++){

         int c3=0;
        for( int j=0; j<n; j++){
            if( m[i][j][0] == 'A' || m[i][j][0] =='E' || m[i][j][0]=='I' || m[i][j][0]=='O' || m[i][j][0]=='U')
            c3++;
        }

        printf("Linha %d, %d iniciam com vogais maiusculas\n", i, c3);
    }

}
