/*

- Fila 1 responsável pelas posicoes (0 - 9)
- Fila 2 responsável pelas posicoes (10 - 19)

Obs: Teria sido melhor usar uma fila estática, mas ainda não sei tornar ela circular.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *ptrToInicio;
} No;

void inicializar(No vet[]);
void incluirNaLista(No vetor[], int *pt1, int *pt2);
int pesquisarNaLista(No vetor[], int pesquisar);
void shift(No vetor[], int pos);
void removerDaLista(No vetor[], int *pt1, int *pt2);

int main(){
    No vet[20];
    int i, cont1 = 0, cont2 = 10;
    int *c1, *c2;

    c1 = &cont1;
    c2 = &cont2;

    inicializar(vet);

    for(i=0; i<20;i++)
        incluirNaLista(vet,c1,c2);

    printf("impressao\n\n");

    for(i=0; i<20;i++)
        printf("%d\n",vet[i].conteudo);

    pesquisarNaLista(vet, 42);

    removerDaLista(vet, c1,c2);

    printf("impressao\n\n");

    for(i=0; i<20;i++)
        printf("%d\n",vet[i].conteudo);

    return 0;
} 

void incluirNaLista(No vetor[], int *pt1, int *pt2){
    int op;

    printf("Inserir na lista 1 ou 2?\n");
    scanf("%d",&op);

    if(op == 1){
        if(*pt1 > 9){
            printf("Lista cheia\n");
            exit(0);
        }

        if(*pt1 == 9){
            printf("Insira o valor ");
            scanf("%d",&vetor[*pt1].conteudo);
            vetor[*pt1].ptrToInicio = &vetor[0];
            *pt1+=1;
        }

        if(*pt1 < 9){
            printf("Insira o valor ");
            scanf("%d",&vetor[*pt1].conteudo);
            vetor[*pt1].ptrToInicio = &vetor[*pt1+1];
            *pt1+=1;
        }  
    }else{
        getchar();
        if(*pt2 > 19){
            printf("Lista cheia\n");
            exit(0);
        }

        if(*pt2 == 19){
            printf("Insira o valor ");
            scanf("%d",&vetor[*pt2].conteudo);
            vetor[*pt2].ptrToInicio = &vetor[10];
        }

        if(*pt2 > 9 && *pt2 < 19){
            printf("Insira o valor ");
            scanf("%d",&vetor[*pt2].conteudo);
            vetor[*pt2].ptrToInicio = &vetor[*pt2+1];
            *pt2+=1;
        }
    }
}

int pesquisarNaLista(No vetor[], int pesquisar){
    int op, encontrou = 0;
    int i1 = 0, i2 = 10;

    printf("Pesquisar o valor %d na lista 1 ou 2?\n", pesquisar);
    scanf("%d",&op);

    printf("Buscando o valor: %d...\n",pesquisar);

    if(op==1){
        while(i1< 9 && encontrou == 0){
            if(vetor[i1].conteudo == pesquisar){
                encontrou = 1;
                printf("Encontrou o valor %d na lista 1\n",pesquisar);
                return i1;
            }else{
                i1++;
            }
        }
    }else{
        while(i2 < 19 && encontrou == 0){
            if(vetor[i2].conteudo == pesquisar){
                encontrou = 1;
                printf("Encontrou o valor %d na lista 2\n",pesquisar);
                return i2;
            }else{
                i2++;
            }
        }
    }

    if(encontrou == 0)
        printf("Nao encontrou o valor\n");

    return 0;
}

void shift(No vetor[], int pos){
    int aux;
    if(pos != 9 && pos != 19){
        if(pos < 9){
            aux = 9-pos;
            while(aux>1){
                vetor[pos].conteudo = vetor[pos+1].conteudo;
                pos++;
                aux-=1;
            }
        }else{
            aux = 19-pos;
            while(aux>0){
                vetor[pos].conteudo = vetor[pos+1].conteudo;
                pos++;
                aux-=1;
            }
        }
    }
}

void removerDaLista(No vetor[], int *pt1, int *pt2){
    int op, pesquisar, encontrou = 0;
    int i1 = 0, i2 = 10;
    
    printf("Remover da lista 1 ou 2?\n");
    scanf("%d",&op);

    printf("Qual valor Remover?\n");
    scanf("%d",&pesquisar);


    if(op==1){
        while(i1< 9 && encontrou == 0){
            if(vetor[i1].conteudo == pesquisar){
                encontrou = 1;
                printf("Removendo o valor %d na lista 1\n",pesquisar);
                shift(vetor, i1);
                *pt1 -=1;
            }else{
                i1++;
            }
        }
    }else{
        while(i2 < 19 && encontrou == 0){
            if(vetor[i2].conteudo == pesquisar){
                encontrou = 1;
                printf("Removendo o valor %d na lista 2\n",pesquisar);
                shift(vetor, i2);
                *pt2 -=1;
            }else{
                i2++;
            }
        }
    }

    if(encontrou == 0)
        printf("Nao encontrou o valor\n");
}

void inicializar(No vet[]){
    int i;

    //ZERAR TODO VETOR PARA EVITAR LIXO, apontar para o proximo e no fim de cada fila apontar para o inicio
    for(i=0; i<20;i++){
        vet[i].conteudo = 0;

        if(i==9)
            vet[i].ptrToInicio = &vet[0];
        else if(i==19)
            vet[i].ptrToInicio = &vet[0];
        else 
            vet[i].ptrToInicio = &vet[i+1];
    }
}