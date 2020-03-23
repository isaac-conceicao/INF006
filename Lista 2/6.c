#include <stdio.h>
#include <stdlib.h>


/*
Objetivos: 

- Criar duas pilhas, cada uma esta ordenada de forma ordenada
- Desempilhar e colocar de forma decrescente em uma terceira pilha

Como fazer:

- Crio a estrtutura de uma pilha
- push
- pop
 */ 

struct node{

	int conteudo;
	struct node *proximo;
};

typedef node Node;

Node *criarPilha(){

	Node *pilha = (Node*)malloc(sizeof);

	if (pilha == NULL)
		return NULL;

	pilha->proximo == NULL;

	return pilha;
}

int vazia(Node *pilha){

	if (pilha->proximo == NULL)
		return 1;

	return 0;
}

int cheia(Node **pilha){

	if ((*pilha) == NULL)
		return 1;

	return 0;
}

int empilha(Node *pilha, int valor){

	if (pilha == NULL) // Pilha nao existe
		return 0;

	if (cheia(pilha)) // Pilha cheia
		return 0;

	Node *novo = (Node*)malloc(sizeof(Node));

	if (novo == NULL) // Memória nao alocada
		return 0;

	novo->conteudo = valor;
	novo->proximo = NULL;

	if (pilha->proximo == NULL){ // Pilha Vaiza, entao insira no inicio
		
		pilha->proximo = novo;
		return 1;
	}

	// Se não estiver vazia, insira na última posicao
	
	Node *ultimo = inicio->proximo;

	while (ultimo->proximo != NULL)
		ultimo = ultimo->proximo;

	ultimo->proximo = novo; // novo passa a ser o último

}

void main(){


}