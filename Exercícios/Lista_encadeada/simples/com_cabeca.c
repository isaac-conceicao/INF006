#include <stdio.h>
#include <stdlib.h>

struct no {

	int conteudo;
	struct no *prox;
};

typedef struct no No;

No* criarLista();
void inserirNoFinal(No* lista, int valor);
void listarListaEncadeada(No *lista);
void inserirNoInicio(No* lista, int valor);
int tamanhoDaLista(No* lista);
void buscarNaLista(No* lista, int x);
void removerDaLista(No* lista, int x);

void main(){

	No *inicio = criarLista();

	inserirNoInicio(inicio, 8);
	inserirNoFinal(inicio, 6);
	inserirNoFinal(inicio, 1);
	inserirNoFinal(inicio, 8);
	inserirNoFinal(inicio, 9);
	listarListaEncadeada(inicio);
	buscarNaLista(inicio,8);

}

No* criarLista(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		return NULL;

	inicio->prox = NULL;

	return inicio;
}

void inserirNoInicio(No* lista, int valor){

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return ;

	novo->conteudo = valor;
	novo->prox = lista->prox;

	lista->prox = novo;
}

void inserirNoMeio(No* lista, int valor){
}

void inserirNoFinal(No* lista, int valor){

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return ;

	novo->conteudo = valor;
	novo->prox = NULL;

	if (lista->prox == NULL) // É POR QUÊ ESTÁ NO INÍCIO
		lista->prox = novo;
	
	else{

		No *atual = lista->prox;

		while (atual->prox != NULL)
			atual = atual->prox;

		atual->prox = novo;
	}
}

void buscarNaLista(No* lista, int x){

	No *busca = lista->prox;

	while (busca != NULL ){

		if (busca->conteudo == x)
			printf("\nAchei \n");
		
		busca = busca->prox;
	}
}
void removerDaLista(No* lista, int x){

	No *busca = lista->prox;
	No *anterior = NULL;

	while (busca != NULL){

		if (busca->conteudo == x){

			if (busca == lista->prox)
				lista->prox = busca->prox;
			else
				anterior->prox = busca->prox;

			free(busca);
			break;
		}

		anterior = busca;
		busca = busca->prox;
	}
}

int tamanhoDaLista(No* lista){

	No *atual = lista->prox;
	int tamanho = 0;

	while (atual != NULL){
		atual = atual->prox;
		tamanho ++;
	}

	return tamanho;
}

void listarListaEncadeada(No *lista){

	No *atual = lista->prox;

	while (atual != NULL){
		printf("-> %d ", atual->conteudo);
		atual = atual->prox;
	}
}
