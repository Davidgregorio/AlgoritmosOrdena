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
