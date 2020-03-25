/*

Checklist

- Criacao de uma fila circular, usando lista encadeada. - completo
- Fila 1 responsável pelas posicoes (0 - 9)
- Fila 2 responsável pelas posicoes (10 - 19)

Obs: Teria sido melhor usar uma fila estática, mas ainda não sei tornar ela circular.
 */


#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *proximo;
};

typedef struct no No;

No* criaFila();
int insereFinal(No **fila, int valor);
int removeInicio(No **fila);
int removeValor(No **fila, int valor);
void liberaFila(No** fila);
void imprimefila(No **fila);

void main(){
	
	
}

No* criaFila(){

	No *inicio = (No*)malloc(sizeof(No));

	if (inicio == NULL)
		return NULL;

	return inicio;
}

int insereFinal(No **fila, int valor){

	if (fila == NULL) // nao existe fila
		return 0;

	No *novo = (No*)malloc(sizeof(No));

	if (novo == NULL) // sem espaco na memoria
		return 0;

	novo->conteudo = valor;

	if ((*fila) == NULL){ // fila vazia: insere inicio
		
		*fila = novo;
		novo->proximo = novo; // já que ele é o único na fila, ele vai apontar para ele mesmo		
	
	}else{

		No *aux = *fila;

		while(aux->proximo != (*fila))
			aux = aux->proximo;

		aux->proximo = novo;
		novo->proximo = *fila;
	}

	return 1;
}

int removeInicio(No **fila){

	if (fila == NULL)
		return 0;

	if ((*fila) == (*fila)->proximo){ // fila fica vazia

		free(*fila);
		*fila = NULL;

		return 1;
	}

	No *atual = *fila;

	while(atual->proximo != (*fila)) // procura o ultimo
		atual = atual->proximo;

	No *novo = *fila;
	atual->proximo = novo->proximo;
	*fila = novo->proximo;

	free(novo);

	return 1;
}

int removeValor(No **fila, int valor){

	if (fila == NULL || (*fila) == NULL)
		return 0;

	No *novo = *fila;

	if (novo->conteudo == valor){ // remover do inicio 

		if (novo == novo->proximo){ // fila fica vazia
			free(novo);

			*fila = NULL;

			return 1;

		}else{

			No *ultimo = *fila;

			while (ultimo->proximo != (*fila)) // procura o ultimo
				ultimo = ultimo->proximo;

			ultimo->proximo = (*fila)->proximo;
			*fila = (*fila)->proximo;

			free(novo);

			return 1;
		}
	}

	No *anterior = novo;
	novo = novo->proximo;

	while (novo != (*fila) && novo->conteudo != valor){

		anterior = novo;
		novo = novo->proximo;
	}

	if (novo == *fila) // nao encontrado
		return 0;

	anterior->proximo = novo->proximo;

	free(novo);

	return 1;
}

void liberaFila(No** fila){

	if (fila != NULL && (*fila) != NULL){

		No *aux, *no = *fila;

		while ((*fila) != no->proximo){

			aux = no;
			no = no->proximo;

			free(aux);
		}

		free(no);
		free(fila);
	}
}

void imprimefila(No **fila){

	if (fila == NULL || (*fila) == NULL)
		return;

	No *atual = *fila;

	do{
		printf("-> %d ", atual->conteudo);
		atual = atual->proximo;
	
	}while (atual != (*fila));
}