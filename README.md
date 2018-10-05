# AlgoritmosOrdena
Algoritmos de ordenação (Insertion, Selection, Buble, Shell, Merge, Quick, Heap)

ALGORITMOS  **************************************************************************************************************
Algoritmos.h
                            /*
    INSERTION SORT          ***********************
                            */
			    
void insertion (int vet[], int tam){
    int i = 0, j, aux;
    for ( j = 1; j < tam ; j++){
		aux = vet[j];
		i = j - 1;
		while ((i > -1) && ( aux < vet[i])){
			vet[i + 1] = vet[i];
			i = i - 1;
		}vet[i + 1] = aux;
    }
 }

                            /*
    SELECTION SORT          ***********************
                            */
			    
void selection(int vet[], int tam){
    for (int i = 0; i < tam; ++i) {
        int Vminimo = i;
        for (int j = i+1; j < tam; ++j) {
            if (vet[j] < vet[Vminimo]) {
            Vminimo = j;}
        }
        int aux = vet[i];
        vet[i] = vet[Vminimo];
        vet[Vminimo] = aux;
    }
}
                            /*
    BUBLE SORT              ***********************
                            */
			    
void buble(int vet[], int tam){
    int aux, i, j;
    for (i = 0; i < (tam - 1); i++) {
        for (j = 0; j < (tam-(i+1)); j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j]= vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

                            /*
    SHELL SORT              ***********************
                            */
void shellS(int vet[], int tam){
    int h = tam/2;
    int i, j, aux;

    while (h > 0){
        i = h;
        while (i < tam){
            aux = vet[i];
            j = i;
            while (j >= h && aux < vet[j-h]){
                vet[j] = vet[j-h];
                j = j - h;
            }vet[j] = aux;
            i = i + 1;
        }h = h/2;
    }
}

                            /*
    MERGE SORT              ***********************
                            */

void Intercala(int inicio, int fim, int vet[], int meio){
    int i = inicio, j = meio + 1, k = 0;
    int *temp = (int *) malloc(sizeof(int) * (fim - inicio + 1));

   while( i < meio + 1 || j  < fim + 1 ){
      if ( i == meio+1 ){
         temp[k] = vet[j];
         j++;   k++;
      }else{
         if (j==fim+1){
            temp[k] = vet[i];
            i++;  k++;
         }else{
            if (vet[i] < vet[j]){
               temp[k] = vet[i];
               i++; k++;
            }else{
              temp[k] = vet[j];
              j++;  k++;
            }
         }
      }
   }

   for( i = inicio; i <= fim; i++ ){
      vet[i] = temp[i-inicio];
    }free(temp);
}

void mergeH( int vet[], int inicio, int fim){
    int meio;
    if ( inicio == fim )
    return;

    meio = ( inicio + fim )/2;
    mergeH( vet, inicio, meio);
    mergeH( vet, meio+1, fim );
    Intercala(inicio, fim, vet, meio);
}

                        /*
    QUICK SORT              ***********************
                            */

int particiona (int vet [], int p, int r){
	int k = p + rand() % (r-p+1); // retorna um num aleatorio
 	int pivo, d, i, j;
 	pivo = vet [k]; vet [k] = vet[p]; vet[p] = pivo;
 	i = p;
 	for (j = p+1; j <= r; j++){
 		if (vet[j]<pivo){ i++;
 		d = vet [i]; vet[i] = vet [j]; vet[j] = d;}
    }d = vet [i]; vet[i] = vet[p]; vet [p] = d;
    return i;
}

void quick(int vet[],int p, int r){
   if (p < r){
   	int meio;
   		meio = particiona (vet, p, r);
      	quick (vet, p, meio-1);
     	quick (vet, meio + 1, r);
    }
}
                            /*
    HEAP SORT               ***********************
                            */
void min_heapify(int vet[], int tam, int i){
    int menor;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < tam && vet[esq] > vet[i])
		menor = esq;
	else menor = i;
	if (dir < tam && vet[dir] > vet[menor])
		menor = dir;
    if (menor != i){
		int temp = vet[i];
		vet[i] = vet[menor];
		vet[menor] = temp;
		min_heapify(vet, tam, menor);
   }
}

void heapS(int vet[], int tam){

    for (int i = tam / 2 - 1; i >= 0; i--)
        min_heapify(vet, tam, i);

    for (int i=tam-1; i>=0; i--){
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;
        min_heapify(vet, i, 0);
    }
}



INSTANCIAS ( Gera os números a serem ordenados)  *************************************************************************
Instancias.h

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



MENU   *******************************************************************************************************************
Menu.h

#include "Algoritmos.h"
using namespace std;

double menu (double menuOp[]){  // Solicita as informações: Qual algoritmo, ordenação e tamanho da instância

    do{ cout << "\n     ALGORITMO:\n\n     1 - Insetion Sort \n     2 - Selection Sort \n     3 - Buble Sort \n     4 - Shell Sort \n     5 - Merge Sort \n     6 - Quick Sort \n     7 - Heap Sort\n     0 - Sair\n     :";
        cin >> menuOp[1];system("cls");
        if (menuOp[1]==0) return 0;
        }while(menuOp[1] > 11);system("cls");

    do{	cout << "\n     ORDENACAO:\n\n     1 - Crescente\n     2 - Randomico\n     3 - Decrescente\n     0 - Sair\n\n :";
		cin >> menuOp[2];	system("cls");
		if (menuOp[2]==0) { menuOp[1]=0;return 0;}
		}while(menuOp[2]<0 || menuOp[2]>3);

    do{	cout << "\n     TAMANHO:\n\n     VaLores multiplos de 10\n\n :";    // Recebe do usuário o tamanho, que deve estar nos intervalos multiplos de 10 até
		cin >> menuOp[4];	system("cls");
		if (menuOp[4]==0)  { menuOp[1]=0;return 0;}
		}while(menuOp[4]!=10 && menuOp[4]!=100 && menuOp[4]!=1000 && menuOp[4]!=10000 && menuOp[4]!=100000 && menuOp[4]!=1000000  && menuOp[4]!=10000000 && menuOp[4]!=100000000 && menuOp[4]!=1000000000);

	return *menuOp;
}


double seleciona(double menuOp[]){
    int *vet;int i=0;
    vet = (int *)malloc (menuOp[4] * sizeof(int));
    int tam = menuOp[4];
	char conversao[15], caminho[80] = "";
	double tempoGasto, inicio, fim;
	string algoritmo [7] = {"Insertion", "Selection", "Buble", "Shell", "Merge", "Quick", "Heap"};
    string ordenacao [3] = {"Crescente", "Randomica", "Decrescente"};

	if (menuOp[2] == 1)strcat(caminho, "Arquivos\\Crescentes\\");       // Concatenações para gerar o nome do arquivo a ser aberto
	else if (menuOp[2] == 2)strcat(caminho, "Arquivos\\Randomicos\\");
    else if (menuOp[2] == 3)strcat(caminho, "Arquivos\\Decrescentes\\");
	sprintf(conversao, "%i", tam);
	strcat(conversao,".txt");
	strcat(caminho,conversao);
    cout <<"\n\n    Lendo arquivo ..." << endl;
    std::ifstream file(caminho);
    unsigned size;
    file >> size;
    if (!file) { cout << "Erro na leitura";}
    while (true) {
        double value;
        if (!(file >> value)) {
            break;
        }vet[i] = value; i++;
    }system ("cls");
    file.close();

    cout <<"\n\n    Ordenando ..." << endl;
    int op = menuOp[1];
    inicio = clock();
    switch(op){
        case 1: insertion(vet, tam);
            break;
        case 2: selection(vet, tam);
            break;
        case 3: buble(vet, tam);
            break;
        case 4: shellS(vet, tam);
            break;
        case 5: mergeH(vet, 0, tam - 1);
            break;
        case 6: quick(vet, 0, tam);
            break;
        case 7: heapS (vet, tam);
            break;
    }fim = clock(); system ("cls");
           // for (int i = 0; i < tam; i++){ cout << vet[i] << endl;}system ("pause");system ("cls");
    free(vet); int ord = menuOp[2];
    tempoGasto = ((fim-inicio)/(double)CLOCKS_PER_SEC);
    cout << "\n\n   Tempo gasto: " << tempoGasto << endl;
    cout << "   Algoritmo .: " << algoritmo [op-1] << endl;
    cout << "   Ordenacao .: " << ordenacao [ord-1]<< endl;
    cout << "   Instancia .: " << menuOp[4] << endl << endl;

    system ("pause");
    system ("cls");
    return *menuOp;
}



MAIN  ********************************************************************************************************************
app.cpp

#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <list>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <array>
#include "Instancias.h"
#include "Menu.h"
using namespace std;

int main(){
    double *menuOp;                     // Capta as opções, onde nas posições: 1- algoritmo 2-ordenação 4-tamanho da instancia
    menuOp = (double *)malloc (6 *sizeof(double));
    int arq, sair =1;
    cout << ("\n     ALGORITMOS DE ORDENACAO\n\n     1 - Gerar Arquivos \n     0 - Nao Gerar \n     :");cin >> arq;
    if(arq == 1){cout << "\n Gerando arquivos ..";
        gerarInstancias();              // Chama a função que gera os números (instancias)
        }system("cls");
    do{ *menuOp = menu(menuOp);         // Loop: apresenta o menu, ate que o usuario digita 0 para sair
        if (menuOp[1] == 0) return 0;
        *menuOp = seleciona(menuOp);
        }while(menuOp[1] != 0);
    free(menuOp);
    return 0;
}
