// acessando um campo de struct usando ponteiros

#include <stdio.h>

struct aluno{

   char nome[40]; 
   float notas[3]; 
};

void s(  struct aluno *pt);

int main(){

    struct aluno v[1];// vetor de struct criado
   struct aluno *pt=v; //criei o meu ponteiro que vai apontar pro vetor de struct

 for(int i=0; i<1; i++){
    printf("Nome:\n");
    scanf("%[^\n]", v[i].nome);
}

  for(int i=0; i<3; i++){ // 0 1 2 
    printf("Digite a sua nota:\n");
    scanf("%f", &v[0].notas[i]);
  }

    s( pt);

    return 0;
}
void s(struct aluno *pt){

    printf("Nota apontanda pelo ponteiro de struct\n");
        printf("%.1f\n", pt->notas[0]);
   
}
