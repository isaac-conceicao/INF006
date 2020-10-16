#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAM 100
#define SUCESSO 1
#define FALHA_ABRIR_ARQUIVO 2
#define FALHA_ALOCACAO 3
#define ARQUIVO_VAZIO 4

typedef struct no{
	char nomeLP[TAM];
	float tamanho;
	int peso;
	int GC;
	struct no* prox;
}Celula;


int converteLinha(Celula *inicio, char linha[]){
	int i;
	int j = 0;

	char nomeLP[TAM];
	char tamanho[TAM];
	char peso[TAM];
	char GC[TAM];


	// Essa funcao pode ser melhorada
	// Os fors podem virar funcoes que recebam string e inteiros.

	// Encontra nome do LP
	for(i = 0; linha[j] != ';'; i++, j++) { 
		nomeLP[i] = linha[j];
	}

	nomeLP[i++] = '\0';
	j++;
	
	// Encontra o tamanho
	for(i = 0; linha[j] != ';'; i++, j++) {
		tamanho[i] = linha[j];
	}

	tamanho[i++] = '\0';
	j++;

	// Encontra o Peso
	for(i = 0; linha[j] != ';'; i++, j++) {
		peso[i] = linha[j];
	}

	peso[i++] = '\0';
	j++;


	// Encontra o GC
	// ATENCAO '\0' deve ser substituido por '\n' quando for usar arquivo.
	for(i = 0; linha[j] != ';' && linha[j] != '\0'; i++, j++) {
		GC[i] = linha[j];
	}

	GC[i++] = '\0';

	// Conversoes

	strcpy(inicio->nomeLP, nomeLP);
	// Converte para Float
	inicio->tamanho = atof(tamanho);
	// Converte para Int
	inicio->peso = atoi(peso);
	inicio->GC = atoi(GC);

	printf("nomeLP: %s \n", inicio->nomeLP);
	printf("Tamanho: %f \n", inicio->tamanho);
	printf("Peso: %d \n", inicio->peso);
	printf("GC: %d \n", inicio->GC);
	
}

int main() {

	char str[TAM] = "Fortaleza;1210.3;5;21";
	Celula *no = (Celula*)malloc(sizeof(Celula));

	converteLinha(no, str);

}