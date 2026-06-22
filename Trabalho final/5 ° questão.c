#include <stdio.h>

int tamanhoCollatz(unsigned long long n, FILE *arq);

int main() {
    int N;

    printf("Digite um numero positivo: ");

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    FILE *arq = fopen("collatz.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arq, "Todas as cadeias de Collatz ---\n");

    int num_maior_cadeia = 1; //armazena o numero com a maior cadeia encontrada
    int tamanho_maior_cadeia = 1; //armazena o tamanho da maior cadeia encontrada

    for (int i = 1; i <= N; i++) {
        fprintf(arq, "%d: ", i);

        int tamanho_atual = tamanhoCollatz((unsigned long long)i, arq);

         //atualiza a maior cadeia encontrada
        if (tamanho_atual > tamanho_maior_cadeia) {
            tamanho_maior_cadeia = tamanho_atual;
            num_maior_cadeia = i;
        }
    }

    fclose(arq);

    printf("Numero maior da cadeia = %d\n", num_maior_cadeia);
    printf("Tamanho maior cadeia = %d\n", tamanho_maior_cadeia);

    return 0;
}

int tamanhoCollatz(unsigned long long n, FILE *arq) {
    int tamanho = 1;

    while (n != 1) {
       
        fprintf(arq, "%llu->", n);

        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        tamanho++;
    }

    fprintf(arq, "1\n");
    return tamanho;
}
