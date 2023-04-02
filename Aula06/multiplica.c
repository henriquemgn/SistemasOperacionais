#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define TAMANHO 3

void *multiplica(void *args) {
    int *arg = (int *) args;
    int n = arg[0];
    int cont = arg[1];
    
    int *resultado = (int *) malloc(TAMANHO * sizeof(int));
    int array[TAMANHO][TAMANHO] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    int vetor[TAMANHO] = {2, 2, 2};
    
    printf("Thread %i multiplicando liha %i\n", cont, cont);
    
    for (int i = 0; i < n; i++) {
        resultado[i] = array[cont][i] * vetor[i];
    }
    
    pthread_exit(resultado);
}


int main()
{
    int i;
    pthread_t linhas[TAMANHO];
    
    int args[TAMANHO][2];
    for (i = 0; i < TAMANHO; i++) {
        args[i][0] = TAMANHO;
        args[i][1] = i;
        pthread_create(&linhas[i], NULL, multiplica, (void *) &args[i]);
    }
    
    int resultados[TAMANHO][TAMANHO];
    
    for ( i = 0; i < TAMANHO; i++){
        void* res;
        pthread_join(linhas[i], &res);
        int* res_array = (int*)res;
        for (int j = 0; j < TAMANHO; j++){
            resultados[i][j] = res_array[j];
        }
        free(res_array);
    }
    
    printf("\nResultados:\n");
    for (i = 0; i < TAMANHO; i++){
        printf("[%d, %d, %d]\n", resultados[i][0], resultados[i][1], resultados[i][2]);
    }

    return 0;
}
