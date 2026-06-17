#include <stdio.h>

void inverter(int *in, int *fim);
void deslocarv(int *v, int n, int k);
int main()
{

    int n; // tamanho
    int k; //  2 

    printf("Digite o tamanho:\n");
    scanf("%d", &n);

    int vetor[n]; //[1 2 3 4 5]

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
void inverter(int *in, int *fim)
{
    int aux;

    while (in < fim)
    {
        aux = *in;
        *in = *fim;
        *fim = aux;

        in++;
        fim--;
    }
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
    inverter(v, v +  ( k - 1));
    inverter(v+k, v + (n - 1));

    for (int i = 0; i < n; i = i + 1)
    {

        printf("%d", *(v + i));
    }
    printf("\n");
}
