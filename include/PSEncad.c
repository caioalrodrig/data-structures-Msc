#include "PSEncad.h"
#include <stdio.h>
#include <stdlib.h>

void inserePSEncad( struct Pilha *pilha , int val ){
    struct No *no = (struct No *)malloc(sizeof(struct No));
    no->chave = val; 

    if ( pilha->top == NULL){
        pilha->top = no;
        return;
    } 

    struct Pilha *s = pilha;
    struct No *p = s->top;
    no->chave = val;
    no->prox = s->top; 
    s->top = no; 

    return;
    
};

int contidoPSEncad(struct Pilha *pilha , int val ){
    struct Pilha *s = pilha;
    if ( s->top == NULL ){
        return;
    }

    struct No *p = s->top;
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

void removePSEncad( struct Pilha *pilha ){

    struct Pilha *s = pilha;
    if ( pilha->top == NULL){
        printf("A pilha já está vazia");
        return;
    }
    struct No *p = s->top;
    s->top = p->prox;
    free(p);
    
    return;
}

void imprimePSEncad(struct Pilha *pilha) {
    if (pilha->top == NULL){
        return;
    } 
    struct No *p = pilha->top;

    while (p->prox != NULL) {
        printf("Val: %d ", p->chave);
        p = p->prox;
    }
    printf("Val: %d ", p->chave);
    return;

}