#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCHAR 50

/*	
	[X] Contruir a estrutura
	[ ] Abrir o arquivo
	[ ] Separar os parâmetros
	[ ] Buscar antes de inserir
	[ ] Inserir no Inicio
	[ ] Inserir no Meio
	[ ] Inserir no Final
	[ ] Inserir Ordenado(em qualquer local);
	[ ] Remover (em qualquer local);
	[ ] Busca na lista;
*/


// Estrutura 
typedef struct Celula {
	char nomeLP[TAMCHAR];
	char peso[TAMCHAR];
	char tamNovo[TAMCHAR];
	char gc[TAMCHAR];

	struct Celula *prox;
} Celula;


// FUNCOES

Celula* criarListaCabeca(){

	Celula *inicio = (Celula*)malloc(sizeof(Celula));

	if (inicio == NULL)
		return NULL;

	inicio->prox = NULL;
	return inicio;
}



void lerLinha(Celula *no) {
	FILE *arquivo;
	arquivo = fopen("GeradorMassaDados.c", "r");

	if(arquivo) {
		while(!feof(arquivo)) {

		}

		fclose(arquivo);

	} else {
		printf("Erro ao Abrir o arquivo");
	}
}

int converterLinha(Celula *no, FILE *arquivo) {
	char linha[TAM];
	int retorno=0;
	
	if(arquivo==NULL){
		retorno=FALHA_ABRIR_ARQUIVO;
	}
	
	if(!feof(arquivo)){
			fgets(linha,TAM,arquivo);
			//substring
			//converter substring p/ os tipos
			//alocar nó
			//atribuir dados convertidos ao nó 
			retorno=SUCESSO;
		}
	} else {
		printf("FIM DE ARQUIVO");
		retorno=FIM_DO_ARQUIVO;
	}
	return retorno;
}

void inserirFinal(Celula *lista, char *valor){

	Celula *tmp;
	Celula *novo;

	novo = (Celula*)malloc(sizeof(Celula));


	if (novo == NULL)
		return ;

	strcpy(novo->peso, valor);
	novo->prox = NULL;

	if (lista->prox == NULL)
		lista->prox = novo;

	else{

		tmp = lista->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}


}

int main() {

	Celula *inicio = NULL;
	
	lerLinha(inicio);
	

}

