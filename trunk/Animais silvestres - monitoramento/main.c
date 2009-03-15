#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "defines.h"
#include "funcoes.h"


int main()
{
  FILE *fpe;
  char opcao;

  printf(OPT_IND);
  scanf("%c",&opcao);


  switch(toupper(opcao)){

  case 'L':

    fpe=fopen("individuos.txt","r");
    if (fpe==NULL) {
      printf(ERRO_ARQ);
    }
    else{
      ler_individuos(fpe);   
	fclose(fpe);
    }
    break;
  case 'I':

    fpe=fopen("individuos.txt","a");
    if(fpe==NULL)   
      printf(ERRO_ARQ);  
    else{
      inserir_individuos(fpe);
    }
 
    fclose(fpe);
    break;
  
  }
  return 0;
}
