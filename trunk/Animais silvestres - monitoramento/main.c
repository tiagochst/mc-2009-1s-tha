#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "defines.h"
#include "funcoes.h"


int main()
{
  FILE *fpe;
  char opcao;
  char pos[50],linha[50],*result; 
  char procura[50];
  char deli;
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
  
  case 'A':
   
    fpe=fopen("individuos.txt","r+");
    printf("o que voce procura: \n");  
    scanf("%s",procura);
    while(fgetc(fpe)!=EOF){
      fgets(linha,50,fpe);  
      result = strtok( linha, "#" );
      
      while( result != NULL ) {
	if(strcmp(result,procura)==0){
	  printf("encontrado %s\n",result);
	}  
	result = strtok( NULL,"#" );
	
      }
    }
    fclose(fpe);
      
 break;
    
  case 'R':
    break;

  case 'V':
    break;

  case 'S':
    exit(1);
    break;

  }
  return 0;
}
