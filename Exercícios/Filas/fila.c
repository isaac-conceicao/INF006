#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{

	int idade;
	char nome[20+1];
	struct Pessoa *prox;
};

typedef struct Pessoa *Posicao;

void iniciar(Posicao *fila){ // INICIA FILA

	*fila = NULL;
}

void inserir(Posicao *fila, int idade, char *nome){

	if(*fila == NULL){
		
		*fila = (Posicao) malloc(sizeof(Posicao));

		if(*fila == NULL)
			return ;

		(*fila)->idade = idade;
		strcpy((*fila)->nome, nome);
		(**fila).prox = NULL;

	}else
		inserir(& (**fila).prox, idade, nome);
}

void apagar (Posicao *fila){

	Posicao *tmp = fila;

	if (*fila == NULL) // NÃO EXISTEM ELEMENTOS
		return ;

	*fila = (*fila)->prox;
	free(tmp);
}

void listar(Posicao fila){ // LISTA TODOS OS ELEMENTOS RECURSIVAMENTE

	if (fila == NULL)
		return ;

	printf("%d %s \n", fila->idade, fila->nome);

	listar(fila->prox); // LISTA OS DEMAIS;
}

void main(){

	Posicao f;

	iniciar(&f);
	puts("iniciar:");
	listar(f);
	puts("inserir: ");
	inserir(&f, 10, "Tiago");
	inserir(&f, 20, "Luisa");
	inserir(&f, 30, "Ana");
	puts("Listar 3");
	listar(f);
	apagar(&f);
	puts("Listar 2");
	listar(f);
	apagar(&f);
	puts("Listar 1");
	listar(f);
	apagar(&f);
	puts("Listar Nada");
	listar(f);
	apagar(&f);
	puts("Listar Naada");
	listar(f);
}