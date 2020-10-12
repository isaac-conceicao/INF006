#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 7

/*
	Fila = Primeiro a entrar Primeiro a sair.

	Fila de Prioridade Crescente = O elemento com maior prioridade estará no final da fila.

 */


struct paciente{
	char nome[30];
	int prio;
};

struct fila_prioridade{
	int qtd;
	struct paciente dados[MAX];
};

typedef struct fila_prioridade FilaPrio;

FilaPrio* criaFilaPrio();
void liberaFilaPrio(FilaPrio *fp);
int insereFilaPrio(FilaPrio *fp, char *nome, int prioridade);
int removeFilaPrio(FilaPrio *fp);
int tamanhoFilaPrio (FilaPrio *fp);
int estaCheiaFilaPrio(FilaPrio *fp);
int estaVaziaFilaPrio(FilaPrio *fp);
void imprimeFilaPrio (FilaPrio *fp);

void main(){

	struct paciente itens[6] = {{"Andre",1},
                                {"Bianca",2},
                                {"Carlos",5},
                                {"Nilza",10},
                                {"Inacio",9},
                                {"Edu",2}};

    FilaPrio* fp;
    fp = criaFilaPrio();

    int i;
    for (i=0; i< 6; i++){
        printf("%d) %d %s\n",i,itens[i].prio, itens[i].nome);
        insereFilaPrio(fp, itens[i].nome,itens[i].prio);
    }

    printf("=================================\n");

    imprimeFilaPrio(fp);

    printf("=================================\n");
    for (i=0; i< 6; i++){
        removeFilaPrio(fp);
        imprimeFilaPrio(fp);
        printf("=================================\n");
    }

    liberaFilaPrio(fp);

}

FilaPrio* criaFilaPrio(){

	FilaPrio *fp = (FilaPrio*)malloc(sizeof(FilaPrio));

	if (fp == NULL)
		return NULL;

	fp->qtd = 0;

	return fp;
}

void liberaFilaPrio(FilaPrio *fp){

	free(fp);
}

int insereFilaPrio(FilaPrio *fp, char *nome, int prioridade){

	if (fp == NULL)
		return 0;
	if (fp->qtd == MAX) // Lista Cheia
		return 0;

	int i = fp->qtd-1;
	while( i>= 0 && fp->dados[i].prio >= prioridade){
		fp->dados[i+1] = fp->dados[i];
		i--;
	}

	strcpy(fp->dados[i+1].nome, nome);
	fp->dados[i+1].prio = prioridade;

	fp->qtd ++;

	return 1;
}

int removeFilaPrio(FilaPrio *fp){
	if (fp == NULL)
		return 0;

	if (fp->qtd == 0)
		return 0;

	fp->qtd --; // Remocao Lógica

	return 1;
}

int tamanhoFilaPrio (FilaPrio *fp){
	if (fp == NULL)
		return -1;
	else
		return fp->qtd;
}

int estaCheiaFilaPrio(FilaPrio *fp){
	if (fp == NULL)
		return -1;
	
	return (fp->qtd == MAX);
}

int estaVaziaFilaPrio(FilaPrio *fp){
	if (fp == NULL)
		return -1;

	return (fp->qtd == 0);
}

void imprimeFilaPrio (FilaPrio *fp){

	if (fp == NULL)
		return ;
	
	int i;

	for (i = fp->qtd-1; i>= 0; i--)
		printf("Prio: %d \tNome: %s\n", fp->dados[i].prio, fp->dados[i].nome);
}
