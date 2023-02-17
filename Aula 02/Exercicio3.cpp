#include <iostream>
using namespace std;

int piramide(int tamanho){
    
    int espacos = 0;
    
    for (int i = 1; i<=tamanho; i+=2){
        for (int j = 0; j < espacos; j++) {
            cout << "   ";
        }
        for(int j = i; j<= tamanho;j++){
            cout << j << "  ";
        }
        cout <<"\n";
        espacos++;
    }
    return 1;
}

int main()
{
    int max_num;
    do {
        cout << "Digite o numero maximo (impar): ";
        cin >> max_num;
    } while (max_num % 2 == 0);
    
    piramide(max_num);
    
    cin.get();
    cin.get();
    cin.get();
    return 0;
}
