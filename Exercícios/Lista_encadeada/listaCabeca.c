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

int remover(No *lista, int valor){

	if (lista == NULL) // Não existe lista
		return 0;

	if (lista->prox == NULL) // lista está vazia, não tem o que remover
		return 0;

	No *busca, *anterior;

	busca = lista->prox;
	anterior = NULL;

	while (busca != NULL){

		if (busca->conteudo == valor){

			if (anterior == NULL) // Esta no inicio da lista
				lista->prox = busca->prox;
			else
				anterior->prox = busca->prox;

			free(busca);
		}

		anterior = busca;
		busca = busca->prox;
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

	printf("\n");
	remover(inicio, 7);
	listarLista(inicio);


}