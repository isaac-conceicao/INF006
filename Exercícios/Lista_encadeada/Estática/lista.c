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

int inserirInicio(Lista* li, int valor){

	if (li == NULL)
		return 0;

	int i;

	for (i = li->qtd-1; i >= 0; i--) 
		li->dados[i+1] = li->dados[i];

	li->dados[0] = valor;

	li->qtd ++;
	return 1;
}

int inserirOrdenado(Lista* li, int valor){

	if (li == NULL)
		return 0;

	int i, j;
	i = 0;

	while(i < li->qtd && li->dados[i] < valor)
		i++;

	for (j = li->qtd-1; j >= i; j--)
		li->dados[j+1] = li->dados[j];

	li->dados[i] = valor;

	li->qtd ++;
	return 1;

}

void exibirLista(Lista* li){

	if (li == NULL || li->qtd == 0)
		return;

	int i;

	for (i = 0; i < li->qtd; i++)
		printf("-> %d", li->dados[i]);

	printf("\n");
}

void main(){

	Lista *li = criarLista(); 

	inserirInicio(li, 1);
	inserirInicio(li, 7);
	exibirLista(li);
	inserirOrdenado(li, 2);
	exibirLista(li);

} 
