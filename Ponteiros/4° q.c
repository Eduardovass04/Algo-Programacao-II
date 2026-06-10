#include <stdio.h>

int contarPalavras(char *str);

int main(){

    char n[30];


    printf("Digite a string\n");
    scanf(" %[^\n]", n);

     char *p=n;

    int r= contarPalavras(p);

    printf(" %d palavras\n", r);

    return 0;
}

int contarPalavras(char *str){

    int i=0; int c=0;

   

    while( *(str + i) != '\0'){

        if( *(str + i) != ' ' &&( i==0 || *(str+i-1)== ' ')){
            c++;
        }
        i++;
    }

    return c;
}
