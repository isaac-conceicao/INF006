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

typedef struct node Node;

Node *criarPilha();
int vazia(Node *pilha);
int cheia(Node **pilha);
int empilha(Node *pilha, int valor);
char desempilha(Node *pilha);
int tamanhoVetor(int vet[]);
int tamanhoVetor(int vet[]);
Node* ordenarDecrescente(int A[], int B[]);

void main(){

	int num1[] = {1, 2, 3};
	int num2[] = {4,5,6};

	Node *pilha = ordenarDecrescente(num1, num2);


}

Node *criarPilha(){

	Node *pilha = (Node*)malloc(sizeof(Node));

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

// Pilha está cheia quando nao tiver mais memória disponível
int cheia(Node **pilha){ 

	if ((*pilha) == NULL)
		return 1;

	return 0;
}

// Insere no Final
int empilha(Node *pilha, int valor){

	if (pilha == NULL) // Pilha nao existe
		return 0;

	if (cheia(&pilha)) // Pilha esta cheia
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
	
	Node *ultimo = pilha->proximo;

	while (ultimo->proximo != NULL)
		ultimo = ultimo->proximo;

	ultimo->proximo = novo; // novo passa a ser o último

}

// retiro do final
char desempilha(Node *pilha){

	if (pilha == NULL) // Pilha nao existe
		return 0;

	if (vazia(pilha))
		return 0;

	Node *ultimo = pilha->proximo;
	Node *penultimo = ultimo;

	while(ultimo->proximo != NULL){
		penultimo = ultimo;
		ultimo = ultimo->proximo;
	}

	penultimo->proximo = NULL;

	int valor = ultimo->conteudo;

	free(ultimo);
	return valor;
}

int tamanhoVetor(int vet[]){

	int tamanho = sizeof(*vet) / sizeof(int);

	return tamanho;
}

Node* ordenarDecrescente(int A[], int B[]){

	Node *p1 = criarPilha(); // Pilha 1
	Node *p2 = criarPilha(); // Pilha 2
	
	if (vazia(p1) || vazia(p2))
		return 0;

	Node *p3 = criarPilha(); // Pilha 3

	int i = 0;
	while (i < tamanhoVetor(A)){ // Empilhando valores do vetor A na Pilha 1
		empilha(p1, A[i]);
		i ++;
	}

	i = 0;
	while (i < tamanhoVetor(B)){ // Empilhando valores do vetor B na Pilha 2
		empilha(p2, B[i]);
		i++;
	}

	int tamanho = tamanhoVetor(A) + tamanhoVetor(B); 

	p3 = (Node*)realloc(p3, tamanho * sizeof(Node));

	int x, y;

	i = 0;
	while (i < tamanho){

		x = desempilha(p1);
		y = desempilha(p2);

		if (x > y)
			p3[i].conteudo = x;
			
		else
			p3[i].conteudo = y;

		i++;
	}

	return p3;
}