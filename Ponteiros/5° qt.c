#include <stdio.h>

void contaTemperatura( float temperatura[],  float temp, int *cont);

int main(){

    float vt[10]; int ct=0; float temp;

    for(int i=0; i<10; i++){

        printf("digite as temperaturas\n");
        scanf("%f", &vt[i]);
    }

    printf("digite uma temperatura que deseja ver\n");
    scanf("%f", &temp);

    contaTemperatura(vt,  temp, &ct);

    return 0;
}
void contaTemperatura( float temperatura[], float temp, int *cont){

    for(int i=0; i<10; i++){

        if(temp == temperatura[i]){
            (*cont)++;
        }
    }

    printf("%d\n", *cont);
}
