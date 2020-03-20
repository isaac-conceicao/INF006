#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *anterior;
	struct no *proximo;
};

typedef struct no No;

No *criarLista(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		return NULL;

	inicio->anterior = NULL;
	inicio->proximo = inicio;

	return inicio;
}

int 


void main(){


}