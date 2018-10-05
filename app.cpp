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
