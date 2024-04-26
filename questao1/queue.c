#include <stdio.h>
#include <stdlib.h>
#include "../include/FSEncad.h"

int main(){
    struct Fila *queue = (struct Fila *)malloc(sizeof(struct Fila));

    int numbers[10] = { 1, 3, 4, 5, 8, 11 ,9, 10, 30};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // popula fila
    for (int n = 0; n < size - 1; n++) {
        insereFSEncad(queue, numbers[n]);
    }
    imprimeFSEncad(queue);

    printf(" Remover elemento da lista:  ");
    removeFSEncad(queue); 
    imprimeFSEncad(queue);
    
    #define x 30
    printf("Busca o termo x = %d na lista: ", x);
    if (contidoFSEncad(queue , 5) == 1)
        printf(" Contem o numero!");
    
    return 0;

}