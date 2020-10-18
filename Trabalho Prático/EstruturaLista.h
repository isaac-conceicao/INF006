#include <stdlib.h>
#include <stdio.h>

#define TAM 100
#define SUCESSO 1
#define FALHA_ABRIR_ARQUIVO 2
#define FALHA_ALOCACAO 3
#define ARQUIVO_VAZIO 4
#define LISTA_VAZIA 5
#define FALHA_INSERIR 6

typedef struct no{
	char nome[TAM];
	float tamanho;
	int peso;
	int gc;
	struct no* prox;
}Celula;

int inserirNoInicio (Celula* inicio,  Celula* no);
int inserirNoFim (Celula* inicio, Celula* no);
int inserirPorNome (Celula* inicio,  Celula* no);
int inserirPorTamanho (Celula* inicio,  Celula* no);
int inserirPorPeso (Celula* inicio,  Celula* no);
int inserirPorGC (Celula* inicio,  Celula* no);
int ordenarPorNome (Celula* inicio, int tamanho);
int ordenarPorTamanho (Celula* inicio, int tamanho);
int ordenarPorPeso (Celula* inicio, int tamanho);
int ordenarPorGC (Celula* inicio, int tamanho);
int encontraValor(char str[], char linha[], int posicao);
int converteLinha (Celula* no,char* linha);
int extrairDados (Celula* inicio, int* tamanhoArquivo);
int buscarPorNome (Celula* inicio, char* nome);
int buscarPorTamanho (Celula* inicio, float tamanho);
int buscarPorPeso (Celula* inicio, int peso);
int buscarPorGC (Celula* inicio, int GC);
