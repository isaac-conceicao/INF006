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
int liberaLista(Lista* li){

	if (li == NULL)
		return 0;

	free(li);

	return 1;
}

int inserirFinal(Lista* li, int valor){

	if (li == NULL)
		return 0;

	li->dados[li->qtd] = valor;

	li->qtd ++;
	return 1;
}

void exibirLista(Lista* li){

	if (li == NULL || li->qtd == 0)
		return;

	int i;

	for (i = 0; i < li->qtd; i++)
		printf("-> %d", li->dados[i]);

	Lista *li = criarLista(); 

	inserirFinal(li, 7);
	exibirLista(li);
}

void main(){

	
} 
