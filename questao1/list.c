#include <stdio.h>
#include <stdlib.h>
#include "../include/LDEncad.h"

int main() {
    // printf("Lista duplamente encadeada: considere a insercao sempre no final da lista ");

    struct No *lista = (struct No *)malloc(sizeof(struct No));
    int numbers[10] = { 1, 3, 4, 5, 8, 11 ,9, 10, 30};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));

    // popula lista
    for (int n = 0; n < size; n++) {
        insereLDEncad(lista, numbers[n]);
    }
    imprimeLDEncad(lista);
    
    // printf(" Adicionar um termo 27 a lista  ");
    // insereLDEncad(lista, 27);
    // imprimeLDEncad(lista);

    // printf(" Remover o primeiro elemento da lista  ");
    // removeLDEncad(lista , 5); 
    // imprimeLDEncad(lista);
    
    // #define busca 7
    // printf("Busca o termo x = %d na lista: ", busca);
    // if (contidoLDEncad(lista , 7))
    //     printf(" Contem o numero!");

    return 0;
}
