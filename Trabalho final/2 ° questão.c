#include <stdio.h>

void deslocarv(int *v, int n, int k);

int main()
{
    int n; //tamanho do meu vetor
    int k; // k deslocamentos

    printf("Digite o tamanho do vetor e o deslocamento:\n");
    scanf("%d %d", &n, &k);

    int vetor[n]; //vetor criado
    //[1 2 3 4 5]

    for (int i = 0; i < n; i++)
    {
        printf("Elementos do vetor:\n");
        scanf("%d", &vetor[i]);
    }

    deslocarv(vetor, n, k); //&vetor[0]

    return 0;
}

void deslocarv(int *v, int n, int k)
{
    // v guarda o inicio do meu vetor
    if (k > n)
    {
        k = k % n; 
    }

    if (k == 0)
    {
        return; // k ==0 return
    }

    int *in; // ponteiro para o inicio
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
