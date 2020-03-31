/*

- Lista Duplamente encadeada
- Insere na lista já ordenado

 */

#include <stdio.h>
#include <stdlib.h>

struct lista{

	int conteudo;
	struct lista *anterior;
	struct lista *proximo;
};

typedef struct lista Lista;

Lista* criarLista(){

	Lista *inicio = (Lista*)malloc(sizeof(Lista));

	if (inicio == NULL)
		return NULL;

	inicio->anterior = NULL;
	inicio->proximo = NULL;

	return inicio;
}

int inserirFinal(Lista *inicio, int valor){

	if (inicio == NULL) // Se a lista nao existir, saia
		return 0;

	Lista *novo = (Lista*)malloc(sizeof(Lista)); // Alocando memória para novo

	if (novo == NULL) // Se não conseguir alocar memória, saia
		return 0;

	novo->conteudo = valor;
	
	if (inicio->proximo == NULL){ // Se a lista estiver vazia, insira no inicio
		novo->proximo = NULL;
		novo->anterior = NULL; // inicio->proximo aponta para NULL

		inicio->proximo = novo; // inicio->proximo passa a  ser o novo elemento
		return 1;
	}

	Lista *ultimo = inicio->proximo;

	while (ultimo->proximo != NULL) // Buscando o último elemento 
		ultimo = ultimo->proximo;

	novo->anterior = ultimo;
	novo->proximo = NULL;

	ultimo->proximo = novo;

	return 1;
}

int inserirOrdenado (Lista *inicio, int valor){

	if (inicio == NULL) // Lista nao existe
		return 0;

	Lista *novo = (Lista*)malloc(sizeof(Lista));

	if (novo == NULL) // Não conseguiu alocar memória
		return 0;

	novo->conteudo = valor;

	if (inicio->proximo == NULL){ // Lista está vazia, entao o novo será o primeiro e único elemento
		
		novo->proximo = NULL;
		novo->anterior = NULL;

		inicio->proximo = novo;
		return 1;
	}
	
	Lista *atual = inicio->proximo;
	Lista *anterior = atual;
	
	// Se o primeiro elemento da lista for maior que o novo valor,
	// o novo valor vem antes do primeiro elemento
	if (atual->conteudo > valor){ 

		novo->proximo = atual;
		novo->anterior = NULL;

		atual->anterior = novo;
		inicio->proximo = novo;

		return 1;
	}

	while (atual != NULL && atual->conteudo < valor){
		anterior = atual;
		atual = atual->proximo;
	}

	// Se atual é diferente de NULL, é por quê ele encontrou algum elemento que é maior que o novo valor,
	//  o novo valor passa a ocupar uma posicao antes desse elemento 
	if (atual != NULL){

		novo->proximo = atual;
		novo->anterior = anterior;

		atual->anterior = novo;
		anterior->proximo = novo;

		return 1;
	}

	// Se ele não encontrou na lista nenhum elemento maior que o novo valor, o novo valor passa a ser o último
	novo->proximo = NULL;
	novo->anterior = anterior;

	anterior->proximo = novo;
	return 1;
}

void display(Lista *inicio){

	Lista *atual = inicio->proximo;

	// Imprimindo do Inicio para o Final
	while (atual != NULL){
		printf("-> %d", atual->conteudo);
		atual = atual->proximo;
	}

	printf("\n"); // Quebra de linha

	atual = inicio->proximo;

	// Procuando o Ultimo elemento
	while(atual->proximo != NULL) 
		atual = atual->proximo;

	// Imprindo do Final para o Inicio
	while (atual != NULL ){ 
		printf("-> %d", atual->conteudo);
		atual = atual->anterior;
	}

	printf("\n"); // Quebra de linha
}

void main(){

	Lista *inicio = criarLista();

	inserirOrdenado(inicio, 5);
	inserirOrdenado(inicio, 2);
	inserirOrdenado(inicio, 3);
	inserirOrdenado(inicio, 8);
	inserirOrdenado(inicio, 4);
	
	display(inicio);
	
}