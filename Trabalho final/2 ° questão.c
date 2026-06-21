#include <stdio.h>

void deslocarv(int *v, int n, int k);

int main()
{
    int n;
    int k;

    printf("Digite o tamanho:\n");
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++)
    {
        printf("Elementos do vetor:\n");
        scanf("%d", &vetor[i]);
    }

    printf("Tamanho do deslocamento:\n");
    scanf("%d", &k);

    deslocarv(vetor, n, k);

    return 0;
}

void deslocarv(int *v, int n, int k)
{
    if (k > n)
    {
        k = k % n;
    }

    if (k == 0)
    {
        return;
    }

    int *in;
    int *fim;
    int aux;

    // Primeira inversão
    in = v;
    fim = v + (k - 1);

    while (in < fim)
    {
        aux = *in;
        *in = *fim;
        *fim = aux;

        in++;
        fim--;
    }

    // Segunda inversão 
    in = v + k;
    fim = v + (n - 1);

    while (in < fim)
    {
        aux = *in;
        *in = *fim;
        *fim = aux;

        in++;
        fim--;
    }

    printf("Saida:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(v + i));
    }

    printf("\n");
}
