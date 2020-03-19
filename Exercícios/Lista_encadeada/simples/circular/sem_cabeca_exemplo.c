#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *proximo;
};

typedef struct no No;

No* criaLista(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		retutn NULL;

	return inicio;
}

void liberaLista(No* lista){

	if (lista != NULL && (*lista) != NULL){

		No *aux, *no = *lista;

		while ((*lista) != no->proximo){

			aux = no;
			no = no->proximo;

			free(aux);
		}

		free(no);
		free(lista);
	}
}

int insereListaFinal(No *lista, int valor){

	if (lista == NULL) // nao existe lista
		return 0;

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL) // sem espaco na memoria
		return 0;

	novo->conteudo = valor;

	if ((*lista) == NULL){ // lista vazia: insere inicio
		
		*lista = novo;
		novo->proximo = novo; // já que ele é o único na lista, ele vai apontar para ele mesmo		
	
	}else{

		No *aux = *lista;

		while(aux->prox != (*lista))
			aux = aux->proximo;

		aux->proximo = novo;
		novo->proximo = *lista;
	}

	return 1;
}

int insereListaInicio(No *lista, int valor){

	if (lista == NULL) // nao existe lista
		return 0;

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return 0;

	novo->conteudo = valor;

	if ((*lista) == NULL){ // lista vazia: insere inicio
		
		*lista = novo;
		novo->proximo = novo;
	
	}else{

		No *aux = *lista;

		while(aux->proximo != (*lista)) // enquanto auxiliar próximo for diferente do endereço do inicio da lista
			aux = aux->proximo;

		aux->proximo = novo;
		novo->proximo = *lista;

		*lista = novo; // novo passa a ser o primeiro da lista;
	}

	return 1;
}

int insereListaOrdenada(No* lista, int valor){

	if (lista == NULL) // se lista nao existir
		return 0;

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return 0;

	novo->conteudo = valor;

	if ((*lista) == NULL){ // insere inicio
		
		*lista = novo;
		novo->proximo = novo;

		return 1;
	
	}else{

		if ((*lista)->conteudo > valor){ // insere início

			No* atual = *lista;

			while(atual->proximo != (*li)) // procura o último
				atual = atual->proximo;

			novo->proximo = *lista;
			atual->proximo = novo;
			*lista = novo;

			return 1;
		}

		No *ant = *lista;
		No *atual = (*lista)->proximo;

		while(atual != (*lista) && atual->conteudo < valor){

			ant = atual;
			atual = atual->prox;
		}

		ant->prox = novo;
		novo->prox = atual;

		return 1;
	}
}

void imprimeLista(No *lista){

	if (lista == NULL || (*lista) == NULL)
		return;

	No *atual = *lista;

	do{
		printf("-> %d ", atual->conteudo);
		atual = atual->proximo;
	
	}while (atual != (*lista));
}

void main(){

}