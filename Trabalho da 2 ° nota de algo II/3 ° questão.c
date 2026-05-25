#include <stdio.h>
#include <string.h>
#define Max 100

struct estudante{

     char ultimonome[20];
     char primeironome[20];
     float rendimentoacademico;

};

struct funcionarios {

 char ultimonome[50];
 char primeironome[50];
 float salario;
};

void cadastrar_estudantes(int t, struct estudante alu[] );
void cadastrar_funcionarios(int t, struct funcionarios trabalhadores[]);
void mostrar_todos_os_estudantes(int t, struct estudante alu[]);
void mostra_todos_os_funcionarios(int t, struct funcionarios trabalhadores[]);
void mostrar_os_dados_de_um_estudante(int t, struct estudante alu[]);
void mostrar_os_dados_de_um_funcionario( int t, struct funcionarios trabalhadores[]);

int main(){
    
     struct estudante alu[Max];
     int qtd_estudante=0;
     
     struct funcionarios trabalhadores[Max];
     int qtd_funcionarios=0;
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
        if(qtd_estudante >= Max){
            printf("ERRO! Limite atingido!\n");
        }else
        {
            cadastrar_estudantes(qtd_estudante, alu);
            qtd_estudante++;
        }
       
    } else if(opc==2){
        if(qtd_funcionarios >= Max){
            printf("ERRO! Limite atingido!");
        }else
        {
            cadastrar_funcionarios(qtd_funcionarios, trabalhadores);
            qtd_funcionarios++;
        }
       
    } else if(opc==3){
        mostrar_todos_os_estudantes(qtd_estudante, alu);
       
    } else if(opc==4){
        mostra_todos_os_funcionarios(qtd_funcionarios, trabalhadores);

    } else if(opc==5){
        mostrar_os_dados_de_um_estudante(qtd_estudante, alu);
      
    } else if(opc==6){
        mostrar_os_dados_de_um_funcionario(qtd_funcionarios, trabalhadores);
      
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

    do{

    repete=0;

        printf("Digite o seu primeiro nome:\n");
    scanf(" %[^\n]", alu[t].primeironome);

    printf("Digite o seu ultimo nome:\n");
    scanf(" %[^\n]", alu[t].ultimonome);
    
    printf("Digite o seu rendimento academico:\n");
    scanf(" %f", &alu[t].rendimentoacademico);

    for( int j=0; j<t; j++){

        if(strcmp(alu[t].primeironome, alu[j].primeironome)==0 &&

        strcmp(alu[t].ultimonome, alu[j].ultimonome)==0){

            repete=1;

            printf(" Aluno ja esta cadastrado \n");
        }
    }
    } while(repete);

}

void cadastrar_funcionarios(int t, struct funcionarios trabalhadores[]){

     int repete2;       

        do{

             repete2=0;

              printf("Digite o seu primeiro nome:\n");
        scanf(" %[^\n]", trabalhadores[t].primeironome);
        
        printf("Digite o seu ultimo nome:\n");
        scanf(" %[^\n]", trabalhadores[t].ultimonome);


        printf("Digite o seu salario:\n");
        scanf(" %f", &trabalhadores[t].salario);

        for( int j=0; j<t; j++){
            if(strcmp(trabalhadores[t].primeironome, trabalhadores[j].primeironome)==0
        && strcmp(trabalhadores[t].ultimonome, trabalhadores[j].ultimonome)==0){

            repete2=1;
        
        printf(" Funcionario ja esta cadastrado\n");
    }
        }
    }while(repete2);
}

void mostrar_todos_os_estudantes(int t, struct estudante alu[]){

    for( int i=0; i<t; i++){

        printf("Estudante %d\n", i+1);

         printf("Primeiro nome: %s\n", alu[i].primeironome);
        printf("Ultimo Nome: %s\n", alu[i].ultimonome );
        printf("Rendimento academico %.2f\n", alu[i].rendimentoacademico);

       
    }
}

void mostra_todos_os_funcionarios(int t, struct funcionarios trabalhadores[]){

    for( int i=0; i<t; i++){

        printf("Funcionario %d\n", i+1);
         printf("Primeiro nome: %s\n", trabalhadores[i].primeironome);
        printf("Ultimo Nome: %s\n", trabalhadores[i].ultimonome);
        printf("Salario %.2f\n", trabalhadores[i].salario);
       
    }
}


 void mostrar_os_dados_de_um_estudante(int t, struct estudante alu[]){

    int escolher;

    printf("Digite a posicao do estudante que deseja ver\n");
    scanf("%d", &escolher);

    

        if( escolher >=0 && escolher < t){

            printf(" DADOS DO ESTUDANTE \n");

             printf("Primeiro nome %s\n", alu[escolher].primeironome);

            printf("Ultimo nome %s\n", alu[escolher].ultimonome);

            printf("Rendimento academico %.2f\n", alu[escolher].rendimentoacademico);
        } else{
            printf(" Posicao indisponivel\n");
        }

 }

 void mostrar_os_dados_de_um_funcionario( int t, struct funcionarios trabalhadores[]){

    int escolher2;

    printf("Digite a posicao do funcionario que deseja ver:\n");
    scanf("%d", &escolher2);

    

        if( escolher2 >=0 && escolher2 <t){

        printf("DADOS DO FUNCIONARIO \n");
        
        printf("Primeiro nome %s\n", trabalhadores[escolher2].primeironome);

        printf("Ultimo nome %s\n", trabalhadores[escolher2].ultimonome);


        printf("Salario %.2f\n", trabalhadores[escolher2].salario);

          } else{
            printf(" Posicao indisponivel\n");
          }
   
 }
