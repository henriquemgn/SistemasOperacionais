#include <stdio.h>      // printf
#include <unistd.h>     // sleep
#include <pthread.h>    // thread
#include <semaphore.h>  // sem_t
#include <stdlib.h>     // rand

sem_t saldo[2];               //Cria semaforo dos saldos
pthread_t transferencia[100]; //Cria threads para 100 transferencias ao mesmo tempo

//Argumentos para função das threads
struct args {
  long saldo1;
  long saldo2;
  int valor;
};
typedef struct args args;

//declarar o array da da struct
args thread;

struct c {
  long saldo; //long por conta do tamanho de void* que é diferente de int
};
typedef struct c conta;

conta from, to;

/***
    Funcao sem_wait ja testa automaticamente se o garfo esta 
    disponivel e so retorna valor quando ele estiver,
    logo nao e necessario um loop para testar se o garfo esta diposnivel
***/
//Ambos saldos devem estar disponiveis para nao ter problema na memória
void verificar_disponibilidade(long saldo1, long saldo2){
    sem_wait(&saldo[saldo1]);
    sem_wait(&saldo[saldo2]);
}

//re-disponibiliza ambos os saldos para a proxima transação
void re_disponibilizar(long saldo1, long saldo2){
  sem_post(&saldo[saldo1]);
  sem_post(&saldo[saldo2]);
}

//função para transferir
void transferir(int valor,long *saldo_enviando,long *saldo_recebendo){
  *saldo_enviando -= valor;
  *saldo_recebendo+= valor;
};

//função de cada thread
void *transacao(void* arg){
  args *my_data;                     //re-declara uma função para os argumentos
  my_data = (args *) arg;            //remove o cache de void
  
  // transfere os dados de args para variaveis mais legiveis
  long saldo_to = my_data->saldo1;   
  long saldo_from = my_data->saldo2;
  int valor = my_data->valor;
  
  while (saldo_to > valor && saldo_from > valor){ //imposibilita de transações serem feitas de o saldo for menor que o valor a transferir
    int tag = rand()%2;                           //se for igual a zero to envia e from recebe
  
    if (tag == 0){                                //Verifica se é o saldo To ou Saldo from que esta enviando
      printf("Saldo To transferindo...\n");
      verificar_disponibilidade(0,1);             //Verifica se saldo esta acessavel
      transferir(valor,&saldo_to,&saldo_from);    //Faz a transferencia
      re_disponibilizar(0,1);                     //Redisponibiliza saldo
    }else{
      printf("Saldo From transferindo...\n");     
      verificar_disponibilidade(0,1);             //Verifica se saldo esta acessave
      transferir(valor,&saldo_from,&saldo_to);    //Faz a transferencia
      re_disponibilizar(0,1);                     //Redisponibiliza saldo
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
    pthread_create(&transferencia[i], NULL, transacao, (void *) &thread); //Cria threads
  }

    for (int i = 0; i < 100; i++) {
        pthread_join(transferencia[i], NULL); //Verifica se thread finalizou
        sem_destroy(&saldo[i]);               //destroi semaforo
    }
}
