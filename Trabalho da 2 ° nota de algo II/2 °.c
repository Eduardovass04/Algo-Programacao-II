#include <stdio.h>

int iniciamvogais(int m1, int n ,char m[m1][n][25]);
int iniciam_com_letra_maiusculas(int m1, int n ,char m[m1][n][25]);
int iniciam_com_numeros(int m1, int n ,char m[m1][n][25]);
int iniciam_com_vogais_letras_maiusculas(int m1, int n ,char m[m1][n][25]);

int main(){
 
    int n,m;

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

            int r1=iniciamvogais(m, n, matriz);
              printf("Total de string que iniciam %d\n", r1);
        } else if( op==2){

            int r2=iniciam_com_letra_maiusculas(m, n, matriz);
              printf("Total de strings que inciam com letras maiusculas %d\n", r2);
        } else if( op==3){
            
             int r3=iniciam_com_numeros(m, n, matriz);
             printf("Total de strings que iniciam com numeros %d\n", r3);
        } else if( op==4){

           int r4=  iniciam_com_vogais_letras_maiusculas(m, n, matriz);
             printf("Total de strings que iniciam com vogais com letras maiusculas %d\n", r4);
        } else if( op==0){

            printf("Encerrando....\n");

        } else{

            printf("Opcao invalida, tente novamente \n");
        }
    } while(op !=0 );

    return 0;

}

int iniciamvogais(int m1, int n ,char m[m1][n][25] ){

     int c=0;
    // [a][e] [i] [o] [u]...
    // a n a
    //[0] verdadeiro
    
    for( int i=0; i<m1; i++){
        for( int j=0; j<n; j++){

            if( m[i][j][0] == 'a' || m[i][j][0]=='e' || m[i][j][0]=='i'
            || m[i][j][0]=='o' || m[i][j][0]=='u' ||  m[i][j][0] == 'A' || m[i][j][0]=='E' || m[i][j][0]=='I'
            || m[i][j][0]=='O' || m[i][j][0]=='U')
            c++;
        }
    }

    return c;
}
int iniciam_com_letra_maiusculas(int m1, int n ,char m[m1][n][25]){
   int c1=0; // meu contador para strings que  iniciam com letras maiúsculas

    for( int i=0; i<m1;i++){
        for( int j=0; j<n; j++){
            if(m[i][j][0]>= 'A' && m[i][j][0] <='Z' ){ //[E d u a r d o]
                                                       //[0 1 2 3 4 5 6]
             
                c1++;
            }
        }
    }
    return c1;
}

int iniciam_com_numeros(int m1, int n ,char m[m1][n][25]){

    int c2=0;

    for( int i=0; i<m1; i++){
        for( int j=0; j<n; j++){
            if(m[i][j][0] >= '0' && m[i][j][0] <='9'){ //[ 4 e d u a r d o]
                                                       //[ 0 1 2 3 4 5 6 7]
                c2++;
            }
        }
    }
 return c2;
}
int iniciam_com_vogais_letras_maiusculas(int m1, int n ,char m[m1][n][25]){
    
    int c3=0;

    for( int i=0; i<m1; i++){
        for( int j=0; j<n; j++){
            if( m[i][j][0] == 'A' || m[i][j][0] =='E' || m[i][j][0]=='I' || m[i][j][0]=='O' || m[i][j][0]=='U')
            c3++;
        }
    }
 return c3;
}
