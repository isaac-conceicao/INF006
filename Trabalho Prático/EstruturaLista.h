#include <stdlib.h>
#include <stdio.h>

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
	no* prox;
}Celula;

int inserirNoInicio (Celula *inicio,  Celula *novo);
int inserirNoFim (Celula *inicio, Celula *novo);
int inserirPorNome (Celula *inicio,  Celula *novo);
int inserirPorTamanho (Celula *inicio,  Celula *novo);
int inserirPorPeso (Celula *inicio,  Celula *novo);
int inserirPorGC (Celula *inicio,  Celula *novo);
int ordenarPorNome (Celula *inicio, int tamanho);
int ordenarPorTamanho (Celula *inicio, int tamanho);
int ordenarPorPeso (Celula *inicio, int tamanho);
int ordenarPorGC (Celula *inicio, int tamanho);
int converteLinha (no,linha);
int extrairDados (Celula *inicio, int *tamanhoArquivo);
int buscarPorNome (Celula* inicio, char *nome);
int buscarPorTamanho (Celula* inicio, float tamanho);
int buscarPorPeso (Celula* inicio, int peso);
int buscarPorGC (Celula* inicio, int GC);

