#include <stdio.h>

struct reg {
    int conteudo; 
    struct reg *prox; 
}; 
typedef struct reg celula;

celula a;
celula b;
celula c;

celula* remover(celula* head, int remover) {
    celula* headaux = head;
    celula* anterior = NULL;

    while (head != NULL) {
        if (head->conteudo == remover) {
            if (anterior == NULL) {
                headaux = head->prox;
            } else {
                anterior->prox = head->prox;
                
            }
            return headaux;
        }
        anterior = head;
        head = head->prox;
    }
    free(head);
    return headaux;
}

void tamanho(celula a){
  printf("Tamanho é %d bytes\n",sizeof(a));
}

void printLista(celula head){
  printf("Lista {");
  while(head.prox != NULL){
    printf("%d, ",head.conteudo);
    head = *head.prox;
  }
  if (head.prox == NULL){
    printf("%d}\n",head.conteudo);
  }
}

int main(void) {
  a.conteudo = 1;
  a.prox = &b;
  b.conteudo = 2;
  b.prox = &c;
  c.conteudo = 3;
  c.prox = NULL;

  printLista(a);
  tamanho(a);
  a = *remover(&a,2);
  printLista(a);
  return 0;
}
