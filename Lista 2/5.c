/*

LIFO -  Last in first out
o último a ser inserido, será o primeiro a ser retirado.

Objetivo: 

Usar pilha para verificar se uma palavra é um palíndromo

dica:

uma parte da palavra será empilhada e comparada a outra parte da palavra, ainda, observar que
palavras com tamanho par tem tratamento um pouco diferente de palavras de tamanho
impar.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pilha;
int topo = -1;


void push(char ele){

	pilha[++topo] = ele;
}

char pop(){

	return pilha[topo--];
}

int ehPalindromo(char str[]){

	int tamanho = strlen(str);

	// Alocando a memoria para pilha
	pilha = (char*)malloc(tamanho * sizeof(char));

	// Encontrando o meio
	int meio = tamanho / 2;
	int i;

	for (i = 0; i < meio; i++)
		push(str[i]);

	// Checando se o tamanho da string é impar, se impar
	// negligencia o meio do caractere
	if (tamanho % 2 != 0)
		i++;

	char elemento;

	//while nao encontra o fim da string
	while(str[i] != '\0'){

		elemento = pop();

		if (elemento != str[i])
			return 0;

		i++;
	}

	return 1;
}

void main(){

	char str[] = "raiar";

	if (ehPalindromo(str))
		printf("\nSim\n");

	else
		printf("\nNao\n");
}
