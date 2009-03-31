#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "defines.h"
#include "funcoes.h"


int main()
{
  FILE *fpe;
  char opcao,arq;

  while(1){
    printf(OPT_ARQ);
    scanf(" %c",&arq);

    switch(toupper(arq)){

      /*especie.txt*/
    case 'A':
      /*
       *Leitura de opçoes para especie.txt
       *L - ler conteudo do arquivo ,em que esta listado :
       *    Indentificado unico da especie,caminho no sistema de arquivos para um arquivo 
       *    com a foto de um individuo da especie,data,nome cientifico,nome popular e 
       *    descrição da especie.  seu sexo e especie
       *A - atualizar dados existentes
       *I - inserir dados de um individuo
       *R - remover 
       */ 

      printf(OPT_ESP);
      scanf(" %c",&opcao);

      switch(toupper(opcao)){

	/*Leitura*/
      case 'L':

	fpe=fopen("especies.txt","r");
	if (fpe==NULL) {
	  printf(ERRO_ARQ);
	}
	else{
	  ler_especies(fpe);   
	  fclose(fpe);
	}
	break;
  
	/*insercao*/

      case 'I':

	fpe=fopen("especies.txt","a");
	if(fpe==NULL)   
	  printf(ERRO_ARQ);  
	else{
	  inserir_especies(fpe);
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
   
	fpe=fopen("especies.txt","r+");
	if(fpe==NULL)   
	  printf(ERRO_ARQ);  
	else{
	  // upd_ind(fpe);

	}

	// upd_ind(fpe);
	fclose(fpe);
      
	break;

	/*remover*/    
      case 'R':
	fpe=fopen("especies.txt","r+");
	if(fpe==NULL)   
	  printf(ERRO_ARQ);  
	else{
	  // upd_ind(fpe);

	}

	//remover_especie(fpe);
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












      break;
      /*individuo.txt*/
    case 'B':


      /*
       *Leitura de opçoes para individuo.txt
       *L - ler conteudo do arquivo ,em que esta listado os indivudos,seu sexo e especie
       *A - atualizar dados existentes
       *I - inserir dados de um individuo
       *R - remover 
       */ 
      printf(OPT_IND);
      scanf(" %c",&opcao);

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
      break;


      /*capturas.data*/
    case 'C':
      /*
       *Leitura de opçoes para capturas.data
       *L - ler conteudo do arquivo ,em que esta listado :
       *    Indentificado unico do individuo ,comprimento,largura,peso,data de captura,local de captura
       *A - atualizar dados existentes
       *I - inserir dados de um individuo capturado
       *R - remover 
       */ 

      printf(OPT_CAP);
      scanf(" %c",&opcao);

      switch(toupper(opcao)){

	/*Leitura*/
      case 'L':

	fpe=fopen("capturas.data","rb");
	if (fpe==NULL) {
	  printf(ERRO_ARQ);
	}
	else{
	  ler_captura(fpe);   
	  fclose(fpe);
	}
	break;
  
	/*insercao*/

      case 'I':

	fpe=fopen("capturas.data","ab");
	if(fpe==NULL)   
	  printf(ERRO_ARQ);  
	else{
	  inserir_captura(fpe);
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
   
	fpe=fopen("capturas.data","r+b");
	if(fpe==NULL)   
	  printf(ERRO_ARQ);  
	else{
	   upd_cap(fpe);

	}

	// upd_ind(fpe);
	fclose(fpe);
      
	break;

	/*remover*/    
      case 'R':
	fpe=fopen("capturas.data","r+b");
	if(fpe==NULL)   
	  printf(ERRO_ARQ);  
	else{

	remover_captura(fpe);
	 
	}
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












      break;
  
    case 'E':
      exit(1);
      break;




 	case 'F':
      
		fpe=fopen("capturas.data","rb");
		exibir_dados_cap(fpe);
      break;



    }


  }  
  return 0;
}
