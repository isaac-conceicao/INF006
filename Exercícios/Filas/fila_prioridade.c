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



void main(){

}