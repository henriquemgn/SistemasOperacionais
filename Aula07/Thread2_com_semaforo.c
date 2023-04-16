#include <stdio.h>      // printf
#include <stdlib.h>     // rand
#include <unistd.h>     // sleep
#include <pthread.h>    // thread
#include <semaphore.h>  // sem_t

long double sum = 0;
int thread_count = 2;
int n = 100000;
sem_t liberado[1];        // Cria o array de garfos com tipo semaforo
pthread_t calculadoras[2]; // Cria o array de filosofos com tipo Thread

void calculadora_livre(){  
    sem_wait(&liberado[0]);
}

void calculadora_usada(){
    sem_post(&liberado[0]);
}

void *calcula(void *arg){
    long my_rank = (long) arg;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
  
    for(i = my_first_i; i < my_last_i; i++){
        if(i % 2 == 0){
            calculadora_livre();
            sum += (1.0/(2* i+1));
            calculadora_usada();
        }else{
            calculadora_livre();
            sum += ((-1.0)/(2* i+1));
            calculadora_usada();
        }
      
    }
    return NULL;
}

int main()
{
    sem_init(&liberado[0], 0, 1);

    for(long i = 0; i < thread_count; i++){
        pthread_create(&calculadoras[i], NULL, calcula, (void *) i);
    }

    for (int i = 0; i < thread_count; i++){
        pthread_join(calculadoras[i], NULL); 
    }
    
    printf("Sum = %Lf\n", 4*sum);
    return 0;
}
