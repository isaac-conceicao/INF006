#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *anterior;
	struct no*proximo;
};

typedef struct no No;

No *criar(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		return NULL;

	return inicio;
}

int inserirInicio(No **inicio, int valor){

	if (inicio == NULL)
		return 0;

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return 0;

	novo->conteudo = valor;

	if (*inicio == NULL){ // se a lista estiver vazia
		
		*inicio = novo;
		novo->anterior = NULL;
		novo->proximo = novo;
	
	}else{

		No *aux = *inicio;

		while(aux->proximo != (*inicio)) // enquanto auxiliar proximor for diferente do endereco do inicio;
			aux = aux->proximo;

		aux->anterior = aux; // antes de encontrar o primeiro, ele encontrou o último, que é aux
		aux->prox = novo; // quando encontrou o endereco do inicio, ele substituiu por novo
		novo->proximo = *inicio; // novo proximo aponta para o endereco do antigo inicio, que aponta para o restante da lista

		*inicio = novo; // novo passa a ser o primeiro da lista
	}


 }

 void main(){

 	
 }