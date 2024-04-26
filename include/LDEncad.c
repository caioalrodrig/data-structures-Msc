#include "LDEncad.h"
#include <stdio.h>
#include <stdlib.h>

void insereLDEncad(struct No *list, int val) {
    struct No *no = (struct No *)malloc(sizeof(struct No));
    no->chave = val; 

    if (list->prox == NULL) { // Lista vazia
        list->prox = no;
        no->ant = list;
        return;
    } else {
        struct No *p = list;
        while (p->prox != NULL) {
            p = p->prox;
        }    
        p->prox = no;
        no->ant = p;
    }
    return;
}

void imprimeLDEncad(struct No *list) {

    if (list->prox == NULL){
        return;
    } 
    struct No *p = list->prox;
    while (p->prox != NULL) {
        printf("Val: %d ", p->chave);
        p = p->prox;
    }
    printf("Val: %d ", p->chave);
    return;

}

void removeLDEncad( struct No *list , int pos){
    struct No *p = list;
    int n = 0;

   if (p->prox == NULL) {
        printf("Lista já está vazia!\n");
        return;
    }
    // Busca por varredura
    while (p->prox != NULL && n != pos) {
        p = p->prox;
        n++;
    }

    if (p == list) { // é o primeiro?
        list = p->prox;
        
        if (list != NULL) {
            list->ant = NULL;
        }
        free(p);
        return;
    }
    
    if ( p->prox == NULL){ // é o último?
        free(p);
        return;
    }

    p->ant->prox = p->prox;
    free(p);
    return;

};

int contidoLDEncad(struct No *list , int val ){
    struct No *p = list;
    if (p->prox == NULL) {
        printf("Lista está vazia!\n");
        return 0;
    }
    
    while ( p->prox != NULL){
        p = p->prox;
        if ( p->chave == val){
            return 1;
        }
    }
    
    return 0;

}

