#include <stdio.h>

int obter_tamanho(char *str); // ponteiro para caractere que aponta pro inico da string é retorna um valor inteiro
void copiar_string(char *copia, char *numero); // copia do meu vetor 'maior' //copia recebe o meu vetor Maior é numero recebe o meu vetor N
int comparar_strings(char *atual, char *maior); // passando dois ponteiros, atual é maior pra retornar um valor inteiro para comparar 
void encontrarMaior(char *N, int T, int indice, char *maior); //função recursiva
// *N recebe o numero original da string. T trocas permitidas. Indice posição do dígito atual, *maior será a string
int main()
{
    char N[42];//usei char n[42] porque o enunciado
              // diz que o número n pode chegar até 40 digitos
              // nem se eu usasse o tipo long long conseguiria armazenar sem estourar a memoria
              // tratando o vetor como o string o usuario pode digitar qualquer número entre 1 e 40 digitos
              //facilita também porque na leitura o scanf coloca o /0 no final
    int T;

    while (1) //criei um laço infinito para que o programa rode vários testes
    {   //uso o if para encerrar o laço infinito, caso o scanf não retornar os 2 valores lidos
        // o programa encerra no break.

        if (scanf("%s %d", N, &T) != 2)
        {//como n foi guardado como um texto, é obrigatorio comparar caractere por caractere
            break;
        }

        if (comparar_strings(N, "0") == 0 && T == 0) // condição de parada que o professor pediu, para 'N' eu chamo a função comparar_string
        {                                            // Se o usuario digitar T de trocas 0 também dá verdadeiro
            break; //encerra
        }

        char maior[42]; // criei outro vetor com o mesmo tamanho, vai ser usado dentro da recursão para 
                        // pegar o maior numero que for gerado

        copiar_string(maior, N);//passando a função, onde eu vou passar o conteúdo de N
                               // pro vetor maior[42].

        encontrarMaior(N, T, 0, maior);//função principal do meu programa

        printf("%s\n", maior); //resultado final
    }
    return 0;
}

int obter_tamanho(char *str)
{ //ponteiro char que aponta pro primeiro elemento do vetor de string 

    int tamanho = 0;// tamanho, vai guardar o tamanho em forma de inteiro
    while (*(str + tamanho) != '\0')//roda até for diferente de \0   //[1 2 3 4]
    {
        tamanho++; //pegando o comprimento da string em o /0, incrementando é o ponteiro apontando pro proximo
    }
    return tamanho;
}

void copiar_string(char *copia, char *numero) //[ 1 2 3 4]
{
    int i = 0;
    //roda a string original 
    while (*(numero + i) != '\0')
    {
        *(copia + i) = *(numero + i);//copia recebe o numero localizado naquele endereço
        i++;// i vai sendo incrementado
    }
    *(copia + i) = '\0';// fechando o laço no \0
}//vetor maior agora recebe[1 2 3 4]

int comparar_strings(char *atual, char *maior)
{
    int i = 0;
    while (*(atual + i) != '\0' && *(maior + i) != '\0')//roda enquanto nenhuma delas chega em \0, separados do operado E
    {
        if (*(atual + i) != *(maior+ i))//verifica se os numeros são diferentes(caracteres)
        {
            return *(atual + i) - *(maior + i);
        }
        i++;
    }
    return *(atual + i) - *(maior + i);
}

void encontrarMaior(char *N, int T, int indice, char *maior)
{//função recursiva
    //n string que vai ser modificada
    //T trocasmque restaram
    //indice e a posição do numero atual(caractere)
    //maior é o ponteiro
    if (T == 0 || *(N + indice) == '\0') //entra na recursão se pelo menos uma dels for verdade
    { //*(N+indice) percorre enquanto eu não chegar no \0
          //quando as trocas acabarem então entra no if
        if (comparar_strings(N, maior) > 0)// exemplo de troca( N=65, maior=56 > 0)
        {
            copiar_string(maior, N); //atualiza o novo maior para 65
        }
        return;
    }

    int tamanho = obter_tamanho(N);// tamanho 4
    char maior_digito = *(N + indice); // assumindo que o primeiro elemento da posição do vetor é o maior

    for (int i = indice + 1; i < tamanho; i++)
    {
        if (*(N + i) > maior_digito)
        {
            maior_digito = *(N + i);
        }
    }
         //4               //1   sim
    if (maior_digito != *(N + indice)) //verificar o maior digito
    {

        for (int i = indice + 1; i < tamanho; i++)
        {
            if (*(N + i) == maior_digito) //procura de novo o maior digito pra fzr a troca
            {
                // N+1= '2' ==4 Não
                // N+2= '3' ==4 não
                //N+3= '4'==4 sim
                               // troca
                char temp = *(N + indice); //N[0]='1'
                *(N + indice) = *(N + i);//N[3]='4'
                *(N + i) = temp; //N[3]='1'

                encontrarMaior(N, T - 1, indice + 1, maior);
                  //chamando a própria função com uma troca a menos t-1, sobe lá pra cima, depois desce
                  //indice + 1 é que foi pra próprima posição

                  //segunda troca, meu vetor volta pro estado original, ou seja 
                temp = *(N + indice); //N[0] que agora é 4
                *(N + indice) = *(N + i); //N[0] recebe N[3]=1
                *(N + i) = temp;//N[3] recebe o 4
            } // voltando ficaria[1 2 3 4]
        }
    }

    encontrarMaior(N, T, indice + 1, maior); //agora minha função avança pro próximo indice 
}
