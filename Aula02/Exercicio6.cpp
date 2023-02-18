#include <iostream>
#include <string>
using namespace std;

void transportar_Matriz(int multiplicador){
    
    int matriz[3][3] = {{2,3,8},{13,9,1},{4,11,7}};
    int transposta[3][3];
    
    cout << "Matriz Antes:" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <3; j++){
            transposta[j][i] = matriz[i][j];
        }
    }
    
    cout << "\nMatriz Transposta:" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << transposta[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n = 5;
    transportar_Matriz(n);
    
    cin.get();
    return 0;
}