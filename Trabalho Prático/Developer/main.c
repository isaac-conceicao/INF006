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


int encontraValor(char str[], char linha[], int posicao) {
	int i;

	for(i = 0; linha[posicao] != ';' && linha[posicao] != '\0'; i++, posicao++) { 
		str[i] = linha[posicao];
	}

	str[i++] = '\0';
	posicao++;

	return posicao;
}


// Funcionando, mas faltam as validações.
int converteLinha(Celula *inicio, char linha[]){
	int i;
	int j = 0;

	char nomeLP[TAM];
	char tamanho[TAM];
	char peso[TAM];
	char GC[TAM];

	// Encontra nome do LP
	j = encontraValor(nomeLP, linha, j);
	
	// Encontra o tamanho
	j = encontraValor(tamanho, linha, j);
	

	// // Encontra o Peso
	j = encontraValor(peso, linha, j);
	
	// // Encontra o GC
	j = encontraValor(GC, linha, j);
	

	// Armazena a string na struct
	strcpy(inicio->nomeLP, nomeLP);
	// Converte para Float
	inicio->tamanho = atof(tamanho);
	// Converte para Int
	inicio->peso = atoi(peso);
	inicio->GC = atoi(GC);

	// Impressoes
	printf("nomeLP: %s \n", inicio->nomeLP);
	printf("Tamanho: %f \n", inicio->tamanho);
	printf("Peso: %d \n", inicio->peso);
	printf("GC: %d \n", inicio->GC);

	return SUCESSO;
	
}

int inseriOrdenadoPeso(Celula *inicio, int peso) {
	if(inicio == NULL)
		return ESTRUTURA_INEXISTENTE;

	Celula *novo = (Celula*)malloc(sizeof(Celula));
	if(novo == NULL)
		return SEM_MEMORIA;

}

// Modelo
// int inserirOrdenado(int valor){

// 	Node *novo = (Node*)malloc(sizeof(Node));

// 	novo->conteudo = valor;

// 	if (cabeca == NULL){

// 		novo->proximo = novo;
// 		novo->anterior = novo;

// 		cabeca = novo;
// 		rabo = novo;

// 		return 1;
	
// 	}else{

// 		if (cabeca->conteudo > valor){

// 			novo->proximo = cabeca;
// 			novo->anterior = rabo;
			
// 			cabeca->anterior = novo;
// 			rabo->proximo = novo;

// 			cabeca = novo;
// 			rabo = novo;

// 			return 1;
		
// 		}else{

// 			Node *atual = cabeca;
// 			Node *ant = atual;

// 			do{
// 				ant = atual;
// 				atual = atual->proximo;
// 			}while(atual != cabeca && atual->conteudo < valor);

// 			//46
// 			//5
// 			novo->proximo = atual;
// 			novo->anterior = atual->anterior;
// 			atual->anterior = novo;
// 			ant->proximo = novo;

// 			return 1;
// 		}
// 	}

// 	return 0;
// }

int main() {

	char str[TAM] = "Fortaleza;1210.3;5;21";
	Celula *no = (Celula*)malloc(sizeof(Celula));

	converteLinha(no, str);

}