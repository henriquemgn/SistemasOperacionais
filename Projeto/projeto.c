#include <stdio.h>      // printf
#include <stdlib.h>     // rand
#include <unistd.h>     // sleep
#include <pthread.h>    // thread
#include <semaphore.h>  // sem_t
/***
Nome: Henrique Magno dos Santos
TIA: 42030471

        Fontes:
                Semaforos: 
                    https://www.geeksforgeeks.org/use-posix-semaphores-c/
                    https://greenteapress.com/thinkos/html/thinkos013.html
                    
                Threads:
                    https://embarcados.com.br/threads-posix/
                    
                Filosofos:
                    https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/
                    https://www.youtube.com/watch?v=NbwbQQB7xNQ
                    https://blog.pantuza.com/artigos/o-jantar-dos-filosofos-problema-de-sincronizacao-em-sistemas-operacionais
                    https://www.vivaolinux.com.br/script/Jantar-dos-Filosofos-Programacao-Paralela
***/

sem_t garfos[5];        // Cria o array de garfos com tipo semaforo
pthread_t Filosofos[5]; // Cria o array de filosofos com tipo Thread


/***
    Funcao sem_wait ja testa automaticamente se o garfo esta 
    disponivel e so retorna valor quando ele estiver,
    logo nao e necessario um loop para testar se o garfo esta diposnivel
***/

//Funcao para pegar o garfo
void pega_garfo(int esq, int dir){  
    sem_wait(&garfos[esq]);
    sem_wait(&garfos[dir]);
    
}

// Funcao para imprimir que terminou de comer e guardar o garfo
void guarda_garfo(int esq, int dir, int id){ 
    printf("Filosofo %d terminou de comer\n", id);
    sem_post(&garfos[esq]);
    sem_post(&garfos[dir]);        

}

// Funcao para imprimir que esta comendo e implementar o contador de quantas x comeu
int come(int id, int contador){
    printf("Filosofo %d esta comendo\n", id);
    sleep(rand() % 10);
    return contador+=1;
}

// Funcao para imprimir que esta pensando por um tempo
void pensa(int id){
    printf("Filosofo %d esta pensando\n", id);
    sleep(rand() % 10);
}

// Funcao principal que leva como argumento um ponteiro que se refere a o array de ids
void *Filosofo(void *arg) {
    
    int contador = 0;           //inicializar contador
    
    int id = *((int *) arg);    //passando para int o ponteiro que aponta para o array de ids
    int esq = id;               //garfo a esquerda tem o mesmo valor de id
    
    /***
        Garfo a direita tem o valor "oposto" ao id, exemplo id = 4 4+1%5 = 0
        logo o garfo a direita sera o primeiro do array de semaforos
    ***/
    int dir = (id + 1) % 5;     

    
    /*** 
        Enquanto todos nao estiverem comido 5x continuara,
        nao utilizei 1 como o maximo porque perderia o proposito da concorrencia
        diminuindo a concorrencia muito rapido
    ***/
    while (contador != 5) {

        pensa(id);                          // pensa
        pega_garfo(esq, dir);               // pega garfo
        contador = come(id, contador);      // come
        guarda_garfo(esq, dir, id);         // guarda o garfo
        
    }
    
    printf("Filosofo %d comeu 5x e se levantou. \n", id);   // avisa que terminou de comer e levanta
}

int main() {
    int i, ids[5];  // declaracao do i fora do for por ser usado 2x e declaracao do array de ids

    for (i = 0; i < 5; i++) {
        sem_init(&garfos[i], 0, 1);                                         // inicializar todos os semaforos garfos
        ids[i] = i;                                                         // inicializar o array de ids com cada id 0-4
        
        /***
         
          Criar threads leva como argumentos o array tipo pthread declarado no inicio do programa,
          NULL e usado como segundo argumento para declarar que ira utilizar atributos padrao para uma thread,
          Um ponteiro para a funcao que sera executada nas threads, no caso, Filosofo,
          E finalmente ponteiro que aponta para o array de ids
          
         ***/
        pthread_create(&Filosofos[i], NULL, Filosofo, (void *) &ids[i]);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(Filosofos[i], NULL);   // pthread_join aguarda até que a thread termine de rodar, no caso, ate comer 5x
        sem_destroy(&garfos[i]);            //entao, destroi o semaforo do garfo equivalente
    }

    return 0;
}
