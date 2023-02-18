#include <iostream>
using namespace std;

//11. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. O resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.

void soma_Matriz(){
    int matriz[3][3] = {{2,-3,4},{12,9,-1},{-5,11,-23}};
    int matrizSomada[3][3] = {{2,-3,4},{12,9,-1},{-5,11,-23}};
    int matrizMultiplicada[3][3] = {{2,-3,4},{12,9,-1},{-5,11,-23}};
    
    cout << "Matriz antes da soma: "  << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }    
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (matriz[i][j] < 0){
                matrizSomada[1][j] = matriz[0][j] + matriz[1][j];
                matrizMultiplicada[1][j] = matriz[0][j] * matriz[1][j];
            }
        }
    }
    
    cout << "\nMatriz depois da soma: "  << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matrizSomada[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMatriz depois da multiplicacao: "  << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matrizMultiplicada[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    soma_Matriz();
    cin.get();
    return 0;
}