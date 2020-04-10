#include <stdio.h>

struct fila{
	int inicioFilaUm;
	int finalFilaUm;
	int inicioFilaDois;
	int finalFilaDois;
	int qtdFila1;
	int qtdFila2;
	int dados[20];
};

typedef struct fila Fila;

Fila* criarFila(){

	Fila *fi = (Fila*)malloc(sizeof(Fila));

	if (fi == NULL)
		return NULL;

	fi->inicioFilaUm = 0;
	fi->finalFilaUm = 0;
	fi->inicioFilaDois = 0;
	fi->finalFilaDois = 0;
	fi->qtdFila1 = 0;
	fi->qtdFila2 = 0;

	return fi; 
}

int filaVazia(Fila *fi, int escolha){

	if (fi == NULL)
		return -1;

	if (escolha == 1)
		if (fi->qtdFila1 == 0)
			return 1;

	else if (escolha == 2)
		if (fi->qtdFila2 == 0)
			return 1;

	return 0;
}

int filaCheia(Fila *fi, int escolha){

	if (fi == NULL)
		return -1;

	if (escolha == 1)
		if (fi->qtdFila1 == 10)
			return 1;

	else if (escolha == 2)
		if (fi->qtdFila2 == 10)
			return 1;

	return 0; 
}

int consultaFila(Fila *fi, int valor, escolha){

} 

int insereFila(Fila *fi, int valor, int escolha){

	if (li == NULL)
		return 0;

	if (escolha == 1){

		if (filaCheia(fi, escolha))
			return 0;

		fi->dados[fi->filaUm] = valor;
		fi->finalFilaUm = (fi->finalFilaUm + 1) % 10;
		fi->qtdFila1 ++;
	
	}else if (escolha == 2){

		if (filaCheia(fi, esxolha))
			return 0;

		fi->dados[fi->filaDois] = valor;
		fi->finalFilaDois = ((fi->finalFilaDois + 1) % 10) + 10;
		fi->qtdFila2 ++;
	}

	return 1;
}

int removeFila(Fila *fi, int escolha){

	if (fi == NULL || filaVazia(fi, escolha))
		return 0;

	if (escolha == 1){
		fi->inicioFilaUm = (fi->inicioFilaUm + 1) % 10;
		fi->qtdFila1 --;
		return 1;

	}else if (escolha == 2){
		fi->inicioFilaDois = (fi->inicioFilaDois + 1) % 10 + 10;
		fila->qtdFila2 --;
		return 1;
	}

	return 0; // Caso Esolha de Fila for Inválida
}

int menuPrincipal(){

	int opcao;

	printf("\n<---- Menu ---->\n\n");
	printf("1- Cria Fila \n");
	printf("2- Menu Fila 1\n");
	printf("3- Menu Fila 2\n");
	printf("4- Consulta Fila\n");
	printf("5- Sair\n\n");

	printf("Opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

int menuFilaUm(){

	int opcao;

	printf("<---- Menu Fila 1 -----> \n\n");
	printf("1- Insere na Fila \n");
	printf("2- Remove da Fila");

	printf("Opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

int menuFilaDois(){

	int opcao;

	printf("<---- Menu Fila 2 -----> \n\n");
	printf("1- Insere na Fila \n");
	printf("2- Remove da Fila");

	printf("Opcao: ");
	scanf("%d", &opcao);

	return opcao;
}

void menuAuxiliar(){
	
	int escolha, opcao, valor;

	do{

		escolha = menuPrincipal()

		switch(escolha){

			case 1:{
				Lista *fi = criarFila();
				break;
			}

			case 2:{
				
				opcao = menuFilaUm();

				if (opcao == 1){
					printf("Digite o Valor a ser Inserido: ");
					scanf("%d", &valor);

					insereFila(fi, valor, 1);
				
				}else if (opcao == 2){
					printf("Digite o Valor a ser Removido: ");
					scanf("%d", &valor);

					removeFila(fi, valor, 1);
				
				}else
					printf("\nOpcao Invalida\n\n");

				break;
			}

			case 3:{
				
				opcao = menuFilaDois();

				if (opcao == 1){
					printf("Digite o Valor a ser Inserido: ");
					scanf("%d", &valor);

					insereFila(fi, valor, 2);
				
				}else if (opcao == 2){
					printf("Digite o Valor a ser Removido: ");
					scanf("%d", &valor);

					removeFila(fi, valor, 2);
				
				}else
					printf("\nOpcao Invalida\n\n");

				break;
			}

			case 4:{
				printf("Digite o Valor a ser Consultado: ");
				scanf("%d", &valor);

				consultaFila(fi, valor);

				break;
			}

			case 5:{

				printf("\nObrigado por Usar, volte Sempre\n\n");
				break;
			}
		}

	}while (escolha != 5);
	
}

void main(){

	menuAuxiliar();

}