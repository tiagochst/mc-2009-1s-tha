#define IND_ESPC "\nPor favor,entre com o indentificador unico da especie:  "
#define IND_INDIV "\nPor favor,entre com o indentificador unico do individuo:  "
#define IND_SEX "\nPor favor,entre com o sexo:  "
#define ERRO_ARQ "Arquivo de entrada nao existe ou sem premissao de leitura.\n"

#define OPT_IND "Opcoes de tarefas relacionada aos dados de individuos:\n -Ver todos os individuos listados (L)\n -Inserir novo individuo(I)\nPor favor faça sua escolha: "

typedef struct {

  int num_especie,num_individuo;
  char sexo;

}INDIVIDUOS;


