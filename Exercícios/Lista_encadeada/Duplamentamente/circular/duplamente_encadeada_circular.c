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

	return 1;

 }

 int inserirOrdenado(No **inicio, int valor){

 	if (inicio == NULL)
 		return 0;

 	No *novo = (No*)malloc(sizeof(No));

 	if (novo == NULL)
 		return 0;

 	novo-conteudo = valor;

 	if ((*inicio) == NULL){ // Lista vazia, então insere no inicio

 		*inicio = novo;
 		novo->anterior = NULL;
 		novo->proximo = novo;

 		return 1;
 	
 	}else{

 		if ((*lista)->conteudo > valor){ // encontrou no inicio

 			No *atual = *inicio;

 			while(atual->proximo != (*lista)) // procura o último
 				atual = atual->proximo;

 			novo->anterior = atual->proximo;
 			novo->proximo = *lista;
 			atual->proximo = novo;

 			*lista = novo;

 			return 1;
 		}

 		No *ant = *inicio;
 		No *atual = (*inicio)->proximo;

 		while(atual != (*inicio) && atual->conteudo < valor){

 			ant = atual;
 			atual = atual->proximo;
 		}

 		ant->proximo = novo;
 		novo->anterior = ant;
 		novo->proximo = atual;

 		return 1;
 	}

 	return 0;

 }

 void main(){


 }