#include <stdio.h>

void ordenaPonteiros(int **vPtr, int n);

int main()
{

    // O o código faz ?: lê um vetor de inteiros cria um vetor de ponteiros
    // apontando para cada elemento, logo eu ordeno os endereços 
    int n;
    printf("Tamanho do vetor:\n");
    scanf("%d", &n);

    int v[n]; //[{50, 10, 30, 20, 40}] t=5 //guarda os valores inteiros

    for (int i = 0; i < n; i = i + 1)
    {
        printf("Digite os elementos do vetor\n");
        scanf("%d", &v[i]);
    }

    int *vp[n]; //vetor de ponteiros que guardará cada endereço

    for(int i=0; i<n; i++){
      vp[i]=&v[i]; //pegando os endereços, *vp guarda os endereços de cada elemento do vetor de inteiros
    }
    
        ordenaPonteiros(vp, n);

    return 0;
}
void ordenaPonteiros(int **vPtr, int n) //vPtr é o meu ponteiro para o primeiro elemento de Vp
{ //** vPtr recebe o endereço da primeira posição de vp

    int *aux; // ponteiro q vai guardar o endereço temporariamente durante a troca

    for (int i = 0; i < n - 1; i++)
    { // 0 < 3, 1 < 2[0 1 ]

        for (int j = i + 1; j < n; j++)
        {

            if (**(vPtr + i) > **(vPtr + j)) //aqui eu comparo qual o elemento maior [50 10 30...]
            {
                aux = *(vPtr + i);
                *(vPtr + i) = *(vPtr + j);
                *(vPtr + j) = aux;
            }
        }
    }

   printf("Saida:\n");
    
    for(int i=0; i<n; i++){
        if (i == n - 1) {
            printf("vPtr[%d]->%d\n", i, **(vPtr+i));
        } else {
            printf("vPtr[%d]->%d, ", i, **(vPtr+i));
        }
    }
}
