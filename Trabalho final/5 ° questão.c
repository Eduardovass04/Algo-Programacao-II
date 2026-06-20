#include <stdio.h>

// Protótipo 
int tamanhoCollatz(long long n, FILE *arq);

int main() {

    int N;

    printf("Digite um numero positivo: ");
    scanf("%d", &N);

    FILE *arq = fopen("collatz.txt", "w");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arq, "Todas as cadeias de Collatz\n\n");

    int num_maior_cadeia = 1;
    int tamanho_maior_cadeia = 1;

    for (int i = 1; i <= N; i++) {

        fprintf(arq, "%d: ", i);

        int tamanho_atual = tamanhoCollatz(i, arq);

        if (tamanho_atual > tamanho_maior_cadeia) {
            tamanho_maior_cadeia = tamanho_atual;
            num_maior_cadeia = i;
        }
    }

    fclose(arq);

    printf("\nNum_maior_cadeia = %d\n", num_maior_cadeia);
    printf("Tamanho_maior_cadeia = %d\n", tamanho_maior_cadeia);

    return 0;
}

// Implementação 
int tamanhoCollatz(long long n, FILE *arq) {

    int tamanho = 1;

    
    while (n != 1) {
   fprintf(arq, "%d -> ", (int)n);

        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = 3 * n + 1;
        }

        tamanho++;
    }

    fprintf(arq, "1\n");

    return tamanho;
}
