#include <stdio.h>
#include <string.h>

struct estudante{

     char ultimonome[20];
     char primeironome[20];
     float rendimentoacademico;

};

struct funcionarios {

 char ultimonome[20];
 char primeironome[20];
 float salario;
};

void cadastrar_estudantes(int t, struct estudante alu[] );
void cadastrar_funcionarios(int t, struct funcionarios trabalhadores[]);
void mostrar_todos_os_estudantes(int t, struct estudante alu[]);
void mostra_todos_os_funcionarios(int t, struct funcionarios trabalhadores[]);
void mostrar_os_dados_de_um_estudante(int t, struct estudante alu[]);
void mostrar_os_dados_de_um_funcionario( int t, struct funcionarios trabalhadores[]);

int main(){

     struct estudante alu[2];
     
     struct funcionarios trabalhadores[2];
   int opc;

   do{

    printf("Escolha uma opcao:\n");
    printf("1-Cadastrar estudante:\n");
    printf("2-cadastrar funcionario:\n");
    printf("3-Mostrar todos os estudantes:\n");
    printf("4-Mostrar todos os funcionarios:\n");
    printf("5-Mostrar os dados de um estudante:\n");
    printf("6-Mostrar os dados de um funcionario:\n");
    printf("0- para sair\n");
    scanf("%d", &opc);

    if(opc==1){
        cadastrar_estudantes( 3,alu);
       
    } else if(opc==2){
        cadastrar_funcionarios(3, trabalhadores);
       
    } else if(opc==3){
        mostrar_todos_os_estudantes(3, alu);
       
    } else if(opc==4){
        mostra_todos_os_funcionarios(3, trabalhadores);

    } else if(opc==5){
        mostrar_os_dados_de_um_estudante(3, alu);
      
    } else if(opc==6){
        mostrar_os_dados_de_um_funcionario(3, trabalhadores);
      
    } else if(opc==0){
        printf("Encerrando programa..\n");
    } else{
        printf("Opcao invalida, tente novamente\n");
    }
   } while( opc != 0);

   return 0;

}

void cadastrar_estudantes(int t, struct estudante alu[] ){

     int repete;

    

    for( int i=0; i<t; i++){

        do{

       repete=0;

          printf("Digite o seu primeiro nome:\n");
        scanf(" %s", alu[i].primeironome);

        printf("Digite o seu ultimo nome:\n");
        scanf(" %s", alu[i].ultimonome);
     
        printf("Digite o seu rendimento academico:\n");
        scanf(" %f", &alu[i].rendimentoacademico);

        for( int j=0; j<i; j++){

            if(strcmp(alu[i].primeironome, alu[j].primeironome)==0 &&

            strcmp(alu[i].ultimonome, alu[j].ultimonome)==0){

                repete=1;

                printf(" Aluno ja esta cadastrado \n");
            }
        }
    } while(repete);

    }
}

void cadastrar_funcionarios(int t, struct funcionarios trabalhadores[]){

     int repete2;

    for( int i=0; i<t; i++){

        repete2=0;

        do{

              printf("Digite o seu primeiro nome:\n");
        scanf(" %s", trabalhadores[i].primeironome);
        
        printf("Digite o seu ultimo nome:\n");
        scanf(" %s", trabalhadores[i].ultimonome);


        printf("Digite o seu salario:\n");
        scanf(" %f", &trabalhadores[i].salario);

        for( int j=0; j<i; j++){
            if(strcmp(trabalhadores[i].primeironome, trabalhadores[j].primeironome)==0
        && strcmp(trabalhadores[i].ultimonome, trabalhadores[j].ultimonome)==0){

            repete2=1;
        
        printf(" Funcionario ja esta cadastrado\n");
    }
        }
    }while(repete2);

    }
}

void mostrar_todos_os_estudantes(int t, struct estudante alu[]){

    for( int i=0; i<t; i++){

        printf("Estudante %d\n", i+1);

         printf("Primeiro nome: %s\n", alu[i].primeironome);
        printf("Ultimo Nome: %s\n", alu[i].ultimonome );

       
    }
}

void mostra_todos_os_funcionarios(int t, struct funcionarios trabalhadores[]){

    for( int i=0; i<t; i++){

        printf("Funcionario %d\n", i+1);
         printf("Primeiro nome: %s\n", trabalhadores[i].primeironome);
        printf("Ultimo Nome: %s\n", trabalhadores[i].ultimonome);
       
    }
}


 void mostrar_os_dados_de_um_estudante(int t, struct estudante alu[]){

    int escolher;

    printf("Digite a posicao do estudante que deseja ver\n");
    scanf("%d", &escolher);

    do{

        if( escolher >=0 && escolher < t){

            printf(" DADOS DO ESTUDANTE \n");

             printf("Primeiro nome %s\n", alu[escolher].primeironome);

            printf("Ultimo nome %s\n", alu[escolher].ultimonome);

            printf("rendimento academico %.2f\n", alu[escolher].rendimentoacademico);
        } else{
            printf(" Posicao indisponivel\n");
        }
    } while( escolher <0);

 }

 void mostrar_os_dados_de_um_funcionario( int t, struct funcionarios trabalhadores[]){

    int escolher2;

    printf("Digite a posicao do funcionario que deseja ver:\n");
    scanf("%d", &escolher2);

    do{

        if( escolher2 >=0 && escolher2 <t){

        printf("DADOS DO FUNCIONARIO \n");
        
        printf("Primeiro nome %s\n", trabalhadores[escolher2].primeironome);

        printf("Ultimo nome %s\n", trabalhadores[escolher2].ultimonome);


        printf("salario %.2f\n", trabalhadores[escolher2].salario);

          } else{
            printf(" Posicao indisponivel\n");
          }
    } while(escolher2<0);
 }
