#include <iostream>
using namespace std;

int lerMatriz(){
    int aux = 999;
	
    int matriz[3][3] = {{7,9,2},{12,43,25},{10,5,3}}; 
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (matriz[i][j] < aux){
                aux = matriz[i][j];
            }
        }
    }
    
    for (int i = 0; i < 3; i++){
        for(int j = 0; j< 3; j++){
            if (matriz[i][j] == aux){
                return i+1;
            }
        }
    }
    return -1;
}


int main()
{
    cout <<"Exercicio 1: O menor numero da matriz esta na linha " <<lerMatriz() << endl;
    cin.get();
    return 0;
}
