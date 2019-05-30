#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menu(int* A, int* B, int tamA, int tamB){

	int i, j;

	printf("Conjunto A = ");
	for(i=0; i<tamA; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("Conjunto B = ");
	for(i=0; i<tamB; i++)
		printf("%d ", B[i]);
	printf("\n");

	printf("\n************************** Menu **************************\n");
	printf("1 - Verificar pertinência de um elemento\n");
	printf("2 - Exibir elementos de maior e menor valor de A e B\n");
	printf("3 - Verificar igualdade dos conjuntos\n");
	printf("4 - Verificar se A é subconjunto de B ou se B é subconjunto de A\n");
	printf("5 - Gerar o conjunto de União de A e B\n");
	printf("6 - Gerar o conjunto de Interseção entre A e B\n");
	printf("7 - Gerar os conjuntos de Diferença A−B e B−A\n");
	printf("8 - Gerar os conjuntos de Complemento de A e Complemento de B\n");
	printf("0 - Sair\n");
	printf("***********************************************************\n");
}

int main(){

	int tamA, tamB, e, i=0, j=0, repetido = 0;

	printf("Digite a quantidade de elementos de A: ");
	scanf("%d", &tamA);

	int A[tamA];

	srand(time(NULL));
	
	for(i=0; i<tamA; i++){
		repetido = 0;
		e = (rand() % 100)-50;
		for(j=0; j<=i; j++){
			if(e == A[j]){
				repetido = 1;
				break;
			}
		}
		if(repetido == 1)
			i--;
		else
			A[i] = e;

	}

	printf("Digite a quantidade de elementos de B: ");
	scanf("%d", &tamB);

	int B[tamB];

	for(i=0; i<tamB; i++){
	printf("Digite o %do elemento: ", i+1);
	scanf("%d", &e);
	repetido = 0;
	for(j=0; j<=i; j++){
		if(e == B[j]){
			repetido = 1;
			break;
		}
	}
	if(repetido == 1){
		printf("\nO numero %d ja existes no conjunto B\n\n",e);
		i--;
	}
	else
		B[i] = e;
	}

	int sair = 0;
	system("clear");

	while(sair == 0){
		int opcao;

		menu(A, B, tamA, tamB);

		printf("\nEscolha sua opcao: ");
		scanf("%d", &opcao);

		int existe = 0;

		switch(opcao){
			case 1:
				system("clear");
				int x;
				printf("Digite o elemento a ser verificado: ");
				scanf("%d", &x);
				for(i=0; i<tamA; i++)
					if(x == A[i]){
						existe = 1;
						break;
					}
				for(i=0; i<tamB; i++)
					if(x == B[i]){
						existe = 1;
						break;
					}
				if(existe == 1)
					printf("O elemento %d existe em um dos conjuntos!\n\n", x);
				else
					printf("O elemento %d nao existe em um dos conjuntos!\n\n", x);
				break;
			case 2:
				system("clear");
				int menor = A[0];
				int maior = A[0];
				for(i=0; i<tamA; i++){
					if(A[i] > maior)
						maior = A[i];
					if(A[i] < menor)
						menor = A[i];
				}
				for(i=0; i<tamB; i++){
					if(B[i] > maior)
						maior = B[i];
					if(B[i] < menor)
						menor = B[i];
				}
				printf("\n%d e o maior elemento nos dois conjuntos\n", maior);
				printf("%d e o menor elemento nos dois conjuntos\n\n", menor);
				break;
			case 3:
				system("clear");
				break;
			case 4:
				system("clear");
				break;
			case 5:
				system("clear");
				break;
			case 6:
				system("clear");
				break;
			case 7:
				system("clear");
				break;
			case 8:
				system("clear");
				break;
			case 9:
				system("clear");
				break;
			case 0:
				system("clear");
				sair = 1;
				break;
			default:
				system("clear");
				printf("\nOpcao invalida\n\n");
				break;
		}
	}

	return 0;
}