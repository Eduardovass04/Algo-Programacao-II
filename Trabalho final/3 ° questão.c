#include <stdio.h>

void casamento(int a, int b, int *rea, int *resb);

int main()
{
    int a;
    int b;
    int resuB;
    int resuA;

    printf("Digite o valor de a e b:\n");
    scanf("%d %d", &a, &b);

    casamento(a, b, &resuA, &resuB);

    printf("Saida\n");

    if (resuA <= resuB)
    {
        printf("%d %d\n", resuA, resuB); //imprimi em ordem crescente
    }
    else
    {
        printf("%d %d\n", resuB, resuA); //imprimi em ordem crescente
    }

    return 0;
}

void casamento(int a, int b, int *rea, int *resb)
{
    int resultadoA = 0;
    int resultadoB = 0;
    int pesoa = 1;
    int pesob = 1;
    int digitoa = 0;
    int digitob = 0;
    int qtdDigitosa = 0;
    int qtdDigitosb = 0;

    while (a > 0 || b > 0) //percorre os ns da direita para a esquerda
    {
        digitoa = a % 10;
        digitob = b % 10;

        if (digitoa > digitob)
        {
            resultadoA  = resultadoA  + (digitoa * pesoa);
            pesoa = pesoa * 10;
           qtdDigitosa++;
        }
        else if (digitob > digitoa)
        {
            resultadoB = resultadoB + (digitob * pesob);
            pesob = pesob * 10;
            qtdDigitosa++;
        }
        else if (digitoa == digitob)
        {
            resultadoA = resultadoA  + (digitoa * pesoa);
            pesoa = pesoa * 10;
            
           resultadoB =resultadoB + (digitob * pesob);
            pesob = pesob * 10;
            
           qtdDigitosa++;
         qtdDigitosb++;
            
        }

        a = a / 10;
        b = b / 10;
    }

    if (qtdDigitosa == 0)
    {
        resultadoA = -1;
    }
     
    if ( qtdDigitosb == 0)
    {
        resultadoB = -1;
    }

    *rea = resultadoA ;
    *resb = resultadoB;
}
