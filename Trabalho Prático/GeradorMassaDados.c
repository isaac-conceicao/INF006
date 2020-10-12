#include <stdio.h>
#include <conio.h>

// numero de cidades que estaram no arquivo
#define cidades 500

int randomico(){
		
	// randomico entre 1 e 10
	int temp = 1 + ( rand() % 10 );
	
	return temp;
}

float tamanhoCabo(int ps, int cg){
	
	int temp;
	float tam;
	
	// definindo tamanho do cabo	
	switch(cg){
		
        case 1 ... 2: 
            temp = ps * 1000;
        break; 		
        case 3 ... 4: 
            temp = ps * 2000;
        break; 		
        case 5 ... 6: 
            temp = ps * 3000;
        break; 		
        case 7 ... 8: 
            temp = ps * 4000;
        break; 		
        case 9 ... 10: 
            temp = ps * 5000;
        break; 		
	
	}
		
	tam = temp/cg;	
	
	return tam;
}

int peso(int cg){
	
	int ps = 0;

	// regra para definicao do peso	
	switch(cg){
		
        case 1 ... 5: 
            ps = cg * 15;
        break; 		
        case 6 ... 10: 
            ps = cg * 25;
        break; 		
        case 11 ... 20: 
            ps = cg * 45;
        break; 		
        default: 
            ps = cg * 60;
        break; 		
	}
	
	return ps;
}

int main() {
	
	FILE *arq;
	float tempTam;
	int i, contador, result, tempPeso, tempCG;
	char nome[3];
	
	arq = fopen("maDados.txt", "w");  // Cria um arquivo texto para gravação
	
	if (arq == NULL){
		printf("Falha !!!!!\n");
		return;
	}
	
	// numero de cidades que estaram no arquivo
	while(contador <= cidades){

		tempTam = 0;
		
		tempPeso = 0;
		
		tempCG = 0;
	
		// randomico entre 1 e 10. Com isso teremos que a conectividade  
		// maxima de um lading point eh 10 
		tempCG = randomico();
		
		tempPeso = peso(tempCG);
		
		tempTam = tamanhoCabo(tempPeso, tempCG);
		
		// inserindo na massa de dados uma linha para cada cabo (conectividade)		
		for(i = 0; i < tempCG; i++){
			
			//Nome; Tamanho do cabo ; Peso ; Grau de conectividade
			result = fprintf(arq,"%d ; %.2f ; %d ; %d \n", contador, tempTam, tempPeso, tempCG);
		}
		
		if (result == EOF){
			printf("Erro na Gravacao\n");
		}
			
		contador++;	
	}
	
	fclose(arq);
}
