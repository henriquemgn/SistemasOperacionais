#include <iostream>
using namespace std;

//9 Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.

void modulo_Matriz(){
    int matriz[3][3] = {{2,-3,4},{12,9,-1},{-5,11,-23}};
    
    cout << "Matriz antes: "  << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }    
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (matriz[i][j] < 0){
                matriz[i][j]*= -1;
            }
        }
    }
    
    cout << "\nMatriz depois: "  << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    modulo_Matriz();
    cin.get();
    return 0;
}