#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int conteudo;
	struct node *anterior;
	struct node *proximo;	
};

typedef struct node Node;

Node *cabeca = NULL;
Node *rabo = NULL;

void inserirInicio(int valor);
void inserirFinal(int valor);
int inserirOrdenado(int valor);
int buscarValor(int valor);
void listaDireta();
void listaReversa();
void tela();

void main(){

	inserirInicio(4);
	inserirFinal(6);
	inserirOrdenado(5);
	tela();
}

void inserirInicio(int valor){

	Node *novo = (Node*)malloc(sizeof(Node));

	novo->conteudo = valor;

	if (cabeca == NULL){ // se a lista estiver vazia

		novo->proximo = novo;
		novo->anterior = novo;
		
		cabeca = novo;
		rabo = novo;
	
	}else{

		novo->proximo = cabeca;
		novo->anterior = rabo;
		
		cabeca->anterior = novo;
		rabo->proximo = novo;
		cabeca = novo;
	}
}

void inserirFinal(int valor){

	Node *novo = (Node*)malloc(sizeof(Node));

	novo->conteudo = valor;
	

	if (cabeca == NULL){

		novo->proximo = novo;
		novo->anterior = novo;
		
		cabeca = novo;
		rabo = novo;
	
	}else{

		rabo->proximo = novo;
		novo->proximo = cabeca;
		novo->anterior = rabo;
		rabo = novo;
		cabeca->anterior = rabo;
	}
}

int inserirOrdenado(int valor){

	Node *novo = (Node*)malloc(sizeof(Node));

	novo->conteudo = valor;

	if (cabeca == NULL){

		novo->proximo = novo;
		novo->anterior = novo;

		cabeca = novo;
		rabo = novo;

		return 1;
	
	}else{

		if (cabeca->conteudo > valor){

			novo->proximo = cabeca;
			novo->anterior = rabo;
			
			cabeca->anterior = novo;
			rabo->proximo = novo;

			cabeca = novo;
			rabo = novo;

			return 1;
		
		}else{

			Node *atual = cabeca;
			Node *ant = atual;

			do{
				ant = atual;
				atual = atual->proximo;
			}while(atual != cabeca && atual->conteudo < valor);

			//46
			//5
			novo->proximo = atual;
			novo->anterior = atual->anterior;
			atual->anterior = novo;
			ant->proximo = novo;

			return 1;
		}
	}

	return 0;
}

int buscarValor(int valor){

	Node* atual = cabeca;

	int achei = 0;

	if (cabeca == NULL){
		printf("\nLista Vazia: valor nao encontrado\n");
		return 0;
	}

	do{

		if (atual-> conteudo = valor){
			printf("Achei, %d encontrado\n", valor);
			achei = 1;
			return valor;
		}

		atual = atual->proximo;

	}while(atual != cabeca);

	if (achei == 0)
		printf("\nValor nao encontrado\n");

	return 0;
}

void listaDireta(){

	if (cabeca == NULL)
		return;

	Node *atual = cabeca;

	do{

		printf("-> %d", atual->conteudo);
		atual = atual->proximo;
	
	}while(atual != cabeca);
}

void listaReversa(){

	if (cabeca == NULL)
		return;

	Node *atual = rabo;

	do{

		printf("-> %d", atual->conteudo);
		atual = atual->anterior;

	}while(atual != rabo);
}

void tela(){

	printf("\nOrdem Direta:\n");
	listaDireta();

	printf("\nOrdem Reversa:\n");
	listaReversa();
}
