#include <stdio.h>

int tamanhoCollatz(unsigned long long n, FILE *arq);// n do tipo unsigned long long que guarda valores inteiros muito grandes
   // também tenho o meu ponteiro do tipo arquivo
   //File representa umm arquivo aberto dentro do sistema
int main() {
    int N;

    ////Resumindo File *arq  é  como se eu emprestasse  o meu arquivo aberto pra dentro da função
    //ela que vai receber o arquivo aberto.

    printf("Digite um numero positivo: ");

    if (scanf("%d", &N) != 1) { // Usuário digita "abc"    → scanf retorna 0 → 0 != 1 é VERDADEIRO → entra no if → return 1 (encerra)
        return 1;
    }
 // no meu código o arquivo é aberto dentro da main
    FILE *arq = fopen("collatz.txt", "w"); //*arq ponteiro para arquivo, File vai abrir a variável
    if (arq == NULL) { //caso falhe ao abrir o arquivo , imprimindo a mensagem
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
      
    fprintf(arq, "Todas as cadeias de Collatz ---\n");
   
     
    int num_maior_cadeia = 1; //armazena o numero com a maior cadeia encontrada
    int tamanho_maior_cadeia = 1; //armazena o tamanho da maior cadeia encontrada

    for (int i = 1; i <= N; i++) {
        fprintf(arq, "%d: ", i); // printa no arquivo o numero atual, seguido dos :

        int tamanho_atual = tamanhoCollatz((unsigned long long)i, arq);//passo o ponteiro para a função, ele usara o arquivo aberto passando as sequências dentro dele

         //atualiza a maior cadeia encontrada
        if (tamanho_atual > tamanho_maior_cadeia) {
            tamanho_maior_cadeia = tamanho_atual;
            num_maior_cadeia = i;
        }
    }

    fclose(arq); // fecha o arquivo depois do fim do loop

    printf("Numero maior da cadeia = %d\n", num_maior_cadeia);
    printf("Tamanho maior cadeia = %d\n", tamanho_maior_cadeia);

    return 0;
}

int tamanhoCollatz(unsigned long long n, FILE *arq) { //usado quando preciso armazenar números muito grandes inteiros sem ser negativos
    int tamanho = 1;//começa em 1 porque o proprio numero de inicio já conta como primeiro elemento da cadeia

    while (n != 1) {
       
        fprintf(arq, "%llu->", n);

        if (n % 2 == 0) { //regra de collatz, aplica a regra de Collatz: se n é par, divide por 2; se é ímpar, multiplica por 3 e soma 1
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        tamanho++;//conto mais um passo na cadeia
    }

    fprintf(arq, "1\n"); //saindo do while n vale 1, escrevendo 1 no final do arquivo e retorna o tamanho total da cadeia
    return tamanho;
}
