#include <iostream>
using namespace std;

//12. Faça uma função que retorne a posição de um dado caracter dentro de uma string.

int encontrarLetra(const char *str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }
    return -1; // caractere não encontrado na string
}

int main()
{
    
    int pos = encontrarLetra("String de Teste", 'i');
    if (pos != -1) {
        cout << "O caractere 'i' e a letra na posicao: " << pos+1 << endl;
    } else {
        cout << "O caractere 'i' nao foi encontrado na string." << endl;
    }

    cin.get();
    return 0;
}