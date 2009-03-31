#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include "funcoes.c"

void inserir_individuos(FILE * fpe); 
void ler_individuos(FILE * fpe); 
void menu_upd_ind();
void upd_ind(FILE * fpe);
void remover_especies(FILE * fpe);


void inserir_especies(FILE * fpe); 
void ler_especies(FILE * fpe); 
void menu_upd_esp();
void upd_esp(FILE * fpe);
void remover_individuos(FILE * fpe);

void remover_captura(FILE * fpe);
void inserir_captura(FILE * fpe); 
void ler_captura(FILE * fpe); 


int verif_especies(FILE * fpe,int procura_esp);
#endif
