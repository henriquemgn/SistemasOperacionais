#include <iostream>

using namespace std;

void inserir(int n, char *string){
    
    for (int i = 100; i >= n; i--){
        string[i+1] = string[i];
    }
    string[n] = 'A';
}

int main()
{
    char Str[100] = "string de teste para inserir";
    
    cout << "String antes: ";
    cout << Str <<endl;
    
    cout << "\nString depois: ";
    inserir(5, Str);
    
    cout << Str << endl;
    
    cin.get();
    return 0;
}