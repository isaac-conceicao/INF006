#include <stdio.h>
#include <stdlib.h>

#define TAMCHAR 50

/*	
	[X] Contruir a estrutura
	[ ] Abrir o arquivo
	[ ] 
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

int lerLinha(Celula *no) {
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

int inserirNaLista(int valor){ //a função recebe apenas o valor que quero inserir na lista
  
    Celula *n;

    n = (Celula*) malloc(sizeof(Celula*));

    if(n == NULL)
        return 0;
    
    n->tamNovo = valor;
    n->proximo = NULL;

    if(inicio == NULL){
        inicio = n;
     }
 }


int main() {

	Celula *inicio = NULL;
	
	lerLinha(inicio);
	

}

