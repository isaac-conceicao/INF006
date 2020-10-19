#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "EstruturaLista.h"

void menu(){
  //imprime menu
}

int main(void) {
  printf("Hello World\n");
  
  Celula* inicio=NULL;
  int tamanhoArquivo=0;
  int retorno;
  
  retorno=extrairDados(inicio, &tamanhoArquivo);
  imprimeLista(inicio);
  destruirLista(inicio);
  
  return retorno;
}