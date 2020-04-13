#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct paciente{
	char nome[30];
	int prio;
};

struct fila_prioridade{
	int qtd;
	struct paciente dados[MAX];
};

typedef struct fila_prioridade filaPrio;

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

	fp->qtd --;

	return 1;
}

void main(){

}