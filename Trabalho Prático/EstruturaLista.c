#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "EstruturaLista.h"

int inserirNoInicio (Celula *inicio,  Celula *no){
	//insere um novo registro no inicio da lista
  int retorno=FALHA_INSERIR;
	//testar se a lista estah vazia
	if (inicio==NULL){
		//inserir no inicio
		inicio=no;
		no->prox=NULL;
		
		retorno=SUCESSO;
	}else{
    //inserir no inicio
    no->prox=inicio;
    inicio=no;
    retorno=SUCESSO;
  }
  return retorno;
}

int inserirNoFim (Celula *inicio, Celula *no){
	int retorno=FALHA_INSERIR;
	//testar se a lista estah vazia
	if (inicio==NULL){
		inserirNoInicio(inicio,no);
		retorno=SUCESSO;
	}else{
		Celula* busca=inicio;
		//buscar o fim da lista
		while(busca->prox!=NULL){
			busca=busca->prox;
		}
		//inserir
		busca->prox=no;
		no->prox=NULL;
		
		retorno=SUCESSO;
	}
	return retorno;
}

int inserirPorNome (Celula *inicio,  Celula *no){
	//insere ordenado por nome
  int retorno=FALHA_INSERIR;
	//testar se a lista estah vazia
	if (inicio==NULL){
		inserirNoInicio(inicio,no);		
		retorno=SUCESSO;
	}else{
    int comp=1;
    Celula* busca=inicio->prox;
    Celula* anterior=inicio;
    while((busca!=NULL)&&(comp=1)){
      comp=strcmp(no->nome,busca->nome);
      anterior=busca;
      busca=busca->prox;
    }
    anterior->prox=no;
    no->prox=busca;
    retorno=SUCESSO;
  }
  return retorno;
}

int inserirPorTamanho (Celula *inicio,  Celula *no){
	//insere ordenado por tamanho
  int retorno=FALHA_INSERIR;
	//testar se a lista estah vazia
	if (inicio==NULL){
		inserirNoInicio(inicio,no);		
		retorno=SUCESSO;
	}else{
    Celula* busca=inicio->prox;
    Celula* anterior=inicio;
    while((busca!=NULL)&&(no->tamanho>busca->tamanho)){
      anterior=busca;
      busca=busca->prox;
    }
    anterior->prox=no;
    no->prox=busca;
    retorno=SUCESSO;
  }
  return retorno;
}

int inserirPorPeso (Celula *inicio,  Celula *no){
	//insere ordenado por peso
   int retorno=FALHA_INSERIR;
	//testar se a lista estah vazia
	if (inicio==NULL){
		inserirNoInicio(inicio,no);		
		retorno=SUCESSO;
	}else{
    Celula* busca=inicio->prox;
    Celula* anterior=inicio;
    while((busca!=NULL)&&(no->peso>busca->peso)){
      anterior=busca;
      busca=busca->prox;
    }
    anterior->prox=no;
    no->prox=busca;
    retorno=SUCESSO;
  }
  return retorno;
}

int inserirPorGC (Celula *inicio,  Celula *no){
	//insere ordenado por GC
   int retorno=FALHA_INSERIR;
	//testar se a lista estah vazia
	if (inicio==NULL){
		inserirNoInicio(inicio,no);		
		retorno=SUCESSO;
	}else{
    Celula* busca=inicio->prox;
    Celula* anterior=inicio;
    while((busca!=NULL)&&(no->gc>busca->gc)){
      anterior=busca;
      busca=busca->prox;
    }
    anterior->prox=no;
    no->prox=busca;
    retorno=SUCESSO;
  }
  return retorno;
}


// Merge Sort em desenvolvimento na pasta Developer

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

int encontraValor(char str[], char linha[], int posicao) {
	int i;

	for(i = 0; linha[posicao] != ';' && linha[posicao] != '\n'; i++, posicao++) { 
		str[i] = linha[posicao];
	}

	if(posicao == 0) {
		return LISTA_VAZIA;
	}

	str[i++] = '\0';
	posicao++;

	return posicao;
}


// Funcionando
// VALIDAÇÕES
/*
	[x] - Lista Vazia
	[ ] - Lista sem nome
	[ ] - Lista sem tamanho
	[ ] - Lista sem peso
	[ ] - Lista sem gc
*/
int converteLinha(Celula *no, char linha[]){
	int i;
	int j = 0;

	char nome[TAM];
	char tamanho[TAM];
	char peso[TAM];
	char gc[TAM];

	// Encontra nome do LP
	j = encontraValor(nome, linha, j);
	
	if(j == LISTA_VAZIA)
		return LISTA_VAZIA;

	// Encontra o tamanho
	j = encontraValor(tamanho, linha, j);
	
	// // Encontra o Peso
	j = encontraValor(peso, linha, j);
	
	// // Encontra o GC
	j = encontraValor(gc, linha, j);
	
	// Armazena a string na struct
	strcpy(no->nome, nome);
	// Converte para Float
	no->tamanho = atof(tamanho);
	// Converte para Int
	no->peso = atoi(peso);
	no->gc = atoi(gc);

	// Impressoes
	// printf("nome: %s \n", inicio->nome);
	// printf("Tamanho: %f \n", inicio->tamanho);
	// printf("Peso: %d \n", inicio->peso);
	// printf("GC: %d \n", inicio->gc);

	return SUCESSO;
}

int extrairDados(Celula *inicio, int *tamanhoArquivo) {
	char linha[TAM];
	Celula *no = NULL;
	int retorno=SUCESSO;
	FILE *arquivo;
	*tamanhoArquivo=0;
	//printf("Abrindo arquivo...\n"); 
	arquivo = fopen("maDados.txt", "r");
	//testa se arquivo abriu
	if(arquivo==NULL){
		retorno=FALHA_ABRIR_ARQUIVO;
	//testa se o arquivo esta vazio
	}else if (feof(arquivo)){
		retorno=ARQUIVO_VAZIO;
	}else{
		while(!feof(arquivo)){
			*tamanhoArquivo+=1;
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

int buscarPorNome(Celula* inicio, char* nome, Celula* resultado){
	int retorno=SUCESSO;
	Celula* busca=inicio;
  
  //verifica se a lista está vazia
  if(inicio==NULL){
    retorno = LISTA_VAZIA;
    resultado=NULL;
  }else{
    //busca enquanto lista não acaba ou acha o 1º nome correspondente
    while((busca!=NULL)&&(strcmp(nome,busca->nome)!=0)){
      busca=busca->prox;
    }
    resultado=busca;
    //verifica se a busca reotrnou nulo
    if (resultado==NULL){
      retorno = NAO_ENCONTRADO;
    }
  }
	return retorno;
}

int buscarPorTamanho(Celula* inicio, float tamanho, Celula* resultado){
	int retorno=SUCESSO;
	Celula* busca=inicio;
  
  //verifica se a lista está vazia
  if(inicio==NULL){
    retorno = LISTA_VAZIA;
    resultado=NULL;
  }else{
    //busca enquanto lista não acaba ou acha o 1º tamanho correspondente
    while((busca!=NULL)&&(busca->tamanho!=tamanho)){
      busca=busca->prox;
    }
    resultado=busca;
    //verifica se a busca reotrnou nulo
    if (busca==NULL){
      retorno = NAO_ENCONTRADO;
    }
  }
	return retorno;
}

int buscarPorPeso(Celula* inicio, int peso, Celula* resultado){
	int retorno=SUCESSO;
	Celula* busca=inicio;
  
  //verifica se a lista está vazia
  if(inicio==NULL){
    retorno = LISTA_VAZIA;
    resultado=NULL;
  }else{
    //busca enquanto lista não acaba ou acha o 1º peso correspondente
    while((busca!=NULL)&&(busca->peso!=peso)){
      busca=busca->prox;
    }
    resultado=busca;
    //verifica se a busca reotrnou nulo
    if (busca==NULL){
      retorno = NAO_ENCONTRADO;
    }
  }
	return retorno;
}

int buscarPorGC(Celula* inicio, int gc, Celula* resultado){
	int retorno=SUCESSO;
	Celula* busca=inicio;
  
  //verifica se a lista está vazia
  if(inicio==NULL){
    retorno = LISTA_VAZIA;
    resultado=NULL;
  }else{
    //busca enquanto lista não acaba ou acha o 1º GC correspondente
    while((busca!=NULL)&&(busca->gc!=gc)){
      busca=busca->prox;
    }
    resultado=busca;
    //verifica se a busca reotrnou nulo
    if (busca==NULL){
      retorno = NAO_ENCONTRADO;
    }
  }
	return retorno;
}

void imprimeLista(Celula* inicio){
  //testa se a lista esta vazia
  if(inicio==NULL)
    printf("!ERRO_LISTA_VAZIA!");
  else{
    Celula* busca=inicio;
    while(busca!=NULL){
      printf("%s;%.2f;%d;%d\n",busca->nome,busca->tamanho,busca->peso,busca->gc);
      system("PAUSE");
    }
  }
}

void destruirLista(Celula* inicio){
  Celula* anterior;
  
  while(inicio!=NULL){
    anterior=inicio;
    inicio=inicio->prox;
    free(anterior);
  }
}
