#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 100
#define SUCESSO 1
#define FALHA_ABRIR_ARQUIVO 2
#define FALHA_ALOCACAO 3
#define ARQUIVO_VAZIO 4
#define LISTA_VAZIA 5
#define FALHA_INSERIR 6

typedef struct no{
	char nomeLP[TAM];
	float tamanho;
	int peso;
	int gc;
	struct no* prox;
}Celula;

// GC
Celula* sortedMerge(Celula *a, Celula *b);
void frontBackSplit(Celula *source,
                    Celula **frontRef, Celula **backRef);

void mergeSort(Celula *inicio) {
    Celula *head = inicio;
    Celula *a;
    Celula *b;

    // Caso tamanho 0 ou 1
    if(head == NULL || head->prox == NULL) {
        return;
    }

    frontBackSplit(head, &a, &b);

    mergeSort(a);
    mergeSort(b);

    inicio = sortedMerge(a, b);
}

Celula *sortedMerge(Celula *a, Celula *b) {
    Celula *result = NULL;

    if(a == NULL)
        return (b);
    else if(b = NULL)
        return (a);

    // Compara GC
    if(a->gc <= b->gc) {
        result = a;
        result->prox = sortedMerge(a->prox, b);
    } else {
        result = b;
        result->prox = sortedMerge(a, b->prox);
    }
    return (result);
}

void frontBackSplit(Celula *source,
                    Celula **frontRef, Celula **backRef) 
{
    Celula *fast;
    Celula *slow;

    slow = source;
    fast = source->prox;

    while(fast != NULL) {
        fast = fast->prox;
        if(fast != NULL) {
            slow = slow->prox;
            fast = fast->prox;
        }
    }

    *frontRef = source;
    *backRef = slow->prox;
    slow->prox = NULL;

}









int main() {
    Celula *inicio = NULL;

    mergeSort(inicio);

    return 0;
}