#include <stdlib.h>
#include <stdio.h>

/*FEATURES - 
    Adicionar na lista de forma que o primeiro elemento inserido continue sendo o primeiro ...

    Adicionar função que ao inserir na lista retorna o endereço, e permite que a próxima posição seja
    inserida depois daquele endereço

    Adicionar Buscar, Remover, Listar específico, Ordenar

    Buscar elemento usando recursividade
    
    Contar elementos da lista usando recursividade
*/

typedef struct Celula{
    int conteudo;
    struct Celula *proximo;
} Celula;

Celula *inicio = NULL;

int contList(Celula *pCelula);
int inserirNaLista(int x);
void busca();
Celula *buscar_recursivo(int x, Celula *inicio);
void remover();
void printarLista();

void main(){
    int i;

    for (i=1; i<=10;i++)
        inserirNaLista(i*2); //para testar a lista vazia basta comentar aqui

    printarLista();

    buscar_recursivo(7, inicio);
    printf("%d \n", contList(inicio));
}

int contList(Celula *le){
    
    int cont = 0;

    while(le!=NULL){
        cont++;
        le = le->proximo;
    }
    return cont;
}   

int inserirNaLista(int x){ //a função recebe apenas o valor que quero inserir na lista
  
    Celula *n;

    n = (Celula*) malloc(sizeof(Celula*));

    if(n == NULL)
        return 0;
    
    n->conteudo = x;
    n->proximo = NULL;

    if(inicio == NULL){
        inicio = n;

    }else{
        n->proximo = inicio;
        inicio = n;
    }

    return 1;
}

void busca(){

  int x;
  Celula *busca = inicio;

  printf("Digite o valor a ser buscado: ");
  scanf("%d", &x);

  while(busca != NULL){

    if(busca->conteudo == x){
      printf("Achei \n");
      break;
    }

    busca = busca->proximo;
  }
}

Celula *buscar_recursivo(int x, Celula *inicio){

  if (inicio == NULL)
    return NULL;

  if (inicio->conteudo == x){
    printf("Achei \n");
    return inicio;
  }

  return buscar_recursivo(x,inicio->proximo);
}

void remover(){

  int x;

  printf("Digite o o valor a ser removido: ");
  scanf("%d", &x);

  Celula *busca = inicio;
  Celula *anterior = NULL;

  while (busca != NULL){
    if(busca -> conteudo == x){
      if (busca == inicio)
        inicio = busca->proximo;
      else
        anterior->proximo = busca->proximo;
      
      free(busca);
      break;
    }
    anterior = busca;
    busca = busca->proximo;
  }
}

void printarLista(){
    Celula *ptr;

  if (inicio == NULL){
    printf("\n--- fim da lista ---\n\n");
    return;
  }

  // Caso a lista nao esteja vazia
  ptr = inicio;
  while (ptr !=NULL) { 
     printf(" %d ->",ptr->conteudo);
     ptr = ptr->proximo;
  }
  printf("--- fim da lista ---\n\n");
}