/* pedidos de entrada especies.txt*/
#define ESP_ESPC "\nPor favor,entre com o indentificador unico da especie:  "
#define ESP_DATA "\nPor favor,entre com a data da especie:  "
#define ESP_FOTO "\nPor favor,entre com o caminho da foto:  "
#define ESP_NCIE "\nPor favor,entre com o nome cientifico:  "
#define ESP_NPOP "\nPor favor,entre com o nome popular :  "
#define ESP_DESC "\nPor favor,entre com a descrição da espécie,quando TERMINAR DIGITE #:  "


/* pedidos de entrada individuos.txt*/
#define IND_ESPC "\nPor favor,entre com o indentificador unico da especie:  "
#define IND_INDIV "\nPor favor,entre com o indentificador unico do individuo:  "
#define IND_SEX "\nPor favor,entre com o sexo:  "


/* pedidos de entrada captura.data*/
#define CAP_IND "\nPor favor,entre com o indentificador unico do individuo :  "
#define CAP_DATA "\nPor favor,entre com a data da captura:  "
#define CAP_LOCAL "\nPor favor,entre com o local de captura :  "
#define CAP_PESO "\nPor favor,entre com o peso do individuo:  "
#define CAP_LARG "\nPor favor,entre com a largura do individuo :  "
#define CAP_COMP "\nPor favor,entre com o comprimento do individuo:  "


/*erro na manipulação do arquivo */
#define ERRO_ARQ "Arquivo de entrada nao existe ou sem premissao de leitura.\n"


/* Menus de escolha do usuario*/
#define OPT_ARQ "O que deseja manipular? :\n -(A)Especies\n -(B)Individuos\n -(C)Capturas\n -(E)Sair\n"
#define OPT_IND "Opcoes de tarefas relacionada aos dados de individuos:\n -(L)Ver todos os individuos listados\n -(I)Inserir novo individuo\n -(A)Atualizar dados de individuo\n -(V)Voltar Menu\n -(S)Sair\n Por favor faça sua escolha: "
#define OPT_ESP "Opcoes de tarefas relacionada aos dados de especies:\n -(L)Ver todos os especies listados e informacoes\n -(I)Inserir nova especie\n -(A)Atualizar dados de individuo\n -(V)Voltar Menu\n -(S)Sair\n Por favor faça sua escolha: "
#define OPT_CAP "Opcoes de tarefas relacionada aos dados de captura:\n -(L)Ver todos os individuos capturados e informacoes\n -(I)Inserir nova captura\n -(A)Atualizar dados decaptura\n -(R)Remover captura\n -(V)Voltar Menu\n -(S)Sair\n Por favor faça sua escolha: "


typedef struct{
	
	int num_especie,num_individuo;
	char sexo;

}INDIVIDUOS;


typedef struct{

	int num_especie,data;
	char nome_cientifico[30],nome_popular[30],descricao[500],caminho_foto[255];

}ESPECIES;


typedef struct {

	int num_individuo,compr,larg,peso,data;
	char local[50];

}CAPTURA;
