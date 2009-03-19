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
  char linha[50],copia[50],*result,*mudar,*t,*k; 
  char procura[50],procura_esp[50],procura_indv[50];
  INDIVIDUOS inserir; 
  long size;
  int contador;
  int col;
 
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
    printf("Como deseja atualizar?\n(A)-Por especies\n(B)-Por individuo\n");   
    scanf(" %c",&opcao); 

    if(toupper(opcao)=='A') {
      printf("Qual a especie que deve ser atualizada?: \n");  
      scanf("%s",procura_esp);
      printf(IND_ESPC);
      scanf(" %d",&(inserir.num_especie));
      
      while(fgetc(fpe)!=EOF){
	size=ftell (fpe);
	
	fgets(linha,50,fpe);  
	strcpy(copia,linha);
	
	result = strtok( linha, "#" );
	printf("%s %s\n",procura_esp,result);   
	while( result != NULL ) {
	  if(strncmp (procura_esp,result,strlen(procura_esp)) ==0){
	    
	    contador=0;
	    
	    mudar = strtok(copia, "#" );
	    
	    while  (mudar != NULL)
	      {
		if(contador==2){ k=mudar;}
		if(contador==1){ t=mudar;}
		mudar=strtok(NULL,"#");
		contador++;
	      }
	    fseek (fpe, size-1, 0);
	    fprintf(fpe,"#%-10d#%s#%s#\n",inserir.num_especie,t,k);
	    break;
	  }
	  result=NULL;	
	}
      }
    }
    else if(toupper(opcao)=='B'){

      printf("Qual individuo deve ter seus dados ataulizados: \n");  
      scanf("%s",procura_indv);
      printf("Qual a sua especie? \n");  
      scanf("%s",procura_esp);
   
      while(fgetc(fpe)!=EOF){
	size=ftell (fpe);

	fgets(linha,50,fpe);  
	strcpy(copia,linha);
   
	result = strtok( linha, "#" );
    
	while( result != NULL ) {
	  if(strncmp (procura_esp,result,strlen(procura_esp)) ==0){
	    result = strtok( NULL,"#" );
	  if(strncmp (procura_indv,result,strlen(procura_indv)) ==0){
	      
	      /*impressao do menu de opcoes listado em funcoes.c*/
	      menu_upd_esp();
	      
	      printf("encontrado %s\n",result);
	      scanf(" %c",&opcao); 
	      
	      
	      switch(toupper(opcao))
		{
		  
		case 'A':
		  printf(IND_SEX);
		  scanf(" %c",&(inserir.sexo));
		  contador=0;
	      
		  mudar = strtok(copia, "#" );
	 	 
		  while  (mudar != NULL)
		    {
		      if(contador==1){ k=mudar;contador++;}
		      if(contador==0){ t=mudar;contador++;}


		      mudar=strtok(NULL,"#");
	
		    }
		  fseek (fpe, size-1, 0);

		  fprintf(fpe,"#%s#%s#%c#\n",t,k,inserir.sexo);
		  break;


		case 'B':
		  printf(IND_INDIV);
		  scanf(" %d",&(inserir.num_individuo));
		  contador=0;
      
		  mudar = strtok(copia, "#" );
	 	 
		  while  (mudar != NULL)
		    {
		      if(contador==2){ k=mudar;}
		      if(contador==0){ t=mudar;}
		      mudar=strtok(NULL,"#");
		      contador++;
		    }
		  fseek (fpe, size-1, 0);
		  fprintf(fpe,"#%s#%-10d#%s#\n",t,inserir.num_individuo,k);
		  break;


		case 'C':
		  printf(IND_ESPC);
		  scanf(" %d",&(inserir.num_especie));
		  contador=0;
      
		  mudar = strtok(copia, "#" );
	 	 
		  while  (mudar != NULL)
		    {
		      if(contador==2){ k=mudar;}
		      if(contador==1){ t=mudar;}
		      mudar=strtok(NULL,"#");
		      contador++;
		    }
		  fseek (fpe, size-1, 0);

		  fprintf(fpe,"#%-10d#%s#%s#\n",inserir.num_especie,t,k);
		  break;


		case 'D':
		  printf(IND_SEX);
		  scanf(" %c",&(inserir.sexo));
		  printf(IND_INDIV);
		  scanf(" %d",&(inserir.num_individuo));
		  contador=0;
      
		  mudar = strtok(copia, "#" );
	 	 
		  while  (mudar != NULL)
		    {
		      if(contador==0){ t=mudar;}
		      mudar=strtok(NULL,"#");
		      contador++;
		    }
		  fseek (fpe, size-1, 0);
		  fprintf(fpe,"#%s#%-10d#%c#\n",t,inserir.num_individuo,inserir.sexo);
		  break;

		case 'E':
		  printf(IND_ESPC);
		  scanf(" %d",&(inserir.num_especie));

		  printf(IND_INDIV);
		  scanf(" %d",&(inserir.num_individuo));

		  contador=0;
      
		  mudar = strtok(copia, "#" );
	 	 
		  while  (mudar != NULL)
		    {
		      if(contador==2){ k=mudar;}
		      mudar=strtok(NULL,"#");
		      contador++;
		    }
		  fseek (fpe, size-1,0);
		  fprintf(fpe,"#%-10d#%-10d#%s#\n",inserir.num_especie,inserir.num_individuo,k);
		  break;


		case 'F':
		  printf(IND_INDIV);
		  scanf(" %d",&(inserir.num_individuo));
		  printf(IND_SEX);
		  scanf(" %c",&(inserir.sexo));

		  contador=0;
      
		  mudar = strtok(copia, "#" );
	 	 
		  while  (mudar != NULL)
		    {
		      if(contador==0){ t=mudar;}
		      mudar=strtok(NULL,"#");
		      contador++;
		    }
		  fseek (fpe, size-1, 0);
		  fprintf(fpe,"#%s#%-10d#%c#\n",t,inserir.num_individuo,inserir.sexo);
		  break;


		case 'G':
		  fseek (fpe, size-1, 0);
		  inserir_individuos(fpe);
		  break;
	    
		}

	    }  

	  }
	      result=NULL;

	}
      }
      
    }
    fclose(fpe);
      
    break;

    /*remover*/    
  case 'R':
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
