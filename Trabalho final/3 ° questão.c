#include <stdio.h>

void casamento(int a, int b, int *rea, int *resb);
//passando dois valores inteiros(a e b)
//é dois ponteiros, resultado A é resultado B
int main()
{
    int a;
    int b;
    int resuB;//recebe  o resultado de b lá da função para imprimir na main
    int resuA;// recebe o resultado de a lá da função para imprimir na main

    printf("Digite o valor de a e b:\n");
    scanf("%d %d", &a, &b);

    casamento(a, b, &resuA, &resuB);
    //passei a e b como valores ou seja, mandei uma cópia dos seus valores pra função
    // já os resultados(a e b), passei os seus endereços

    printf("Saida\n");

    if (resuA <= resuB)// se o valor final de a for menor que o de b, então já está em ordem crescente
    {
        printf("%d %d\n", resuA, resuB); //imprimi em ordem crescente
    }
    else
    {
        printf("%d %d\n", resuB, resuA); //imprimi em ordem crescente
    }// se não, se resuA for maior, então é impresso o resultadoB primeiro em seguida o de A

    return 0;
}

void casamento(int a, int b, int *rea, int *resb)
{
    //*resa é *resb são ponteiros que estão apontando
    // para reuA é resuB lá da main

    int resultadoA = 0; //guarda meus números que sobrarem no cálculo
    int resultadoB = 0;
    int pesoa = 1; // recebe o digito que sobra, múltiplica começa com 1 é * por 10, pula pra unidade, depois por 100(centenas)
    int pesob = 1;
    int digitoa = 0; // guardara temporariamente o digito isolado(2, do 52)
    int digitob = 0;// guardara temporariamente o digito isolado
    int qtdDigitosa = 0;
    int qtdDigitosb = 0;

    // enquanto a ou b tiverem digitos ele percorre
    while (a > 0 || b > 0) //percorre os ns da direita para a esquerda, só para quando os dois virarem 0
    {
        digitoa = a % 10;//pego o resto da divisão por 10, isolando o último digito da direita (isola)
        digitob = b % 10;//pego o resto da divisão por 10, isolando o último digito da direita (isola)

        if (digitoa > digitob)
        {
            resultadoA  = resultadoA  + (digitoa * pesoa);
            pesoa = pesoa * 10; //avanço uma casa decimal 
           qtdDigitosa++; //contandor do digito a aumenta
        }
        else if (digitob > digitoa)
        {
            resultadoB = resultadoB + (digitob * pesob);
            pesob = pesob * 10; //avança uma casa decimal
            qtdDigitosb++; //contandor do digito b aumenta
        }
        else if (digitoa == digitob) // se os dois forem iguais os dois ganham o digito( para a é b)
        {
            resultadoA = resultadoA  + (digitoa * pesoa);
            pesoa = pesoa * 10;
            
           resultadoB =resultadoB + (digitob * pesob);
            pesob = pesob * 10;
            
           qtdDigitosa++;
         qtdDigitosb++;
            
        }

        a = a / 10; // exclui o último digito
        b = b / 10;
    } //fim do while

    if (qtdDigitosa == 0)//verificação da saida, caso o meu contando tiver 0
    {                   //significa que meu digito a não recebeu digito 
        resultadoA = -1;// recebe -1 como a regra da questão diz
    }
     
    if ( qtdDigitosb == 0)//verificação da saida, caso o meu contando tiver 0
    {                     //significa que meu digito a não recebeu digito
        resultadoB = -1;  // recebe -1 como a regra da questão diz
    }

    *rea = resultadoA ; //desreferenciação, acessando o endereço do resultado da main é mando o novo valor final pra lá
    *resb = resultadoB; 
}
