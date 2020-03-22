#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int conteudo;
	struct node *anterior;
	struct node *proximo;
};

typedef struct node Node;


// funcao de inserir no final
int inserirFim(No** inicio, int valor){

	if (inicio == NULL) // lista nao existe
		return 0;

	Node *novo = (Node*)malloc(sizeof(No));
	
	if (novo == NULL)
		return 0;

	novo->conteudo = valor;
	
	//se lista esta vazia, crie um unico nó
	if (*inicio == NULL){

		novo->anterior = novo;
		novo->proximo = novo;

		*inicio = novo;

		return 1;
	}

	// if lista nao estiver vazia
	
	// encontre o ultimo nó
	Node *ultimo = (*inicio)->anterior;

	// fazendo com que o proximo de novo, recebe o atual inicio
	novo->proximo = *inicio;

	// anterior do inicio, recebe novo
	(*inicio)->anterior = novo;

	// fazendo de novo anterior, o antigo ultimo
	novo->anterior = ultimo;

	// fazendo com que proximo do novo, se torne o antigo ultimo
	ultimo->proximo = novo;

	return 1;
}

int inserirInicio(Node ** inicio, int valor){

	if (inicio == NULL)
		return 0;

	Node *novo = (Node*)malloc(sizeof(Node));

	if (novo == NULL)
		return 0;

	novo->conteudo = valor;

	// ponteiro de ponteiro para o ultimo nó
	Node *ultimo = (*inicio)->anterior;

	// estabelecendo anterior e proximo de novo nó
	novo->proximo = *inicio;
	novo->anterior = ultimo;

	// atualizando anteriores e proximos ponteiros de inicio e ultimo
	ultimo->proximo = novo;
	(*inicio)->anterior = novo;

	// atualizando ponteiro de inicio
	*inicio = novo;

	return 1;
}

int inserirListaOrdenada(Node** inicio, int valor){

	if (inicio == NULL) // nao existe lista
		return 0;

	Node *novo = (Node*)malloc(sizeof(No));

	if (novo == NULL) // nao foi possivel alocar memoria
		return 0;

	novo->conteudo = valor;

	Node *ant = (*inicio);
	Node *atual = (*inicio)->proximo;

	while(atual != (*inicio) && atual->conteudo < valor){
		ant = atual;
		atual = atual->proximo;
	}

	ant->proximo = novo;
	novo->proximo = atual
	novo->anterior = ant->proximo;

	return 1;

}