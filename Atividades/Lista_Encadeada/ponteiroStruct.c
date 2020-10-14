#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    
    int idade;
    float salario;
    char sexo, nome[50];
    struct pessoa *proximo;

}Pessoa;

/*
    Cadastrar 5 Pessoas
    op1 = 4 vetores
    op2 = 1 vetor de Struct
 */

int menuPrincipal(Pessoa *lista);
int novoUsuario(Pessoa *lista, int *cont);
void listarUsuarios(Pessoa *lista, int *cont);
int ler_idade(Pessoa *lista);
void imprimir_idade(Pessoa *lista);
int ler_sexo(Pessoa *lista);
void imprimir_sexo(Pessoa *lista);
int ler_salario(Pessoa *lista);
void imprimir_salario(Pessoa *lista);
int ler_nome(Pessoa *lista);
void imprimir_nome(Pessoa *lista);
void apagar_tela();

void main(){

    Pessoa *pLista = (Pessoa *)malloc(sizeof(Pessoa));

    int cont = 0;
    int *pCont = &cont;
    int opcao;

    do {

        
        opcao = menuPrincipal(pLista);

        switch(opcao){

            case 1:{ 
                novoUsuario(pLista, pCont); 
                printf("\ncont = %d\n",*pCont);
                break;
            }
            case 2:{
                listarUsuarios(pLista, pCont);
                break;
            }
            case 3:{
                printf("\nVolte Sempre\n");
                break;
            }
            default:{
                printf("\nOpcao Invalida\n");
            }
        }

    }while(opcao != 3);
}

int menuPrincipal(Pessoa *lista){

    int opcao;


    printf("\n--------- Menu Principal ------------\n\n");
    printf("1 - Novo Usuario \n");
    printf("2 - Listar \n");
    printf("3 - Sair \n\n");

    printf("Digite a sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int novoUsuario(Pessoa *lista, int *cont){

    if (cont > 0)
        lista = realloc(lista,1*sizeof(Pessoa));

    if (ler_idade(lista) == 0) return 0;
    if (ler_sexo(lista) == 0) return 0;
    if (ler_salario(lista) == 0) return 0;
    if (ler_nome(lista) == 0) return 0;

    cont ++;

    return 1;

}

void listarUsuarios(Pessoa *lista, int *cont){

    int i;

    printf("\nCont = %d\n\n", *cont);

    imprimir_idade(lista);
    imprimir_sexo(lista);
    imprimir_salario(lista);
    imprimir_nome(lista);

}

int ler_idade(Pessoa *lista){
    
    int id;
    
    printf("Digite a sua Idade: ");
    scanf("%d", &id);
    
    if (id < 0)
        return 0;
        
    lista->idade = id;
    
    return 1;
        
}

int ler_sexo(Pessoa *lista){
    
    char sx[2];
    
    printf("Digite o sexo: ");
    scanf("%s", sx);
      
    if (strlen(sx) > 1)
        return 0;
    
    if (sx[0] != 'M' && sx[0] != 'F' && sx[0] != 'm' && sx[0] != 'f')
       return 0;

    lista->sexo = sx[0]; 

    return 1;
}

int ler_salario(Pessoa *lista){
    
    printf("Digite o Salário: ");
    scanf("%f", &lista->salario);
    
    return 1;
}

int ler_nome(Pessoa *lista){
    
    char str[50];

    printf("Digite o Nome :");
    fgets(str, 50, stdin);
    
    size_t ln = strlen(str) - 1; //size_t = unsigned integer type
    if (str[ln] == '\n')
        str[ln] = '\0';
    
    if (strlen(str) == 0)
        return 0;
    
    int i;

    for (i = 0; i < strlen(str); i ++)
        lista->nome[i] = str[i];

    imprimir_nome(lista);

    return 1;
}

void imprimir_idade(Pessoa *lista){
    
    printf("\nSua idade e: %d \n", lista->idade);
}


void imprimir_sexo(Pessoa *lista){
       
    printf("O sexo digitado e: %c \n", lista->sexo);
}

void imprimir_salario(Pessoa *lista){
    
    printf("Salario Digitado e : %.2f \n", lista->salario);
}

void imprimir_nome(Pessoa *lista){
    
    printf("%s\n", lista->nome);
}



