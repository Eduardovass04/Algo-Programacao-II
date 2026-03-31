#include <stdio.h>

int main()
{

  int vetor[10];
  int vetor2[10];
  int n;
  int k = 0;

  printf("Digite os tamanho do vetor\n");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Digite os elementos do vetor\n");
    scanf("%d", &vetor[i]);
  }

  for (int i = 0, j = n - 1; i <=j; i++, j--)
  {
    if (i == j)
    {
      vetor2[k] = vetor[i];
    }
    else
    {
      vetor2[k] = vetor[i] + vetor[j];
    }
    k++;
  }

  for (int i = 0; i < k; i++)
  {

    printf("%d", vetor2[i]);
  }

  return 0;
}
