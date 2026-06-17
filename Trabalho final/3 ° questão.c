#include <stdio.h>

void casamento(int a, int b, int *rea, int *resb);

int main()
{
    int a;
    int b;
    int resuB;
    int resuA;

    printf("Digite o valor de a:\n");
    scanf("%d", &a);

    printf("Digite o valor de b:\n");
    scanf("%d", &b);

    casamento(a, b, &resuA, &resuB);

    if (resuA <= resuB)
    {
        printf("%d %d\n", resuA, resuB);
    }
    else
    {
        printf("%d %d\n", resuB, resuA);
    }

    return 0;
}

void casamento(int a, int b, int *rea, int *resb)
{
    int inia = 0;
    int inib = 0;
    int pesoa = 1;
    int pesob = 1;
    int digitoa = 0;
    int digitob = 0;
    int conta = 0;
    int contb = 0;

    while (a > 0 || b > 0)
    {
        digitoa = a % 10;
        digitob = b % 10;

        if (digitoa > digitob)
        {
            inia = inia + (digitoa * pesoa);
            pesoa = pesoa * 10;
            conta++;
        }
        else if (digitob > digitoa)
        {
            inib = inib + (digitob * pesob);
            pesob = pesob * 10;
            contb++;
        }
        else if (digitoa == digitob)
        {
            inia = inia + (digitoa * pesoa);
            pesoa = pesoa * 10;
            
            inib = inib + (digitob * pesob);
            pesob = pesob * 10;
            
            conta++;
            contb++;
        }

        a = a / 10;
        b = b / 10;
    }

    if (conta == 0)
    {
        inia = -1;
    }
    if (contb == 0)
    {
        inib = -1;
    }

    *rea = inia;
    *resb = inib;
}
