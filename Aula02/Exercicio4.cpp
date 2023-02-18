#include <iostream>
#include <string>
using namespace std;

void ordem_alfabetica(){
    string nome1 = "Joao Joao";
    string nome2 = "Henrique Henrique";
    
    if (nome1 < nome2){
        cout << "1-" << nome1 << " 2-" << nome2 << endl;
    }else{
        cout << "1-" << nome2 << " 2-" << nome1 << endl;
    }
}

int main()
{
    ordem_alfabetica();
    
    cin.get();
    return 0;
}
