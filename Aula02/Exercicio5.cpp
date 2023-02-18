#include <iostream>
#include <string>
using namespace std;

void multiplicar_Matriz(int multiplicador){
    
    int matriz[3][3] = {{2,3,8},{13,9,1},{4,11,7}};
    
    cout << "Matriz Antes:" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\nMatriz Depois: " << "(primeira linha e coluna multiplicada por " << multiplicador << ")" << endl;
    for(int i = 0; i < 3; i++){
        matriz[i][0] *= multiplicador;
        for(int j = 0; j <3; j++){
            matriz[0][j] *= multiplicador;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    multiplicar_Matriz(n);
    
    cin.get();
    return 0;
}