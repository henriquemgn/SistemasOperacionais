#include <stdio.h>      // printf
#include <stdlib.h>     // rand
#include <unistd.h>     // sleep
#include <pthread.h>    // thread

long double sum = 0;
int thread_count = 2;
int n = 100000;
pthread_t calculadoras[2]; // Cria o array de filosofos com tipo Thread

void *calcula(void *arg){
    long my_rank = (long) arg;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
  
    for(i = my_first_i; i < my_last_i; i++){
        if(my_first_i % 2 == 0){
            sum += (1.0/(2* i+1));
        }else{
            sum += ((-1.0)/(2* i+1));
        }
      
    }
    return NULL;
}

int main()
{
    for(long i = 0; i < thread_count; i++){
        pthread_create(&calculadoras[i], NULL, calcula, (void *) i);
    }

    for (int i = 0; i < thread_count; i++){
        pthread_join(calculadoras[i], NULL); 
    }
    
    printf("Sum = %Lf\n", 4*sum);
    return 0;
}
