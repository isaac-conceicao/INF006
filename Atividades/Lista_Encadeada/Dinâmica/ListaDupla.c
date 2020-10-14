/**************************************************/
/*  Autor: Felipe Andrade                         *
/*                                                */
/*  araujoandrade.flp@gmail.com                   */
/*                                                */
/*  Data: 19/09/12 11:15                          */
/*                                                */
/*  Descrição: Lista duplamente encadeada         */
/*                                                */
/**************************************************/


#include <stdio.h>
#include <stdlib.h>

struct no{

	int conteudo;
	struct no *anterior;
	struct no *proximo;
};

typedef struct no No; // Definicao do tipo No apartir do tipo struct no

void inserirInicio(No **inicio, int valor){

	No *novo;

	novo = (No*)malloc(sizeof(No)); // Aloca Memória para o novo nó

	if (novo == NULL) // Se não houver memória disponível
		return ; // Sai da Funcao

	novo->conteudo = valor; // Insere o valor no novo nó

	if (*inicio == NULL){ // Se lista estiver vazia
		
		novo->anterior = NULL; // Não há anterior
		novo->proximo = NULL; // Não há próximo

		*inicio = novo;
	
	}else{ // Se já existia nó na lista

		novo->anterior = NULL; // Não há anterior
		novo->proximo = *inicio; // O novo nó aponta para o que está no início
		(*inicio)->anterior = novo; // o nó atual do início aponta para o novo nó
		*inicio = novo; // O novo nó passa a ser o primeiro da lista
	}
}

void inserirFinal(No **inicio, int valor){

	No *novo;
	No *atual;

	novo = (No*)malloc(sizeof(No));

	if (novo == NULL)
		return;

	novo->conteudo = valor;

	if (*inicio == NULL){

		novo->anterior = NULL;
		novo->proximo = NULL;

		*inicio = novo;
	
	}else{

		atual = *inicio; // atual aponta para o início

		while (atual->proximo != NULL) // Enquanto o nó atual não for o último
			atual = atual->proximo; // Vai para o nó seguinte

		novo->anterior = atual; // O nó anterior ao novo é o nó atual
		novo->proximo = NULL; // Não há próximo nó, pois o novo será o ultimo
		atual->proximo = novo; // O nó atual aponta para o novo nó e não é mais o último
	}
}

// Remove um nó escolhido pelo usuário
int remover(No **inicio, int valor){

	No *temporario;
	No *atual;

	if (*inicio == NULL)
		return 0; // retorna 0 caso a lista esteja vazia

	if ((*inicio)->conteudo == valor) // caso o nó a ser retirado seja o do inicio
		*inicio = (*inicio)->proximo; // o nó inicial passa a ser o próximo da lista

	atual = *inicio; // o nó atual é o do início

	while (atual != NULL && atual->conteudo != valor) // Se há nó e o valor do mesmo não é o valor que se quer retirar
		atual = atual->proximo; // passa a ser  o próximo

	if (atual == NULL)
		return 0; // retorna 0 se não encontrou o valor

	// caso tenha encontrado
	else{

		temporario = atual; // temporario aponta para o nó encontrado

		if (atual->anterior != NULL) // caso haja um nó anterior ao encontrado
			atual->anterior->proximo = atual->anterior; // faz o nó posterior apontar para o nó anterior ao encontrado

		free(temporario); // remove o nó encontrado
	} 

	return 1;
}

// deleta um nó apartir do inicio da lista
int eliminaNo(No **inicio){

	No *temporario;
	int x;

	temporario = *inicio; // nó do início passa a ser temporário
	x = (*inicio)->conteudo; // pega o valor que estava no nó
	*inicio = (*inicio)->proximo; // o nó seguinte passa a ser o do inicio

	free(temporario); // deleta o nó temporário

	return x;
}

int estaVazia(No *lista){

	return lista == NULL;
}

void imprimeListaOrdemDireta(No *lista){

	if (estaVazia(lista))
		printf("\n\n A lista esta vazia \n\n");

	else{

		printf("\nA lista eh: \n\n");
		while (lista != NULL){
			printf(" %d", lista->conteudo);
			lista = lista->proximo;
		}
	}
}

void imprimeListaOrdemInversa(No *lista){

	if (estaVazia(lista))
		printf("\n\nA lista esta vazia \n\n");

	else{
		while (lista->proximo != NULL) // enquanto não chegar no último nó...
			lista = lista->proximo; // ...percorre a lista

		printf("\nA lista eh: \n\n");
		while (lista != NULL){
			printf(" %d", lista->conteudo);
			lista = lista->anterior;
		}
	}
}

void menu(){

	printf("         <---------> OPERACOES BASICAS EM UMA LISTA DUPLAMENTE ENCADEADA <------>\n\n");
	printf("\n\n\t\t\t\t OPCOES \n\n");
	printf("\t\t1 - Inserir um elemento no inicio da lista\n");
	printf("\t\t2 - Inserir um elemento no final da lista\n");
	printf("\t\t3 - Remover um elemento da lista\n");
	printf("\t\t4 - Imprimir a lista na ordem direta\n");
	printf("\t\t5 - Imprimir a lista na ordem inversa\n");
	printf("\t\t6 - Sair\n\n");
}


void main(){

	No *lista = NULL; // inicia a lista

	int opcao;
	int valor;

	menu();
	printf("Escolha uma das opcoes: ");
	scanf("%d", &opcao);

	while (opcao != 6){

		switch(opcao){

			case 1:{

				printf("\nDigite um valor: ");
				scanf("%d", &valor);
				inserirInicio(&lista, valor);
				system("clear");
				break;
			}

			case 2:{

				printf("\nDigite um valor: ");
				scanf("%d", &valor);
				inserirFinal(&lista, valor);
				system("clear");
				break;
			}

			case 3:{

				printf("\nDigite o valor a ser retirado: ");
				scanf("%d", &valor);

				if (! remover(&lista, valor))
					printf("\nNo inexistente! \n\n");

				system("clear");
				break;
			}

			case 4:{

				imprimeListaOrdemDireta(lista);
				system("clear");
				break;
			}

			case 5:{

				imprimeListaOrdemInversa(lista);
				system("clear");
				break;
			}

			default:{

				printf("\nOpcao Invalida!!! \n\n");
				system("clear");
				break;
			}
		}

		menu();
		printf("Escolha uma das opcoes: ");
		scanf("%d", &opcao);
	}

	printf("\nLimpando a lista ... \n\n");
	while(! estaVazia(lista)) // retira todos os nós não apagados para liberar a memoria
		printf("No %d retirado\n", eliminaNo(&lista));

	printf("\nLista vazia\n"); 
}