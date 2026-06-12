#include <stdio.h>

struct trabalhador{

    char nome[60];
    int idade;
    float salario;
    int horast;
};

void ba( struct trabalhador *ptr);

int main(){

    struct trabalhador a[3];

    for(int i=0; i<3; i++){

        printf("Nome:\n");
        scanf(" %[^\n]", a[i].nome);

        printf("Idade:\n");
        scanf("%d", &a[i].idade);

        printf("Salario:\n");
        scanf("%f", &a[i].salario);

        printf("Horas:\n");
        scanf("%d", &a[i].horast);
    }

    ba(&a[2]);

    return 0;
}

void ba( struct trabalhador *ptr){

    printf("acessando\n");

    printf("%s\n", ptr->nome);
    printf("%d\n", ptr->idade);
    printf("%f\n", ptr->salario);
    printf("%d\n", ptr->horast);
}
