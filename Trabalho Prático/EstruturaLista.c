#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "EstruturaLista.h"

int inserirNoInicio (Celula *inicio,  Celula *novo){
	//insere um novo registro no inicio da lista
}

int inserirNoFim (Celula *inicio, Celula *novo){
	//insere um novo registro no fim da lista
}

int inserirPorNome (Celula *inicio,  Celula *novo){
	//insere ordenado por nome
}

int inserirPorTamanho (Celula *inicio,  Celula *novo){
	//insere ordenado por tamanho	
}

int inserirPorPeso (Celula *inicio,  Celula *novo){
	//insere ordenado por peso
}

int inserirPorGC (Celula *inicio,  Celula *novo){
	//insere ordenado por peso
}

int ordenarPorNome(Celula *inicio, int tamanho){
	int retorno=SUCESSO;
	//ordena a lista por nome
	return retorno;
}

int ordenarPorTamanho(Celula *inicio, int tamanho){
	int retorno=SUCESSO;
	//ordena a lista por tamanho
	return retorno;
}

int ordenarPorPeso(Celula *inicio, int tamanho){
	int retorno=SUCESSO;
	//ordena a lista por peso
	return retorno;
}

int ordenarPorGC(Celula *inicio, int tamanho){
	int retorno=SUCESSO;
	//ordena a lista por GC
	return retorno;
}

int converteLinha(no,linha){
	int i;
	int j = 0;

	char nomeLP[TAM];
	char tamanho[TAM];
	char peso[TAM];
	char GC[TAM];

	// Encontra nome do LP
	for(i = 0; linha[j] != ';'; i++, j++) { 
		nomeLP[i] = linha[j];
	}

	nomeLP[i++] = '\0';
	
	// Encontra o tamanho
	for(i = 0; linha[j] != ';'; i++, j++) {
		tamanho[i] = linha[j];
	}

	tamanho[i++] = '\0';	

	// Encontra o Peso
	for(i = 0; linha[j] != ';'; i++, j++) {
		peso[i] = linha[j];
	}

	peso[i++] = '\0';

	// Encontra o GC
	for(i = 0; linha[j] != ';'; i++; j++) {
		GC[i] = linha[j];
	}

	GC[i++] = '\0';

	// Converte para Float
	no.tamanho = strof(tamnho); // solucao Temporaria, preciso testar essa funcao

	// Converte para Int
	no.peso = atoi(peso);
	no.GC = atoi(GC);
	
}

int extrairDados(Celula *inicio, int *tamanhoArquivo) {
	char linha[TAM];
	Celula *no = NULL;
	int retorno=SUCESSO;
	FILE *arquivo;
	 
	arquivo = fopen("GeradorMassaDados.c", "r");
	//testa se arquivo abriu
	if(arquivo==NULL){
		retorno=FALHA_ABRIR_ARQUIVO;
	//testa se o arquivo esta vazio
	}else if (arquivo==feof){
		retorno=ARQUIVO_VAZIO;
	}else{
		while(!feof(arquivo)){
			fgets(linha,TAM,arquivo);
			no=(Celula*)malloc(sizeof(Celula));
			//testa alocacao
			if(no==NULL){
				retorno=FALHA_ALOCACAO;
			}else{
				no->prox=NULL;
				//converter linha
				retorno=converteLinha(no,linha);
				//testa conversao da linha
				if(retorno==SUCESSO)
					//insere na lista
					retorno=inserirNoFim(inicio, no);
				else{
					free(no);
					break;
				}
			}
		}
	}
	return retorno;
}

int buscarPorNome(Celula* inicio, char *nome){
	int retorno=SUCESSO;
	//
	return retorno;
}

int buscarPorTamanho(Celula* inicio, float tamanho){
	int retorno=SUCESSO;
	//
	return retorno;
}

int buscarPorPeso(Celula* inicio, int peso){
	int retorno=SUCESSO;
	//
	return retorno;
}

int buscarPorGC(Celula* inicio, int GC){
	int retorno=SUCESSO;
	//
	return retorno;
}
