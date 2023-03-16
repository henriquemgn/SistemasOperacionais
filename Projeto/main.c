/****

Projeto de Sistemas Operacionais

Problema dos filosofos

Metodo utilizado para solução, colocado os filosofos em uma lista circular,
imaginando a mesa circular onde tera os garfos como 1 ou 0 e os filosofos como,
F1, F2, F3, F4 e F5, ou seja, ->1-F1-1-F2-1-F3-1-F4-1-F5->, e caso F1 esteja comendo
->0-F1-0-F2-1-F3-1-F4-1-F5-> e apenas F3 ou F4 pode comer, como F3 é menor q F4 ele
irá comer, e após abaixar os garfos o proximo da lista comerá e o proximo disponivel

*****/

#include <stdio.h>
#include <unistd.h> // sleep

void imprimir(char *mesa[], int fome[]){
    for(int i = 0; i < 10; i++){
        printf("%s ",mesa[i]);
    }
}

char** resetGarfos(char *mesa[]){
    mesa[0] = "1";
    mesa[2] = "1";
    mesa[4] = "1";
    mesa[6] = "1";
    mesa[8] = "1";
    
    return mesa;
}

char* verificadorFome(int fome[], char *mesa[]){
    
    if(fome[0] >= fome[1] && fome[0] >= fome[2] && fome[0] >= fome[3] && fome[0] >= fome[4]){
        if (mesa[0] == "1" && mesa[2] == "1"){
            return "fome1";
        }else if(fome[1] >= fome[2] && fome[1] >= fome[3] && fome[1] >= fome[4] && mesa[2]=="1" && mesa[4]=="1"){
            return "fome2";
        }else if(fome[2] >= fome[3] && fome[2] >= fome[4] && mesa[4]=="1" && mesa[6]=="1"){
            printf("teste1");
            return "fome3";
        }else if(fome[3] >= fome[4] && mesa[6]=="1" && mesa[8]=="1"){
            return "fome4";
        }else if(mesa[8] == "1" && mesa[0] == "1"){
            return "fome5";
        }
    }
    
    if(fome[1] >= fome[0] && fome[1] >= fome[2] && fome[1] >= fome[3] && fome[1] >= fome[4]){
        if (mesa[2] == "1" && mesa[4] == "1"){
            return "fome2";
        }else if(fome[2] >= fome[3] && fome[2] >= fome[4] && mesa[4]=="1" && mesa[6]=="1"){
            printf("teste2");
            return "fome3";
        }else if(fome[3] >= fome[4] && mesa[6]=="1" && mesa[8]=="1"){
            return "fome4";
        }else if(mesa[8] == "1" && mesa[0] == "1"){
            return "fome5";
        }
    }
    
    if(fome[2] >= fome[3] && fome[2] >= fome[4]){
        if (mesa[4] == "1" && mesa[6] == "1"){
            printf("teste3");
            return "fome3";
        }else if(fome[3] >= fome[4] && mesa[6]=="1" && mesa[8]=="1"){
            return "fome4";
        }else if(mesa[8] == "1" && mesa[0] == "1"){
            return "fome5";
        }
    }
    
    if(fome[3] >= fome[4]){
        if (mesa[6] == "1" && mesa[8] == "1"){
            return "fome3";
        }
    }else if(mesa[8] == "1" && mesa[0] == "1"){
            return "fome5";
        }
    
    else{
        return "fome5";
    }
}

void filosofosComem(int fome[], char *mesa[]){
    
    int pip[2];
    pipe(pip);
    
    if (fome[0] <= 0 && fome[1] <= 0 && fome[2] <= 0 && fome[3] <= 0 && fome[4] <= 0){
        printf("\n Todos terminaram de comer");
    }
    
    char *aux = verificadorFome(fome,mesa);
    mesa = resetGarfos(mesa);
    for(int i = 0; i < 2; i++){
        if (aux == "fome1" && fome[0]>0){
            printf("Filoso 1 comendo.\n");
            fome[0] -= 50;
            mesa[0] = "0";
            mesa[2] = "0";
            aux = verificadorFome(fome,mesa);
        }else if(aux == "fome2" && fome[1]>0){
            printf("Filoso 2 comendo.\n");
            fome[1] -= 50;
            mesa[2] = "0";
            mesa[4] = "0";
            aux = verificadorFome(fome,mesa);
        }else if(aux == "fome3" && fome[2]>0){
            printf("Filoso 3 comendo.\n");
            fome[2] -= 50;
            mesa[4] = "0";
            mesa[6] = "0";
            aux = verificadorFome(fome,mesa);
        }else if(aux == "fome4" && fome[3]>0){
            printf("Filoso 4 comendo.\n");
            fome[3] -= 50;
            mesa[6] = "0";
            mesa[8] = "0";
            aux = verificadorFome(fome,mesa);
        }else if(aux == "fome5" && fome[4]>0){
            printf("Filoso 5 comendo.\n");
            fome[4] -= 50;
            mesa[8] = "0";
            mesa[0] = "0";
            aux = verificadorFome(fome,mesa);
        }
    }
    
    printf("verificarFome = %s\n",aux);
    imprimir(mesa,fome);
    printf("\n");
    
    printf("Fome[0] = %d\n",fome[0]);
    printf("Fome[1] = %d\n",fome[1]);
    printf("Fome[2] = %d\n",fome[2]);
    printf("Fome[3] = %d\n",fome[3]);
    printf("Fome[4] = %d\n",fome[4]);
    
    sleep(1);
    filosofosComem(fome,mesa);

}

int main(){
    char *mesa[10];
    int fome[5];
    
    fome[0] = 100;
    fome[1] = 100;
    fome[2] = 100;
    fome[3] = 100;
    fome[4] = 100;

    // adicionar valores a lista
    mesa[0] = "1";
    mesa[1] = "F1";
    mesa[2] = "1";
    mesa[3] = "F2";
    mesa[4] = "1";
    mesa[5] = "F3";
    mesa[6] = "1";
    mesa[7] = "F4";
    mesa[8] = "1";
    mesa[9] = "F5";
    
    filosofosComem(fome,mesa);
    
    // imprimir lista

    return 0;
}
