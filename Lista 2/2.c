#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *anterior;
	struct no *proximo;
};

typedef struct no No;

//criacao de uma lista com cabeca
No *criar(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		return NULL;

	inicio->anterior = NULL;
	inicio->proximo = NULL;

	return inicio;
}

int inserirInicio(No **inicio, int valor){

//inicio == pego o endereco que está armazenado em inicio
//*inicio == pego o endereco de inicio
//**inicio == pego o valor para onde inicio está apontando

	if (inicio == NULL) // não existe lista
		return 0;

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return 0;

	novo->conteudo = valor;

	if ((*inicio)->proximo == NULL){ // lista está vazia
		
		novo->anterior = (*inicio)->proximo;
		novo->proximo = novo;
		
		(*inicio)->proximo = novo;
		
	
	}else{

		No *aux = (*inicio)->proximo;

		while(aux->proximo != (*inicio)->proximo)
			aux = aux->proximo;


		aux->proximo = novo;
		novo->anterior = aux;
		novo->proximo = (*inicio)->proximo;

		(*inicio)->proximo = novo;

	}

	return 1;
}


void imprimeListaOrdemDireta(No **lista){

	if (lista == NULL || (*lista)->proximo == NULL)
		return;

	No *atual = (*lista)->proximo;

	do{
		printf("-> %d ", atual->conteudo);
		atual = atual->proximo;
	
	}while (atual != (*lista)->proximo);
}

void imprimeListaOrdemInversa(No **lista){

	if (lista == NULL || (*lista)->proximo == NULL)
		return;

	No *ultimo = (*lista)->proximo;

	while (ultimo->proximo != (*lista)->proximo)
		ultimo = ultimo->proximo;

	while(ultimo != (*lista)->proximo){
		printf(" ->%d ", ultimo->conteudo);
		ultimo = ultimo->anterior; 
	}
}

void main(){

	No *inicio = criar();

	inserirInicio(&inicio, 3);
	inserirInicio(&inicio,1);
	inserirInicio(&inicio,5);
	imprimeListaOrdemDireta(&inicio);
	imprimeListaOrdemInversa(&inicio);	

}

