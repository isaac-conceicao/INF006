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

int buscar(Lista *inicio, int valor){

	if (inicio == NULL) // Não existe lista
		return 0;

	if (inicio->proximo == NULL) // A lista está vazia, não há o que buscar
		return 0;

	Lista *busca = inicio->proximo;

	while (busca != NULL){

		if (busca->conteudo == valor){

			printf("\nAchei\n");
			break;
		}

		busca = busca->proximo;
	}
}

int removerValor(Lista *inicio, int valor){

	if (inicio == NULL || inicio->proximo == NULL)
		return 0;

	Lista *atual = inicio->proximo;

	while (atual != NULL && atual->conteudo != valor) // Buscando valor, do inicio até o final da lista
		atual = atual->proximo;

	if (atual == NULL) // Valor nao foi encontrado
		return 0;

	if (atual->anterior == NULL) // Remove do início
		inicio->proximo = atual->proximo;
	else
		atual->anterior->proximo = atual->proximo; // Se existir alguém antes dele

	if (atual->proximo != NULL) // Se ele não for o último
		atual->proximo->anterior = atual->anterior;

	free(atual);

	return 1;

}	

void listarInicioFim(Lista *inicio){

	Lista *atual = inicio->proximo;

	while (atual != NULL){
		printf("-> %d", atual->conteudo);
		atual = atual->proximo;
	}

	printf("\n");
}

void listarFimInicio(Lista *inicio){

	Lista *atual = inicio->proximo;

	while (atual->proximo != NULL) // Encontrando o último
		atual = atual->proximo;

	while (atual != NULL){ // Imprimindo do Final para o início
		printf("-> %d", atual->conteudo);
		atual = atual->anterior;
	}

	printf("\n");
}

void display(Lista *inicio){

	if (inicio == NULL || inicio->proximo == NULL)
		return;

	listarInicioFim(inicio);

	listarFimInicio(inicio);
	
}






void main(){

	Lista *inicio = criarLista();

	inserirOrdenado(inicio, 5);
	inserirOrdenado(inicio, 2);
	inserirOrdenado(inicio, 3);
	inserirOrdenado(inicio, 8);
	inserirOrdenado(inicio, 4);
	display(inicio);
	removerValor(inicio, 8);
	display(inicio);
	
}