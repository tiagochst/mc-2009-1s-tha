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

  /*
   *Leitura de opçoes
   *L - ler conteudo do arquivo individuos.txt,em que esta listado os indivudos,seu sexo e especie
   *A - atualizar dados existentes
   *I - inserir dados de um individuo
   *R - remover 
  */ 
  printf(OPT_IND);
  scanf("%c",&opcao);
  switch(toupper(opcao)){

    /*Leitura*/
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
  
    /*insercao*/

  case 'I':

    fpe=fopen("individuos.txt","a");
    if(fpe==NULL)   
      printf(ERRO_ARQ);  
    else{
      inserir_individuos(fpe);
    }
 
    fclose(fpe);
    break;
  
    /*Atualizar
     *
     *Consiste em procurar uma linha, copiar dados que nao serao alterados
     *e inserir no local da linha uma nova, sobreescrevendo-a com os novos dados
     *     
     */

  case 'A':
   
    fpe=fopen("individuos.txt","r+");
    upd_ind(fpe);
    fclose(fpe);
      
    break;

    /*remover*/    
  case 'R':
    fpe=fopen("individuos.txt","r+");
	 remover_individuos(fpe);
    fclose(fpe);

    break;

    /*voltar menu*/
  case 'V':
    break;

    /*sair do programa*/
  case 'S':
    exit(1);
    break;

  }
  return 0;
}
