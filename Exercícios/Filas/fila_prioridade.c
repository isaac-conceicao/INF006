#include <stdio.h>
#include <stdlib.h>

#define MAX 3

/*
	Fila = Primeiro a entrar Primeiro a sair.

	Fila de Prioridade Crescente = Oelemento com maior prioridade estará no final da fila.

 */


struct paciente{
	char nome[30];
	int prio;
};

struct fila_prioridade{
	int qtd;
	struct paciente dados[MAX];
};

typedef struct fila_prioridade filaPrio;

filaPrio* criarFilaPrio();
void liberaFilaPrio(filaPrio *fp);
int insereFilaPrio(filaPrio *fp, char nome, int prioridade);
int removeFilaPrio(filaPrio *fp);
int tamanhoFilaPrio (filaPrio *fp);
int estaCheiaFilaPrio(filaPrio *fp);
int estaVaziaFilaPrio(filaPrio *fp);
void imprimeFilaPrio (filaPrio *fp);

void main(){

}

filaPrio* criarFilaPrio(){

	filaPrio *fp = (filaPrio*)malloc(sizeof(filaPrio));

	if (fp == NULL)
		return NULL;

	fp->qtd = 0;

	return fp;
}

void liberaFilaPrio(filaPrio *fp){

	free(fp);
}

int insereFilaPrio(filaPrio *fp, char nome, int prioridade){

	if (fp == NULL)
		return 0;
	if (fp->qtd == MAX) // Lista Cheia
		return 0;

	int i = fp->qtd-1;
	while( i>= 0 && fp->prio >= prioridade){
		fp->dados[i+1] = fp->dados[i];
		i--;
	}

	strcpy(fp->dados[i+1].nome, nome);
	fp->dados[i+1].prio = prioridade;

	fp->qtd ++;

	return 1;
}

int removeFilaPrio(filaPrio *fp){
	if (fp == NULL)
		return 0;

	if (fp->qtd == 0)
		return 0;

	fp->qtd --; // Remocao Lógica

	return 1;
}

int tamanhoFilaPrio (filaPrio *fp){
	if (fp == NULL)
		return -1;
	else
		return fp->qtd;
}

int estaCheiaFilaPrio(filaPrio *fp){
	if (fp == NULL)
		return -1;
	
	return (fp->qtd == MAX);
}

int estaVaziaFilaPrio(filaPrio *fp){
	if (fp == NULL)
		return -1;

	return (fp->qtd == 0);
}

void imprimeFilaPrio (filaPrio *fp){

	if (fp == NULL)
		return ;
	
	int i;

	for (i = fp->qtd-1; i>= 0; i--)
		printf("Prio: %d \tNome: %s\n", fp->dados[i].prio, fp->dados[i].nome);
}
