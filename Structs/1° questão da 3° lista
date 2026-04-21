#include <stdio.h>

int main(){

  char string1[5]="roma";
  char string2[5]="raom";


  int i=0;
  int c1=0;

  while( string1[i] !='\0'){

    if( string1[i] !='\0'){
      c1++;
    }
    i++;
  }

  int j=0;
  int c2=0;

  while( string2[j] !='\0'){

    if(string2[j] !='\0'){
      c2++;
    }
    j++;
  }
 int v[5]={0,0,0,0,0};
 int letras=0;

 for( int i=0; i<c1; i++){
  for( int j=0; j<c2; j++){

    if( string1[i] == string2[j] && v[j]==0){

      v[j]=1;
      letras++;
      break;
    }
  }
 }

  if( letras== c1){
    printf("Sao anagramas\n");
  } else{
    printf("Nao sao anagramas\n");
  }

  return 0;
}
