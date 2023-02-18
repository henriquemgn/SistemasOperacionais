#include <iostream>

// 7. Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct. 
// O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas. A struct deve armazenar os dados de idade, peso e altura.

using namespace std;

struct Pessoa  
{  
    int idade;  
    int peso;  
    int altura;  
};  

int main()
{
    Pessoa pessoas[3];
    pessoas[0].idade = 18;
    pessoas[0].peso = 80;
    pessoas[0].altura = 180;

    pessoas[1].idade = 56;
    pessoas[1].peso = 72;
    pessoas[1].altura = 184;
    
    pessoas[2].idade = 26;
    pessoas[2].peso = 60;
    pessoas[2].altura = 170;
    
    for (int i = 0; i < 3; i++){
        cout << "Pessoa " << i+1 << ":\n" << endl;
        cout << "Pesa: " << pessoas[i].peso << "kg."<< endl;
        cout << "Idade: " << pessoas[i].idade << " anos." << endl;
        cout << "Altura: " << pessoas[i].altura << " cm de altura." << endl;
        cout << "\n\n";
    }

    cin.get();

    return 0;
}