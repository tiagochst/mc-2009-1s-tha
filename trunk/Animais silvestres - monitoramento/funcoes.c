#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
int verif_especies(FILE * fpe,int procura_esp);

/*************************************************************/
/*               OPERACOES ESPECIES.TXT                    */
/*************************************************************/


void remover_especies(FILE * fpe){

  char linha[50],copia[50],*result;
  char procura_esp[50];/*guardam valores de procura para compraçao*/
  long size;/*guarda posiçao do inicio da linha antes de pegar uma linha do arquivo */
  
  
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
  
  return ;

}

void inserir_especies(FILE * fpe){
  ESPECIES inserir; 
int verifica;

  printf(ESP_ESPC);
  scanf(" %d",&(inserir.num_especie));
  

	verifica=verif_especies(fpe,inserir.num_especie);
	
	if(verifica){
	  printf("Especie ja cadastrada\n");
	return;	
	} 
  
  printf(ESP_FOTO);
  scanf(" %s",(inserir.caminho_foto));
  printf(ESP_DATA);
  scanf(" %d",&(inserir.data));
  printf(ESP_NCIE);
  scanf(" %[^\n]",(inserir.nome_cientifico));
  printf(ESP_NPOP);
  scanf(" %[^\n]",(inserir.nome_popular));
  printf(ESP_DESC);
  scanf(" %[^\n]",(inserir.descricao));
  printf(" %d",strlen(inserir.caminho_foto));
  inserir.caminho_foto[strlen(inserir.caminho_foto)]='|';
  inserir.caminho_foto[strlen(inserir.caminho_foto)+1]='\0';
  
  
  fprintf(fpe,"#%-10d#%-255s#%-10d#%-30s#%-30s#%-500s#\n",inserir.num_especie,inserir.caminho_foto,inserir.data,inserir.nome_cientifico,inserir.nome_popular,inserir.descricao);


  return;
}

void ler_especies(FILE * fpe){
  char linha[900],*result,*data,*esp,*cien,*pop,*descri,*foto;
  int contador=0;
  printf("--------------------------------------------------------\n");
  //printf("|     Especie       |     caminho da foto     |      \n");
  
  while(fgetc(fpe)!=EOF) {
    
    fgets(linha,900,fpe);  
    if(linha[0]!='*'){
      result = strtok( linha, "#" );
    
    
      while  (result != NULL)
	{
	  if(contador==5){ descri=result;contador++;}
	  if(contador==4){ pop=result;contador++;}
	  if(contador==3){ cien=result;contador++;}
	  if(contador==2){ data=result;contador++;}
	  if(contador==1){ foto=result;contador++;}
	  if(contador==0){ esp=result;contador++;}
	
	  result=strtok(NULL,"#");
	}
      printf("--------------------------------------------------------\n");
      //printf("|     %s    |     %s    |      %s       | \n",ind,esp,sexo);
      printf(" %s \n",esp);
      printf(" %s \n",foto);
      printf(" %s \n",data);
      printf(" %s \n",cien);
      printf(" %s \n",pop);
      printf(" %s \n",descri);
      printf("--------------------------------------------------------\n");
 

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


void upd_esp(FILE * fpe){

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
	      inserir_especies(fpe);
	      break;
	    
	    }

	}  

	result=strtok(NULL,"#");
	
	
      }
    }
      
  }
}







/*************************************************************/
/*               OPERACOES INDIVIDUOS.TXT                    */
/*************************************************************/
void remover_individuos(FILE * fpe){

  char linha[50],copia[50],*result;
  char opcao; 
  char procura_esp[50],procura_indv[50];/*guardam valores de procura para compraçao*/
  long size;/*guarda posiçao do inicio da linha antes de pegar uma linha do arquivo */
  
  
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

void menu_upd_ind()
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
	  menu_upd_ind();
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































/*************************************************************/
/*               OPERACOES Capturas.data                    */
/*************************************************************/


void remover_captura(FILE * fpe){

  char linha[50],copia[50],*result;
  char procura_ind[50];/*guardam valores de procura para compraçao*/
  long size;/*guarda posiçao do inicio da linha antes de pegar uma linha do arquivo */
  
  
  printf("Qual o numero do individuo que deve ser removido?: \n");  
  scanf("%s",procura_ind);
  
  while(fgetc(fpe)!=EOF){

    size=ftell (fpe);/*guarda posicao da linha que vai ser avalida,caso seja necessario voltar a sua posicao*/
    fgets(linha,50,fpe);  
    strcpy(copia,linha);/*faz uma copia da string para ser novamente avaliada(seria o mesmo que le-la novamente do arquivo)*/
    result = strtok( linha, "#" );/*quebra a string de acordo com nosso delimitador #*/
		


    while( result != NULL ) {
      /*procura na linha se a especie requerida e a existente*/
      if(strncmp (procura_ind,result,strlen(procura_ind)) ==0){
	    
	/*
	 *Retorna ao inicio da linha e escreve sobre ela os novos dados
	 */
	fseek (fpe, size-1, 0);
	fprintf(fpe,"**                                                                                                         ");
	break;
      }
      //linha procurada nao satifaz a procura
      result=NULL;	
    }
  }
  
  return ;

}

void inserir_captura(FILE * fpe){
 CAPTURA inserir; 

  printf(CAP_IND);
  scanf(" %d",&(inserir.num_individuo));
  printf(CAP_COMP);
  scanf(" %d",&(inserir.compr));
  printf(CAP_LARG);
  scanf(" %d",&(inserir.larg));
  printf(CAP_PESO);
  scanf(" %d",&(inserir.peso));
  printf(CAP_DATA);
  scanf(" %d",&(inserir.data));
  printf(CAP_LOCAL);
  scanf(" %[^\n]",(inserir.local));

  fprintf(fpe,"#%-10d#%-10d#%-10d#%-10d#%-10d#%-50s#\n",inserir.num_individuo,inserir.compr,inserir.larg,inserir.peso,inserir.data,inserir.local);


  return;
}

void ler_captura(FILE * fpe){
  char linha[900],*result,*data,*esp,*cien,*pop,*descri,*foto;
  int contador=0;
  printf("--------------------------------------------------------\n");
  
  while(fgetc(fpe)!=EOF) {
    
    fgets(linha,900,fpe);  
    if(linha[0]!='*'){
      result = strtok( linha, "#" );
    
    
      while  (result != NULL)
	{
	  if(contador==5){ descri=result;contador++;}
	  if(contador==4){ pop=result;contador++;}
	  if(contador==3){ cien=result;contador++;}
	  if(contador==2){ data=result;contador++;}
	  if(contador==1){ foto=result;contador++;}
	  if(contador==0){ esp=result;contador++;}
	
	  result=strtok(NULL,"#");
	}
      printf("--------------------------------------------------------\n");
      //printf("|     %s    |     %s    |      %s       | \n",ind,esp,sexo);
      printf("NUMERO DO INDIVIDUO: %s \n",esp);
      printf("COMPRIMENTO:         %s \n",foto);
      printf("LARGURA:             %s \n",data);
      printf("PESO:                %s \n",cien);
      printf("DATA DE CAPTURA:     %s \n",pop);
      printf("LOCAL DE CAPTURA:    %s \n",descri);
      printf("--------------------------------------------------------\n");
 

    }
  }  
  printf("--------------------------------------------------------\n");

  return;
}


/*
void menu_upd_cap()
{
  
  printf("O que deseja atualizar?\n");
  printf("(G)-Todos os dados\n ");
  return;
}

*/















void menu_upd_cap()
{
  
  printf("O que deseja atualizar?\n");
  printf("(A)-Todos os dados \n");
  printf("(B)-Numero de identificaçao do invidividuo\n");
  return;
}


void upd_cap(FILE * fpe){

  char opcao; 

  /* linha contem linha do arquivo,e copia eh uma copia dela,
   * result eh um apontador para a linha dividida em tres strings assim como mudar,
   * t e k apontam para pedaços da string a serem mantidas(nao atualizadas)
   */
  
  char linha[50],copia[50],*result,*mudar;
   
  char procura_indv[50];/*guardam valores de procura para compraçao*/
  long size;/*guarda posiçao do inicio da linha antes de pegar uma linha do arquivo */
  
  
 
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
	  menu_upd_cap();
	  scanf(" %c",&opcao); 
	    
	  mudar = strtok(copia, "#" );
	    
	  fseek (fpe, size-1, 0);
	    
	    
	  switch(toupper(opcao))
	    {
		
	    case 'A':
	      inserir_captura(fpe);
	      break;


	      break;

	    
	    }

	}  

	result=strtok(NULL,"#");
	
	
      }
    } 
}      

















void exibir_dados_cap(FILE * fpe){
  char *result,*data,*esp,*cien,*pop,*descri,*foto;
  int contador=0;
   char linha[108],copia[108];
  char procura_ind[50];/*guardam valores de procura para compraçao*/
  long size;/*guarda posiçao do inicio da linha antes de pegar uma linha do arquivo */
  
  
  printf("Exibir os dados de qual individuo?: \n");  
  scanf("%s",procura_ind);
  
  while(fgetc(fpe)!=EOF){

    size=ftell (fpe);/*guarda posicao da linha que vai ser avalida,caso seja necessario voltar a sua posicao*/
    fgets(linha,108,fpe);  
    strcpy(copia,linha);/*faz uma copia da string para ser novamente avaliada(seria o mesmo que le-la novamente do arquivo)*/
    result = strtok( linha, "#" );/*quebra a string de acordo com nosso delimitador #*/
		


  
      /*procura na linha se a especie requerida e a existente*/
      if(strncmp (procura_ind,result,strlen(procura_ind)) ==0){
	    
	/*
	 *Retorna ao inicio da linha e escreve sobre ela os novos dados
	 */
		fseek (fpe, size-1, 0);
 
 	   fgets(linha,108,fpe);  
  
      result = strtok( linha, "#" );
    
    
      while  (result != NULL)
	{
	  if(contador==5){ descri=result;contador++;}
	  if(contador==4){ pop=result;contador++;}
	  if(contador==3){ cien=result;contador++;}
	  if(contador==2){ data=result;contador++;}
	  if(contador==1){ foto=result;contador++;}
	  if(contador==0){ esp=result;contador++;}
	
	  result=strtok(NULL,"#");
	}
      printf("--------------------------------------------------------\n");
      //printf("|     %s    |     %s    |      %s       | \n",ind,esp,sexo);
      printf("NUMERO DO INDIVIDUO: %s \n",esp);
      printf("COMPRIMENTO:         %s \n",foto);
      printf("LARGURA:             %s \n",data);
      printf("PESO:                %s \n",cien);
      printf("DATA DE CAPTURA:     %s \n",pop);
      printf("LOCAL DE CAPTURA:    %s \n",descri);
      printf("--------------------------------------------------------\n");
 

   
  }  
 }
 
  return;
}





















int verif_especies(FILE * fpe,int procura_esp){

  char linha[900],copia[900],*result;
 int esp,final;
   
    final=ftell (fpe);/*guarda posicao da linha que vai ser avalida,caso seja necessario voltar a sua posicao*/
 	 fseek (fpe, 0, 0);

  while(fgetc(fpe)!=EOF){
   fgets(linha,900,fpe);  
    strcpy(copia,linha);/*faz uma copia da string para ser novamente avaliada(seria o mesmo que le-la novamente do arquivo)*/
    result = strtok( linha, "#" );/*quebra a string de acordo com nosso delimitador #*/
		
		esp = atoi (result);

	 if(procura_esp==esp) {
	    return 1;
		 }
    }
 
  	 fseek (fpe, final, 0);
 
  
  return 0;

}
