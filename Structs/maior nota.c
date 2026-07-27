// notas de 5 alunos
#include <stdio.h>

struct notas
{

    char nome[100];
    float notas;
};

struct notas maior_nota(struct notas a1[], int t){
  
     int maior_notas=0;

    for( int i=0; i<t; i++){
        if(a1[i].notas> a1[maior_notas].notas){
            maior_notas=i;
        }
    }
     return a1[maior_notas];
 }

int main()
{

    struct notas a[5];

    for (int i = 0; i < 5; i++)
    {

        printf("INSERIR NOME:\n");
        scanf(" %[^\n]", a[i].nome);

        printf("INSERIR NOTA:\n");
        scanf(" %f", &a[i].notas);
    }

    // exibindo

    printf("ALUNOS E NOTAS:\n");

    for (int i = 0; i < 5; i++)
    {

        printf("Aluno: %s -> Nota: %f\n", a[i].nome, a[i].notas);

    }

    struct notas aluno = maior_nota(a, 5); // passando o endereço do primeiro elemento do meu vetor de struct

    printf("NOTA MAIOR:\n");

    printf("Nome: %s -> nota: %.2f\n", aluno.nome, aluno.notas);

    return 0;
}
 
