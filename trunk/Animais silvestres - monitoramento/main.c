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
  char procura[50];
  INDIVIDUOS inserir; 

  long size;
 
  printf(OPT_IND);
  scanf("%c",&opcao);
  int contador;
  int col;
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
    printf("Como deseja atualizar?\n(A)-Por especies\n(B)-Por individuo\n");   
    scanf(" %c",&opcao); 
    if(toupper(opcao)=='A'){col=0;}
    else if(toupper(opcao)=='B'){col=1;}

    printf("Qual individuo deve ter seus dados ataulizados: \n");  
    scanf("%s",procura);
    while(fgetc(fpe)!=EOF){
      size=ftell (fpe);

      fgets(linha,50,fpe);  
      strcpy(copia,linha);
   
      result = strtok( linha, "#" );
    
      contador=0;  
      while( result != NULL ) {
	if(contador ==col){
	  if(strcmp(result,procura)==0){

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

		fprintf(fpe,"#%s#%s#%c\n",t,k,inserir.sexo);
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
		fprintf(fpe,"#%s#%d#%s\n",t,inserir.num_individuo,k);
		break;


	      case 'C':
		printf(IND_INDIV);
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

		fprintf(fpe,"#%d#%s#%s\n",inserir.num_especie,t,k);
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
		fprintf(fpe,"#%s#%d#%c\n",t,inserir.num_individuo,inserir.sexo);
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
		fseek (fpe, size-1, 0);
		fprintf(fpe,"#%d#%d#%s\n",inserir.num_especie,inserir.num_individuo,k);
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
		fprintf(fpe,"#%s#%d#%c\n",t,inserir.num_individuo,inserir.sexo);
		break;


	      case 'G':
		fseek (fpe, size-1, 0);
		inserir_individuos(fpe);
		break;
	    
	    
	      }  
	  }
	}
	result = strtok( NULL,"#" );
	contador++;
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
