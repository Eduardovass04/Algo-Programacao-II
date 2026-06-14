// troca de elementos de vetores usando ponteiros

#include <stdio.h>

int main()
{

    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {10, 11, 12, 13, 14};

    int *ptd = a; //->1

    int *pt = b;
    int vet[5];

    for (int i = 0; i < 5; i++)
    {
        vet[i] = *(ptd + i); // aqui eu guardo os elementos do vetor a.
    }

    for (int j = 0; j < 5; j = j + 1)
    {

        a[j] = *(pt + j); // aqui  eu aloco os elementos do vetor b.
    }

    for (int k = 0; k < 5; k++)
    {

        b[k] = vet[k];
    }

    printf("vetor A apos a troca\n");

    for (int j = 0; j < 5; j++)
    {
        printf("%d\n", *(ptd + j));
    }

    printf("Vetor B apos a troca\n");

    for (int k = 0; k < 5; k++)
    {

        printf("%d\n", *(pt + k));
    }

    return 0;
}
