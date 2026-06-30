#include <stdio.h>

void deslocarv(int *v, int n, int k);
// dentro do protótipo da função eu passei um ponteiro do tipo inteiro
// que vai receber o primeiro elemento do meu vetor

int main()
{
    int n; //tamanho do meu vetor
    int k; // k deslocamentos informados pelo usuário

    printf("Digite o tamanho do vetor e o deslocamento:\n");
    scanf("%d %d", &n, &k);

    int vetor[n]; //criei o meu vetor 
    

    for (int i = 0; i < n; i++)
    {
        printf("Elementos do vetor:\n");
        scanf("%d", &vetor[i]);
    }

    deslocarv(vetor, n, k); //passei o meu vetor na chamada da função
    // é como se eu passase o endereço do primeiro elemento deele
    // &v[0], passei também o tamanho do vetor é k deslocamentos

    return 0;
}

void deslocarv(int *v, int n, int k)
{
    // v guarda o inicio do meu vetor
    if (k > n)//fiz uma verificação caso o meu deslocamento seja maior que o tamanho do meu vetor
    {
        k = k % n; 
    }

    if (k == 0)
    {
        return; // k ==0 return é encerra
    }

    int *in; // ponteiro para o inicio
    int *fim; 
    int aux; 

    // Primeira inversão
    in = v; //in recebe o endereço da primeira posição do meu vetor, apontando para posição [0]
    fim = v + (k - 1);

    while (in < fim)//compara usando o endereço de memória
    {
        aux = *in;// por meio da desrreferenciação eu faço a troca dos elementos *
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
