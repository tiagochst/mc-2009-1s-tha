#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void inserir_individuos(FILE * fpe){
  INDIVIDUOS inserir; 

  printf(IND_ESPC);
  scanf(" %d",&(inserir.num_especie));
  printf(IND_INDIV);
  scanf(" %d",&(inserir.num_individuo));
  printf(IND_SEX);
  scanf(" %c",&(inserir.sexo));
  fprintf(fpe,"#%d#%d#%c\n",inserir.num_especie,inserir.num_individuo,inserir.sexo);


  return;
}

void ler_individuos(FILE * fpe){
  char c;
  while (fscanf(fpe,"%c",&c)!=EOF) { printf("%c",c); }
  return;
}

void menu_upd_esp()
{

	    printf("O que deseja atualizar?\n");
	    printf("(A)-Sexo \n");
	    printf("(B)-Numero de identificaçao do invidividuo\n");
	    printf("(C)-Numero de identificaçao da especie\n");
	    printf("(D)-Sexo e -Numero de identificaçao do invidividuo\n");
	    printf("(E)-Numero de identificaçao do invidividuo e Numero de identificaçao da especie\n");
	    printf("(F)-Sexo e Numero de identificaçao do invidividuo\n");
	    printf("(G)-Todos os dados\n ");
	    return;
}
