#include <stdio.h>

int obter_tamanho(char *str);
void copiar_string(char *copia, char *numero);
int comparar_strings(char *atual, char *maior);
void encontrarMaior(char *N, int T, int indice, char *maior);

int main()
{
    char N[42];
    int T;

    while (1)
    {
        if (scanf("%s %d", N, &T) != 2)
        {
            break;
        }

        if (comparar_strings(N, "0") == 0 && T == 0) // condição de parada
        {
            break; //encerra
        }

        char maior[42];
        copiar_string(maior, N);

        encontrarMaior(N, T, 0, maior);

        printf("%s\n", maior); //resultado final
    }
    return 0;
}

int obter_tamanho(char *str)
{
    int tamanho = 0;
    while (*(str + tamanho) != '\0')
    {
        tamanho++;
    }
    return tamanho;
}

void copiar_string(char *copia, char *numero)
{
    int i = 0;
    while (*(numero + i) != '\0')
    {
        *(copia + i) = *(numero + i);
        i++;
    }
    *(copia + i) = '\0';
}

int comparar_strings(char *atual, char *maior)
{
    int i = 0;
    while (*(atual + i) != '\0' && *(maior + i) != '\0')
    {
        if (*(atual + i) != *(maior+ i))
        {
            return *(atual + i) - *(maior + i);
        }
        i++;
    }
    return *(atual + i) - *(maior + i);
}

void encontrarMaior(char *N, int T, int indice, char *maior)
{
    if (T == 0 || *(N + indice) == '\0')
    {

        if (comparar_strings(N, maior) > 0)
        {
            copiar_string(maior, N);
        }
        return;
    }

    int tamanho = obter_tamanho(N);
    char maior_digito = *(N + indice);

    for (int i = indice + 1; i < tamanho; i++)
    {
        if (*(N + i) > maior_digito)
        {
            maior_digito = *(N + i);
        }
    }

    if (maior_digito != *(N + indice))
    {

        for (int i = indice + 1; i < tamanho; i++)
        {
            if (*(N + i) == maior_digito)
            {
                               // troca
                char temp = *(N + indice);
                *(N + indice) = *(N + i);
                *(N + i) = temp;

                encontrarMaior(N, T - 1, indice + 1, maior);

                temp = *(N + indice);
                *(N + indice) = *(N + i);
                *(N + i) = temp;
            }
        }
    }

    encontrarMaior(N, T, indice + 1, maior);
}
