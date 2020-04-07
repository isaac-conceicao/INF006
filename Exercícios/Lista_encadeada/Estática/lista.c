#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct lista{

	int qtd; // vai servir para se mover dentro do vetor
	int dados[MAX];
};

typedef struct lista Lista;

// A lista foi criada dessa forma, para que depois 
// possa ser usada a funcao libera lista
Lista* criarLista(){

	Lista *inicio = (Lista*)malloc(sizeof(Lista));

	if (inicio != NULL)
		inicio->qtd = 0;

	return inicio;
}

void main(){

	
} 
