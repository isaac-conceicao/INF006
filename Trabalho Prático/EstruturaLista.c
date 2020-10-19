#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "EstruturaLista.h"

int ligado = SHOW_LOG;
void show_log(char *str){
    if (ligado)
        printf("##%s##\n", str);
}

//insere um novo registro no inicio da lista
int inserirNoInicio (Celula *inicio,  Celula *no){
  show_log("inserirNoInicio()");
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
  show_log("inserirNoFim()");
	int retorno=FALHA_INSERIR;
	//testar se a lista estah vazia
	if (inicio==NULL){
		retorno=inserirNoInicio(inicio,no);
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
  show_log("inserirPorNome()");
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
  show_log("inserirPorTamanho()");
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
	show_log("inserirPorPeso()");
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
	show_log("inserirPorGC()");
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
	show_log("ordenarPorNome()");
  int retorno=SUCESSO;
	//ordena a lista por nome
  mergeSortNome(inicio);
  

	return retorno;
}

int ordenarPorTamanho(Celula *inicio, int tamanho){
	show_log("ordenarPorTamanho()");
  int retorno=SUCESSO;
	//ordena a lista por tamanho
  mergeSortTamanho(inicio);
	return retorno;
}

int ordenarPorPeso(Celula *inicio, int tamanho){
	show_log("ordenarPorPeso()");
  int retorno=SUCESSO;
	//ordena a lista por peso
  mergeSortPeso(inicio);
	return retorno;
}

int ordenarPorGC(Celula *inicio, int tamanho){
	show_log("ordenarPorGC()");
  int retorno=SUCESSO;
	//ordena a lista por GC
  mergeSortGC(inicio);

	return retorno;
}

int encontraValor(char str[], char linha[], int posicao) {
	show_log("encontraValor()");
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
	show_log("converteLinha()");
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
	// printf("nome: %s \n", no->nome);
	// printf("Tamanho: %f \n", no->tamanho);
	// printf("Peso: %d \n", no->peso);
	// printf("GC: %d \n", no->gc);

	return SUCESSO;
}

int extrairDados(Celula *inicio, int *tamanhoArquivo) {
	show_log("extrairDados()");
  char linha[TAM];
	Celula *no = NULL;
	int retorno=SUCESSO;
	FILE *arquivo;
	*tamanhoArquivo=0;
  show_log("Abrindo maDados.txt..."); 
	arquivo = fopen("maDados.txt", "r");
	//testa se arquivo abriu
	if(arquivo==NULL){
    show_log("ERRO_FALHA_ABRIR_ARQUIVO");
		retorno=FALHA_ABRIR_ARQUIVO;
	//testa se o arquivo esta vazio
	}else if (feof(arquivo)){
    show_log("ERRO_ARQUIVO_VAZIO");
		retorno=ARQUIVO_VAZIO;
	}else{
		while(!feof(arquivo)){
			*tamanhoArquivo+=1;
      show_log("Lendo linha %d...");
			fgets(linha,TAM,arquivo);
			no=(Celula*)malloc(sizeof(Celula));
			//testa alocacao
			if(no==NULL){
        show_log("ERRO_FALHA_ALOCACAO");
				retorno=FALHA_ALOCACAO;
			}else{
				no->prox=NULL;
        //converter linha
        show_log("Convertendo linha...");
				retorno=converteLinha(no,linha);
				//testa conversao da linha
				if(retorno==SUCESSO){
					show_log("Linha convertida com sucesso!");
          //insere na lista
          show_log("Linha convertida com sucesso!");
				  retorno=inserirNoFim(inicio, no);
          //se a inserção falhar destruir a lista toda
          if(retorno==FALHA_INSERIR){
            show_log("ERRO_FALHA_INSERIR");
            destruirLista(inicio);
            free(no);
            break;
          }
        }
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
	show_log("buscarPorNome()");
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
	show_log("buscarPorTamanho()");
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
	show_log("buscarPorPeso()");
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
	show_log(" buscarPorGC()");
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
  show_log("imprimeLista()");
  int* x;
  //testa se a lista esta vazia
  if(inicio==NULL)
    show_log("ERRO_LISTA_VAZIA");
  else{
    Celula* busca=inicio;
    while(busca!=NULL){
      printf("%s;%.2f;%d;%d\n",busca->nome,busca->tamanho,busca->peso,busca->gc);
      scanf("%d",x);
    }
  }
}

void destruirLista(Celula* inicio){
  show_log("destruirLista()");
  Celula* anterior;
  //checar se a lista exite
  if(inicio==NULL){
    show_log("ERRO_LISTA_VAZIA");
  }else{
    while(inicio!=NULL){
      anterior=inicio;
      inicio=inicio->prox;
      free(anterior);
    }
  }
}


// MergeSort Nome
Celula *sortedMergeNome(Celula *a, Celula *b) {
    Celula *result = NULL;

    if(a == NULL)
        return (b);
    else if(b = NULL)
        return (a);

    // Compara Nome
    if(strcmp(a->nome, b->nome) <= 0) {
        result = a;
        result->prox = sortedMergeNome(a->prox, b);
    } else {
        result = b;
        result->prox = sortedMergeNome(a, b->prox);
    }
    return (result);
}

void frontBackSplitNome(Celula *source,
                    Celula **frontRef, Celula **backRef) 
{
    Celula *fast;
    Celula *slow;

    slow = source;
    fast = source->prox;

    while(fast != NULL) {
        fast = fast->prox;
        if(fast != NULL) {
            slow = slow->prox;
            fast = fast->prox;
        }
    }

    *frontRef = source;
    *backRef = slow->prox;
    slow->prox = NULL;

}

void mergeSortNome(Celula *inicio) {
    Celula *head = inicio;
    Celula *a;
    Celula *b;

    // Caso tamanho 0 ou 1
    if(head == NULL || head->prox == NULL) {
        return;
    }

    frontBackSplitNome(head, &a, &b);

    mergeSortNome(a);
    mergeSortNome(b);

    inicio = sortedMergeNome(a, b);
}

// MergeSort Tamanho
Celula *sortedMergeTamanho(Celula *a, Celula *b) {
    Celula *result = NULL;

    if(a == NULL)
        return (b);
    else if(b = NULL)
        return (a);

    // Compara Tamanho
    if(a->tamanho <= b->tamanho) {
        result = a;
        result->prox = sortedMergeTamanho(a->prox, b);
    } else {
        result = b;
        result->prox = sortedMergeTamanho(a, b->prox);
    }
    return (result);
}

void frontBackSplitTamanho(Celula *source,
                    Celula **frontRef, Celula **backRef) 
{
    Celula *fast;
    Celula *slow;

    slow = source;
    fast = source->prox;

    while(fast != NULL) {
        fast = fast->prox;
        if(fast != NULL) {
            slow = slow->prox;
            fast = fast->prox;
        }
    }

    *frontRef = source;
    *backRef = slow->prox;
    slow->prox = NULL;

}

void mergeSortTamanho(Celula *inicio) {
    Celula *head = inicio;
    Celula *a;
    Celula *b;

    // Caso tamanho 0 ou 1
    if(head == NULL || head->prox == NULL) {
        return;
    }

    frontBackSplitTamanho(head, &a, &b);

    mergeSortTamanho(a);
    mergeSortTamanho(b);

    inicio = sortedMergeTamanho(a, b);
}

// MergeSort Peso
Celula *sortedMergePeso(Celula *a, Celula *b) {
    Celula *result = NULL;

    if(a == NULL)
        return (b);
    else if(b = NULL)
        return (a);

    // Compara Peso
    if(a->peso <= b->peso) {
        result = a;
        result->prox = sortedMergePeso(a->prox, b);
    } else {
        result = b;
        result->prox = sortedMergePeso(a, b->prox);
    }
    return (result);
}

void frontBackSplitPeso(Celula *source,
                    Celula **frontRef, Celula **backRef) 
{
    Celula *fast;
    Celula *slow;

    slow = source;
    fast = source->prox;

    while(fast != NULL) {
        fast = fast->prox;
        if(fast != NULL) {
            slow = slow->prox;
            fast = fast->prox;
        }
    }

    *frontRef = source;
    *backRef = slow->prox;
    slow->prox = NULL;

}

void mergeSortPeso(Celula *inicio) {
    Celula *head = inicio;
    Celula *a;
    Celula *b;

    // Caso tamanho 0 ou 1
    if(head == NULL || head->prox == NULL) {
        return;
    }

    frontBackSplitPeso(head, &a, &b);

    mergeSortPeso(a);
    mergeSortPeso(b);

    inicio = sortedMergePeso(a, b);
}







// MergeSort GC
Celula *sortedMergeGC(Celula *a, Celula *b) {
    Celula *result = NULL;

    if(a == NULL)
        return (b);
    else if(b = NULL)
        return (a);

    // Compara GC
    if(a->gc <= b->gc) {
        result = a;
        result->prox = sortedMergeGC(a->prox, b);
    } else {
        result = b;
        result->prox = sortedMergeGC(a, b->prox);
    }
    return (result);
}

void frontBackSplitGC(Celula *source,
                    Celula **frontRef, Celula **backRef) 
{
    Celula *fast;
    Celula *slow;

    slow = source;
    fast = source->prox;

    while(fast != NULL) {
        fast = fast->prox;
        if(fast != NULL) {
            slow = slow->prox;
            fast = fast->prox;
        }
    }

    *frontRef = source;
    *backRef = slow->prox;
    slow->prox = NULL;

}

void mergeSortGC(Celula *inicio) {
    Celula *head = inicio;
    Celula *a;
    Celula *b;

    // Caso tamanho 0 ou 1
    if(head == NULL || head->prox == NULL) {
        return;
    }

    frontBackSplitGC(head, &a, &b);

    mergeSortGC(a);
    mergeSortGC(b);

    inicio = sortedMergeGC(a, b);
}

