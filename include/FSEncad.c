#include "FSEncad.h"
#include <stdlib.h>
#include <stdio.h>

void insereFSEncad( struct Fila *fila , int val ){
    struct Fila *queue = fila;
    struct No *no = (struct No *)malloc(sizeof(struct No));
    no->chave = val;

    if ( queue->head == NULL ){
    
        queue->lenght = 1;
        queue->tail = no;
        queue->head = no;
        return;
    }

    struct No *p = queue->head;
    while (p->prox != NULL){ // fim da fila
        p = p->prox;
    }
    p->prox = no;
    queue->lenght ++;
    queue->tail = no;

    return;
};

int contidoFSEncad(struct Fila *fila , int val ){
    struct Fila *q = fila;
    if ( q->head == NULL ){
        return;
    }

    struct No *p = q->head;
    while ( p->prox != NULL ){
        p = p->prox;
        if ( p->chave == val){
            return 1;
        }
    }
    if ( p->chave == val){
       return 1;
    }
    return 0;
};

void removeFSEncad( struct Fila *fila ){

    struct Fila *q = fila;
    if ( fila->head == NULL){
        printf("A fila já está vazia");
        return;
    }
    struct No *p = q->head;
    q->head = p->prox;
    free(p);
    
    return;
}

void imprimeFSEncad(struct Fila *fila) {
    if (fila->head == NULL){
        return;
    } 
    struct No *p = fila->head;

    while (p->prox != NULL) {
        printf("Val: %d ", p->chave);
        p = p->prox;
    }
    printf("Val: %d ", p->chave);
    return;

}