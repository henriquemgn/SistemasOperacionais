#include <stdio.h>
#include <iostream>
using namespace std;

int lerMatriz(){
    int aux = 999;
    short int linhas = 3;
    short int colunas = 3;
    
    int matriz[linhas][colunas] = {{7,9,2},{12,43,25},{10,5,3},{47,32,13}}; 
    
    for (int i = 0; i<=linhas; i++){
        for (int j = 0; j<=colunas; j++){
            if (matriz[i][j] < aux){
                aux = matriz[i][j];
            }
        }
    }
    
    for (int i = 0; i <= linhas; i++){
        for(int j =0; j<= colunas; j++){
            if (matriz[i][j] == aux){
                return i;
            }
        }
    }
    return -1;
}


int main()
{
    cout <<"Exercicio 1: O menor numero da matriz esta na linha " <<lerMatriz() << endl;

    return 0;
}
