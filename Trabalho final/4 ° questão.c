#include <stdio.h>

int obter_tamanho(char *str);
void copiar_string(char *destino, char *origem);
int comparar_strings(char *str1, char *str2);
void encontrarMaior(char *N, int T, int index, char *maior);

int main()
{
    char N[42];
    int T;

    printf("==================================================\n");
    printf("         MAIOR NUMERO COM ATE T TROCAS            \n");
    printf("==================================================\n");

    while (1)
    {

        printf("Digite o numero N e a quantidade de trocas T:\n");
        printf("Digite 0 Para encerrar o programa:\n");
        printf("Entrada: ");

        if (scanf("%s %d", N, &T) != 2)
        {
            break;
        }

        if (comparar_strings(N, "0") == 0 && T == 0)
        {
            printf(" Programa encerrado\n");
            break;
        }

        char maior[42];
        copiar_string(maior, N);

        encontrarMaior(N, T, 0, maior);

        printf("Saída: %s\n", maior);
        printf("--------------------------------------------------\n");
    }

    return 0;
}

int obter_tamanho(char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
    {
        len++;
    }
    return len;
}

void copiar_string(char *destino, char *origem)
{
    int i = 0;
    while (*(origem + i) != '\0')
    {
        *(destino + i) = *(origem + i);
        i++;
    }
    *(destino + i) = '\0';
}

int comparar_strings(char *str1, char *str2)
{
    int i = 0;
    while (*(str1 + i) != '\0' && *(str2 + i) != '\0')
    {
        if (*(str1 + i) != *(str2 + i))
        {
            return *(str1 + i) - *(str2 + i);
        }
        i++;
    }
    return *(str1 + i) - *(str2 + i);
}

void encontrarMaior(char *N, int T, int index, char *maior)
{
    if (T == 0 || *(N + index) == '\0')
    {

        if (comparar_strings(N, maior) > 0)
        {
            copiar_string(maior, N);
        }
        return;
    }

    int len = obter_tamanho(N);
    char maior_digito = *(N + index);

    for (int i = index + 1; i < len; i++)
    {
        if (*(N + i) > maior_digito)
        {
            maior_digito = *(N + i);
        }
    }

    if (maior_digito != *(N + index))
    {

        for (int i = index + 1; i < len; i++)
        {
            if (*(N + i) == maior_digito)
            {

                char temp = *(N + index);
                *(N + index) = *(N + i);
                *(N + i) = temp;

                encontrarMaior(N, T - 1, index + 1, maior);

                temp = *(N + index);
                *(N + index) = *(N + i);
                *(N + i) = temp;
            }
        }
    }

    encontrarMaior(N, T, index + 1, maior);
}
