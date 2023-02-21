#include <iostream>

using namespace std;

void remover(int n, char *string){
    for (int i = 0; i < 100; i++ ){
        if (i >= n){
            string[i] = string[i+1];
        }
    }
}

int main()
{
    char Str[100] = "string de teste para remover";
    
    cout << "String antes: ";
    cout << Str <<endl;
    
    cout << "\nString depois: ";
    remover(5, Str);
    
    cout << Str << endl;

    cin.get();
    return 0;
}