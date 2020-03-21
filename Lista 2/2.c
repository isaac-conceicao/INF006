#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *anterior;
	struct no *proximo;
};

typedef struct no No;

No *criar(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		return NULL;

	inicio->anterior = NULL;
	inicio->proximo = NULL;

	return inicio;
}

void main(){

	No *inicio = criar();

	
}

