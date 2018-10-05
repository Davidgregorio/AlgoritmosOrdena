#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <list>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <array>

using namespace std;

int geraNum(int vet[], int opcao[]){ // gera o vetor de numeros
    int j;
	switch (opcao[2]){
		int i;

		case 1: cout << "\n Gerando entradas Crescentes...\n";
			for (i=0; i<opcao[4];i++){
				vet[i]=i+1;

				}	break;
		case 2: cout << "\n Gerando entradas Randomicas...\n";
			for (i=0; i<opcao[4];i++){	vet[i]=(rand () % opcao[4]+1);

			}	break;
		case 3: cout <<"\n Gerando entradas Decrescentes...\n";
            j=0;
			for (i=opcao[4]; i>0;i--){
                    vet[j]=i;
                    j++;

			}	break;
	}	return *vet;
}

void criaPastas (int opcao[]){ // cria as pastas
	int op;
	switch(opcao[2] ){

				case 1:	system("mkdir Arquivos\\Crescentes"); break;
				case 2:	system("mkdir Arquivos\\Randomicos"); break;
				case 3:	system("mkdir Arquivos\\Decrescentes");	break;
	}
	system ("cls");
}

void arquivoEntrada (int opcao[], int vet[]){ // Gera arquivos entrada
	FILE* f;
	char conversao[15], caminho[80] = "";
	int j, i = 0;

	strcat(caminho, "Arquivos\\");
	sprintf(conversao, "%i", opcao[4]); // salva em conversão o que vai ser nome do arquivo, neste caso, o que o usuário digitou, e que esta salvo no ponteiro menu
	strcat(conversao,".txt"); // concatena com .txt

	switch(opcao[2]){ // concatena com as 3 opções de ordenação crescente, decresc....
		case 1:	strcat(caminho, "Crescentes\\");
			strcat(caminho,conversao);
			f = fopen(caminho, "w");
			if (f == NULL){ printf ("\n O arquivo nao pode ser criado!\n\n"); exit(1);}
			else fprintf (f, "%d \n\n", opcao[4]);
			for (j=0;j<opcao[4];j++) fprintf (f, "%d\n", vet[j]); 	break;

		case 2:	strcat(caminho, "Randomicos\\");
			strcat(caminho, conversao);
			f = fopen(caminho, "w");
			if (f == NULL){	printf ("\n O arquivo nao pode ser criado!\n\n"); exit(1);}
			else fprintf (f, "%d \n\n", opcao[4]);
			for (j=0;j<opcao[4];j++) fprintf (f, "%d\n", vet[j]); 	break;

		case 3:strcat(caminho, "Decrescentes\\");
			strcat(caminho, conversao);
			f = fopen(caminho, "w");
			if (f == NULL){ printf ("\n O arquivo nao pode ser criado!\n\n"); exit(1);}
			else fprintf (f, "%d \n\n", opcao[4]);
			for (j=0;j<opcao[4];j++) fprintf (f, "%d\n", vet[j]); 	break;
	}fclose(f);
}

void gerarInstancias(){
    int *opcao, *vet;
    opcao = (int *)malloc (4 *sizeof(int) );
    for (int i= 1; i<4; i++){                                                       // Gerencia ordenação
        opcao[2] = i;
        opcao[4] = 1;                                                             // a partir de que tamanho gerar intancias
            for(int j=1; j<9; j++){              // Gera instancias de até até 10^8
                opcao[4]  = opcao[4]*10;         // As instancias são multiplas de 10
                vet = (int *)malloc (opcao[4] * sizeof(int));
                criaPastas(opcao);                                                   // cria pastas
                *vet = geraNum(vet, opcao);                                          // gera os numeros e insere no vetor
                arquivoEntrada (opcao,vet);
                free(vet);                                        // cria os arquivos entrada
                }
        }
    free(opcao);
    system ("cls");
    cout << " \n Instancias Geradas com sucesso!" << endl;
}
