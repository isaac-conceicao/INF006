#include <stdio.h>
#include <stdlib.h>

#define n1 3
#define n2 7

void main(){

	int *pValor;

	// INICIANDO ALOCAÇÃO DE MEMÓRIA
	pValor = (int*)malloc(n1*sizeof(int));
	 
	int i;

	for (i = 0; i < n1; i++){
		printf("Digite o %d° numeor: ", i+1);
		scanf("%d", &pValor[i]);
	}

	// REALOCANDO MEMÓRIA
	pValor = (int*)realloc(pValor,n2*sizeof(int));

	for (i = n1; i < (n1 + n2); i++){
		printf("Digite o %d° numeoro: ", i+1);
		scanf("%d", &pValor[i]);
	}

	printf("\n");

	for (i = 0; i < (n1 + n2); i++)
		printf("%d ", pValor[i]);


}

