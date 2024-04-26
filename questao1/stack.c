#include <stdio.h>
#include <stdlib.h>
#include "../include/PSEncad.h"

int main(){
    struct Pilha *stack = (struct Pilha *)malloc(sizeof(struct Pilha));

    int numbers[10] = { 1, 3, 4, 5, 8, 11 ,9, 10, 30};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // popula fila
    for (int n = 0; n < size - 1; n++) {
        inserePSEncad(stack, numbers[n]);
    }
    imprimePSEncad(stack);

    printf(" Remover elemento da pilha:  ");
    removePSEncad(stack); 
    imprimePSEncad(stack);
    
    #define x 30
    printf("Busca o termo x = %d na pilha: ", x);
    if (contidoPSEncad(stack , 5) == 1)
        printf(" Contem o numero!");
    
    return 0;

}