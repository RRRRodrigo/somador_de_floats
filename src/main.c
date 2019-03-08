#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

char* entrada;
int auxiliar = 0, tam = 0, flag = 0, aux2 = 0;
entrada = calloc(100, sizeof(char));
int i = 0, j = 0;
float soma = 0, aux = 0;
fgets(entrada,100,stdin);
tam = strlen(entrada);

for(i=0;i<100;i++){
  flag = 0;
  auxiliar = (int)entrada[i] - '0'; 
  if(auxiliar >= 0 && auxiliar < 10){
    if(entrada[i+1] == '.'){
	auxiliar = (int)entrada[i+2] - '0';
      if(auxiliar >= 0 && auxiliar < 10){
        if(entrada[i+3] == ' ' || entrada[i+3] == '\n'){
          soma = soma + (entrada[i] - '0');
          aux = entrada[i+2] - '0';
          aux = aux/10;
          soma = soma + aux;
          aux = 0;
          i = i + 2;
        }
      }
    }
    else if(entrada[i+1] == ' ' || entrada[i+1] == '\n'){
      soma = soma + (entrada[i] - '0');
      continue;
    }
    auxiliar = (int)entrada[i+1] - '0';
    if(auxiliar >= 0 && auxiliar < 10){
      if(atoi(entrada) < 0)
	continue;
      soma = soma + atoi(entrada+i);
	aux2 = atoi(entrada+i);
      auxiliar = (int)entrada[i+1] - '0';
      while(auxiliar >= 0 && auxiliar < 10){
	auxiliar = (int)entrada[i+1] - '0';
	if(entrada[i+1] == '.'){
		flag++;
		break;
	}
	i++;
      }
	if(flag)
	soma = soma - aux2;
    }
  }

}

printf("%g\n", soma);
return 0;
}
