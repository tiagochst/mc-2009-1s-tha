#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void remover_individuos(FILE * fpe){

  char linha[50],copia[50],*result,*mudar,*ind,*esp,*sexo;
  char opcao; 
  char procura_esp[50],procura_indv[50];/*guardam valores de procura para compraçao*/
  INDIVIDUOS inserir; /*cria individuo para guardar valor enviado pelo usuario na atualizaçao*/
  long size;/*guarda posiçao do inicio da linha antes de pegar uma linha do arquivo */
  int contador;/*usado para especificar na atualizaçao qual termo deve ser gurdado apos a quebra da string*/
  
  
  printf("O que deseja remover?\n-(A)Especie\n(B)-Individuo\n");
  scanf(" %c",&opcao); 
  
  if(toupper(opcao)=='A') {
    printf("Qual a especie que deve ser removida?: \n");  
    scanf("%s",procura_esp);
  
   while(fgetc(fpe)!=EOF){

      size=ftell (fpe);/*guarda posicao da linha que vai ser avalida,caso seja necessario voltar a sua posicao*/
      fgets(linha,50,fpe);  
      strcpy(copia,linha);/*faz uma copia da string para ser novamente avaliada(seria o mesmo que le-la novamente do arquivo)*/
      result = strtok( linha, "#" );/*quebra a string de acordo com nosso delimitador #*/
		


      while( result != NULL ) {
	/*procura na linha se a especie requerida e a existente*/
	if(strncmp (procura_esp,result,strlen(procura_esp)) ==0){
	    
		/*
	   *Retorna ao inicio da linha e escreve sobre ela os novos dados
	   */
	  fseek (fpe, size-1, 0);
	  fprintf(fpe,"**                       ");
	  break;
	}
	//linha procurada nao satifaz a procura
	result=strtok(NULL,"#");
	result=NULL;	
      }
    }
  }


  else if(toupper(opcao)=='B'){
    
    /*
     * Para procurar um individuo         especifico deve entrar com seu numero de identificacao e especie
     */

    printf("Qual individuo deve ter seus dados removidos? \n");  
    scanf("%s",procura_indv);
   
    while(fgetc(fpe)!=EOF){
      size=ftell (fpe);

      fgets(linha,50,fpe);  
      strcpy(copia,linha);
   
      result = strtok( linha, "#" );
    
      while( result != NULL ) {
	  if(strncmp (procura_indv,result,strlen(procura_indv)) ==0){
	    
	  	fseek (fpe, size-1, 0);
	 	 fprintf(fpe,"**                      \n");
		break;     

		}

	result=NULL;

      }
    }
      
  }
return ;

}

void inserir_individuos(FILE * fpe){
  INDIVIDUOS inserir; 

  printf(IND_ESPC);
  scanf(" %d",&(inserir.num_especie));
  printf(IND_INDIV);
  scanf(" %d",&(inserir.num_individuo));
  printf(IND_SEX);
  scanf(" %c",&(inserir.sexo));
  fprintf(fpe,"#%-10d#%-10d#%c#\n",inserir.num_especie,inserir.num_individuo,inserir.sexo);


  return;
}

void ler_individuos(FILE * fpe){
  char linha[50],*result,*sexo,*ind,*esp;
  int contador=0;
  printf("--------------------------------------------------------\n");
  printf("|     Individuo     |     Especie       |     Sexo     |\n");
  
  while(fgetc(fpe)!=EOF) {
    
    fgets(linha,50,fpe);  
if(linha[0]!='*'){
    result = strtok( linha, "#" );
    
    
    while  (result != NULL)
      {
	if(contador==2){ sexo=result;contador++;}
	if(contador==1){ ind=result;contador++;}
	if(contador==0){ esp=result;contador++;}
	
	result=strtok(NULL,"#");
      }
    printf("--------------------------------------------------------\n");
    printf("|     %s    |     %s    |      %s       | \n",ind,esp,sexo);
}
  }  
  printf("--------------------------------------------------------\n");

  return;
}

void menu_upd_esp()
{
  
  printf("O que deseja atualizar?\n");
  printf("(A)-Sexo \n");
  printf("(B)-Numero de identificaçao do invidividuo\n");
  printf("(C)-Numero de identificaçao da especie\n");
  printf("(D)-Sexo e Numero de identificaçao do invidividuo\n");
  printf("(E)-Numero de identificaçao do invidividuo e Numero de identificaçao da especie\n");
  printf("(F)-Sexo e Numero de identificaçao do invidividuo\n");
  printf("(G)-Todos os dados\n ");
  return;
}


void upd_ind(FILE * fpe){

  char opcao; 

  /* linha contem linha do arquivo,e copia eh uma copia dela,
   * result eh um apontador para a linha dividida em tres strings assim como mudar,
   * t e k apontam para pedaços da string a serem mantidas(nao atualizadas)
   */
  
  char linha[50],copia[50],*result,*mudar,*ind,*esp,*sexo;
   
  char procura_esp[50],procura_indv[50];/*guardam valores de procura para compraçao*/
  INDIVIDUOS inserir; /*cria individuo para guardar valor enviado pelo usuario na atualizaçao*/
  long size;/*guarda posiçao do inicio da linha antes de pegar uma linha do arquivo */
  int contador;/*usado para especificar na atualizaçao qual termo deve ser gurdado apos a quebra da string*/
  
  
  /* Opcoes de atualizacao
   * A - ataulizacao por especie,troca o valor de especie de cada membro da especie
   * Ex: exitem 10 individuos da especie 15,porem essa especie foi relistada
   * e ganhou novo valor 30.Assim todos desse especie terao que mudar seu valor
   * B - ataulizacao por individuo - encontra individuo de determinda especie e troca qualquer informaçoes dele
   * Ex: individuo 1 da especie 15 sexo f,pode mudar para individuo 2 especie 30 sexo m no caso mais abrangente
   *(ha a possibilidade de mudar um valor,dois ou todos de uma vez) 
   */ 
  printf("Como deseja atualizar?\n(A)-Por especies\n(B)-Por individuo\n");
  scanf(" %c",&opcao); 
  
  if(toupper(opcao)=='A') {
    printf("Qual a especie que deve ser atualizada?: \n");  
    scanf("%s",procura_esp);
    printf(IND_ESPC);
    scanf(" %d",&(inserir.num_especie));
      
    while(fgetc(fpe)!=EOF){

      size=ftell (fpe);/*guarda posicao da linha que vai ser avalida,caso seja necessario voltar a sua posicao*/
      fgets(linha,50,fpe);  
      strcpy(copia,linha);/*faz uma copia da string para ser novamente avaliada(seria o mesmo que le-la novamente do arquivo)*/
      result = strtok( linha, "#" );/*quebra a string de acordo com nosso delimitador #*/

      while( result != NULL ) {
	/*procura na linha se a especie requerida e a existente*/
	if(strncmp (procura_esp,result,strlen(procura_esp)) ==0){
	    
	  contador=0;
	  /*divide a string novamente*/    
	  mudar = strtok(copia, "#" );
	    
	  while  (mudar != NULL)
	    {
	      /*copia dados atuais que nao serao alterados*/
	      if(contador==2)
		sexo=mudar;/*guarda pedaco 2,sexo*/
	      if(contador==1)
		ind=mudar;/*guarda pedaco 1,numero do individuo*/
	      mudar=strtok(NULL,"#");
	      contador++;
	    }
	  /*
	   *Retorna ao inicio da linha e escreve sobre ela os novos dados
	   */
	  fseek (fpe, size-1, 0);
	  fprintf(fpe,"#%-10d#%s#%s#\n",inserir.num_especie,ind,sexo);
	  break;
	}
	//linha procurada nao satifaz a procura
	result=NULL;	
      }
    }
  }

  
  else if(toupper(opcao)=='B'){
    
    /*
     * Para procurar um individuo especifico deve entrar com seu numero de identificacao e especie
     */

    printf("Qual individuo deve ter seus dados ataulizados? \n");  
    scanf("%s",procura_indv);
   
    while(fgetc(fpe)!=EOF){
      size=ftell (fpe);

      fgets(linha,50,fpe);  
      strcpy(copia,linha);
   
      result = strtok( linha, "#" );
    
      while( result != NULL ) {
	  if(strncmp (procura_indv,result,strlen(procura_indv)) ==0){
	    
	    printf("O indivudo da especie foi encontrado,o que deseja atualizar? \n");
	      
	    /*impressao do menu de opcoes listado em funcoes.c*/
	    menu_upd_esp();
	    scanf(" %c",&opcao); 
	    
	    
	    
	    contador=0;
	      
	    mudar = strtok(copia, "#" );
	    
	    while  (mudar != NULL)
	      {
		if(contador==2){ sexo=mudar;contador++;}
		if(contador==1){ ind=mudar;contador++;}
		if(contador==0){ esp=mudar;contador++;}
		
		
		mudar=strtok(NULL,"#");
		
	      }
	    
	    fseek (fpe, size-1, 0);
	    
	    
	    
	    switch(toupper(opcao))
	      {
		
		

	      case 'A':
		printf(IND_SEX);
		scanf(" %c",&(inserir.sexo));

		fprintf(fpe,"#%s#%s#%c#\n",esp,ind,inserir.sexo);
		break;


	      case 'B':
		printf(IND_INDIV);
		scanf(" %d",&(inserir.num_individuo));

		fprintf(fpe,"#%s#%-10d#%s#\n",esp,inserir.num_individuo,sexo);
		break;


	      case 'C':
		printf(IND_ESPC);
		scanf(" %d",&(inserir.num_especie));

		fprintf(fpe,"#%-10d#%s#%s#\n",inserir.num_especie,ind,sexo);
		break;


	      case 'D':
		printf(IND_SEX);
		scanf(" %c",&(inserir.sexo));
		printf(IND_INDIV);
		scanf(" %d",&(inserir.num_individuo));
		fprintf(fpe,"#%s#%-10d#%c#\n",esp,inserir.num_individuo,inserir.sexo);
		break;

	      case 'E':
		printf(IND_ESPC);
		scanf(" %d",&(inserir.num_especie));

		printf(IND_INDIV);
		scanf(" %d",&(inserir.num_individuo));
		fprintf(fpe,"#%-10d#%-10d#%s#\n",inserir.num_especie,inserir.num_individuo,sexo);
		break;


	      case 'F':
		printf(IND_INDIV);
		scanf(" %d",&(inserir.num_individuo));
		printf(IND_SEX);
		scanf(" %c",&(inserir.sexo));
		fprintf(fpe,"#%s#%-10d#%c#\n",esp,inserir.num_individuo,inserir.sexo);
		break;


	      case 'G':
		inserir_individuos(fpe);
		break;
	    
	      }

	  }  

	result=strtok(NULL,"#");
	
	
      }
    }
      
  }
}