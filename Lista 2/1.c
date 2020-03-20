/* 

1- Fila Circular estática
2- O elemento que entra primeiro. sai primeiro.
3- Sempre que um elemento é adicionado a fila, ele vai para o final dela.
4- Sempre que removemos um elemento, o primeiro é removido.

FIFO - first in/ First Out

Objetivos: 

- Inserir na fila
- Pesquisar na fila
- Excluir na fila o valol pesquisado

1° fila (0 - 9)
2° fila (10 - 19)

*/
#include <stdio.h>
#include <stdlib.h>

void inicializa(int principal[], int limite){

	int i = 0;

	while (i < limite){
		principal[i] = -1;
		i++;
	}

}

int vazia(int inicio, int final){

	if (inicio == final)
		return 1;

	return 0;
}

int cheia(int inicio, int final, int limite){

	if (final-1 == limite)
		return 1;

	return 0;
}

int inserir(int fila[], int x,int inicio, int final, int limite){

	if (cheia(inicio, final, limite)){
		printf("Fila Cheia!!\n");
		return 0;
	}

	fila[final] = x;

	return 1;
}

int buscar(int fila[],int valor, int inicio, int final){

	if (vazia(inicio, final))
		return 0;

	int i = 0;
	
	while(i < final){

		if (fila[i] == valor){
			printf("Achei\n");
			return 1;
		}

		i++;
	}

	return 0;
}

int remover(int fila[], int valor, int inicio, int final){

	if (vazia(inicio, final))
		return 0;

	int i, achei = 0;
	int aux;

	if (fila[i] == valor){ // se ele estiver na primeira posicao
		
		aux = fila[i];
		fila[i] = fila[i+1];
		fila[i+1] = aux;

		achei = 1;

	}
	
	while(i < final){

		if (fila[i] == valor){
			aux = fila[i];
			fila[i] = fila[i+1];
			fila[i+1] = aux;

			achei = 1;
		}

		i++;
	}

	if (achei == 0)
		return 0;

	printf("\nValor %d removido \n", valor);
		
	return 1;
}

void listar(int fila[], int limite){

	int i = 0;

	while(i < limite){
		
		if (fila[i] != -1)
			printf("-> %d", fila[i]);
		
		i++;
	}
}


void main(){

	int primeira[10];
	int finalPrimeira = 0;

	int segunda[10];
	int finalSegunda = 0;

	int principal[20];
	int finalPrincipal = 0;
	int limitePrincipal = 20;

	int inicio, opcao = 0;
	int limite = 10;
	int valor;

	int *inicioPtr = &inicio;
	int *finalPrimeiraPtr = &finalPrimeira;
	int *finalSegundaPtr = &finalSegunda;
	int *finalPrincipalPtr = &finalPrincipal;

	inicializa(principal, limitePrincipal);

	
	do{

		printf("\n1 - Inserir \n");
		printf("2 - Buscar \n");
		printf("3 - Excluir \n");
		printf("4 - Listar \n");
		printf("5 - Sair\n\n");

		printf("Digite a sua opcao: ");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:{

				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);

				if (inserir(primeira, valor, inicio, finalPrimeira, limite)){
					principal[finalPrimeira] = primeira[finalPrimeira];
					finalPrimeira ++;
				
				}else if (inserir(segunda,valor, inicio, finalSegunda, limite)){
					principal[finalSegunda+10] = segunda[finalSegunda];
					finalSegunda ++;
				
				}else
					printf("\nLista Cheia \n\n");

				break;
			}

			case 2:{

				printf("Digite o valor a ser buscado: ");
				scanf("%d", &valor);

				if(!buscar(primeira, valor, inicio, finalPrimeira)) // se não achou na primeira lista
					if(!buscar(segunda, valor, inicio, finalSegunda)) // se nao achou na segunda lista
						printf("\nValor nao encontrado \n");
				
				break;
			}
			case 3:{

				printf("Digite o valor a ser removido: ");
				scanf("%d", &valor);

				if (remover(primeira, valor, inicio, finalPrimeira)){
					remover(principal, valor, inicio, finalPrimeira);
					finalPrimeira --;
				
				}else if(remover(segunda, valor, inicio, finalSegunda)){
					remover(principal, valor, (inicio + 10), (finalSegunda + 10));
					finalSegunda --;
				} 

				break;
			}

			case 4:{
				listar(principal, limitePrincipal);
				break;
			}

		}

	}while(opcao != 5);

}