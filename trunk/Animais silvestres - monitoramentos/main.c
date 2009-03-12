#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char c;
  FILE *fpl, *fpe;
  fpl=fopen("arq1.txt","r");
  if (fpl==NULL) {
    printf("Arquivo de entrada nao existe ou sem premissao de leitura.\n");
    return -1;
  }
  fpe=fopen("arq2.txt","w");

  while (fscanf(fpl,"%c",&c)!=EOF) { fprintf(fpe,"%c",c); }


  fclose(fpl);
  fclose(fpe);

  return 0;
}
