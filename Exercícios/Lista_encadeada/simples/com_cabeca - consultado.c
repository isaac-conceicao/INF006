#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *prox;
};

typedef struct no No;

No* criarListaCabeca(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		return NULL;

	inicio->prox = NULL;
	return inicio;
}

void inserirFinal(No *lista, int valor){

	No *tmp;
	No *novo;

	novo = (No*)malloc(sizeof(No));


	if (novo == NULL)
		return ;

	novo->conteudo = valor;
	novo->prox = NULL;

	if (lista->prox == NULL)
		lista->prox = novo;

	else{

		tmp = lista->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}


}

void listarLista(No *lista){

	No *tmp;

	tmp = lista->prox;

	while(tmp != NULL){

		printf("-> %d ", tmp->conteudo);
		tmp = tmp->prox;
	}
}

void main(){

	No *inicio = criarListaCabeca();

	inserirFinal(inicio, 7);
	inserirFinal(inicio, 32);
	listarLista(inicio);


}