#include <stdio.h>      // printf
#include <unistd.h>     // sleep
#include <pthread.h>    // thread
#include <semaphore.h>  // sem_t
#include <stdlib.h>     // rand

sem_t saldo[2];
pthread_t transferencia[100];

struct args {
  long saldo1;
  long saldo2;
  int valor;
};
typedef struct args args;

args thread;

struct c {
  long saldo; //long por conta do tamanho de void* que é diferente de int
};
typedef struct c conta;

conta from, to;

void verificar_disponibilidade(long saldo1, long saldo2){
    sem_wait(&saldo[saldo1]);
    sem_wait(&saldo[saldo2]);
}

void re_disponibilizar(long saldo1, long saldo2){
  sem_post(&saldo[saldo1]);
  sem_post(&saldo[saldo2]);
}

void transferir(int valor,long *saldo_enviando,long *saldo_recebendo){
  if ( *saldo_enviando > valor){
    *saldo_enviando -= valor;
    *saldo_recebendo+= valor;
  }
};

void *transacao(void* arg){
  args *my_data;
  my_data = (args *) arg;
  long saldo_to = my_data->saldo1;
  long saldo_from = my_data->saldo2;
  int valor = my_data->valor;
  while (saldo_to > valor && saldo_from > valor){
    int tag = rand()%2; //se for igual a zero to envia e from recebe
  
    if (tag == 0){
      printf("Saldo To transferindo...\n");
      verificar_disponibilidade(0,1);
      transferir(valor,&saldo_to,&saldo_from);
      re_disponibilizar(0,1);
    }else{
      printf("Saldo From transferindo...\n");
      verificar_disponibilidade(0,1);
      transferir(valor,&saldo_from,&saldo_to);
      re_disponibilizar(0,1);
    }
    printf("Saldo to: %ld\n", saldo_to);
    printf("Saldo from: %ld\n", saldo_from);
  }
};

int main(){
  to.saldo = 1000;
  from.saldo = 1000;

  thread.saldo1 = to.saldo;
  thread.saldo2 = from.saldo;
  thread.valor = 10;

  sem_init(&saldo[0], 0, 1);
  sem_init(&saldo[1], 0, 1);

  for(int i = 0; i < 100; i++){
    pthread_create(&transferencia[i], NULL, transacao, (void *) &thread);
  }

    for (int i = 0; i < 100; i++) {
        pthread_join(transferencia[i], NULL);
        sem_destroy(&saldo[i]);
    }
}
