#include <stdio.h>

int tamanhoCollatz(long long n, FILE *arq) {
    int passos = 1;
    while (n != 1) {
        if (arq != NULL) {
            fprintf(arq, "%lld->", n);
        }
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        passos++;
    }
    if (arq != NULL) {
        fprintf(arq, "1\n");
    }
    return passos;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;
    }

    FILE *arq = fopen("collatz.txt", "w");
    if (arq == NULL) {
        return 1;
    }

    fprintf(arq, "Todas as cadeias de Collatz ---\n");

    int num_maior_cadeia = 1;
    int tamanho_maior_cadeia = 1;

    for (int i = 1; i <= N; i++) {
        fprintf(arq, "%d: ", i);
        int atual_tamanho = tamanhoCollatz(i, arq);
        if (atual_tamanho > tamanho_maior_cadeia) {
            tamanho_maior_cadeia = atual_tamanho;
            num_maior_cadeia = i;
        }
    }

    fclose(arq);

    printf("Num_maior_cadeia = %d\n", num_maior_cadeia);
    printf("Tamanho_maior_cadeia = %d\n", tamanho_maior_cadeia);

    return 0;
}
