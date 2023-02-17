#include <iostream>
using namespace std;

void notas(){
    short int nota1=6,nota2=4,nota3=10;
    cout << "Nota 1: " << nota1 << "\nNota 2: " << nota2 << "\nNota 3: " << nota3 <<endl;
    short int ME = (nota1+nota2+nota3)/3;
    short int MA = (nota1 + nota2*2 + nota3*3 + ME)/7;
    cout << "Media em numero: " << MA << "\n"<<endl;
    
    if(MA>=9){
        cout << "Nota Final: A" << endl;
    }else if(MA>=7.5){
        cout << "Nota Final: B" << endl;
    }else if(MA>=6){
        cout << "Nota Final: C" << endl;
    }else if(MA>=4){
        cout << "Nota Final: D" << endl;
    }else if(MA<4){
        cout << "Nota Final: E" << endl;
    }
}

int main()
{
    notas();
    cin.get();
    return 0;
}
