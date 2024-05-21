#include <stdio.h>
#include <stdlib.h>
#include "../include/BST.h"

void insereBST( Tree *raiz, int val){ 

    struct No *no = (struct No *)malloc(sizeof(struct No));
    no->info = val;
    no->esq = NULL;
    no->dir = NULL;
    
    if (*raiz == NULL) {
        *raiz = no;
        return;
    }
    struct No* atual = *raiz;
    struct No* ant = atual;
    while (atual != NULL) {
        ant = atual;
        if (val == atual->info) return;
        if (val < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    // reach leaf
    if (val < ant->info) {
        ant->esq = no;
    } else {
        ant->dir = no;
    }

}

int contidoBST( Tree *raiz, int valor){
    if (!raiz || *raiz == NULL) return 0;

    struct No* atual = *raiz;
    while (atual != NULL) {
        if (valor == atual->info) return 1;
        if (valor < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    return 0;
}

struct No* removeAtualBST( struct No *atual ){
    struct No *no1, *no2;
    if( atual->esq == NULL ) {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    // Find rightmost node in the left subtree  
    no1 = atual;
    no2 = atual->esq;
    while( no2->dir != NULL ){
        no1 = no2;
        no2 = no2->dir;
    }
    if (no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;

}

void removeBST( Tree *raiz, int val){ 
    if (!raiz || *raiz == NULL) {
        return;
    }

    struct No* atual = *raiz;
    struct No* ant = NULL;
    while ( atual != NULL ) {
        if( atual->info == val ) {
            if( ant == NULL ) *raiz = removeAtualBST(atual);
            else{
                if ( ant->dir == atual ) ant->dir = removeAtualBST(atual);
                else ant->esq = removeAtualBST(atual);
            }
            return;
        }
        // level decrease
        ant = atual;
        if (val < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
}

void insereCodeBST( Tree *raiz, int altura, int codeAtual){
    /*func: debug tree*/
    if (!raiz || *raiz == NULL) return;
    struct No *atual = *raiz;
    printf("%d", codeAtual);
    if( atual->esq != NULL ) insereCodeBST(&(atual->esq), altura+1, 0);
    if( atual->dir != NULL ) insereCodeBST(&(atual->dir), altura+1, 1);
}

void imprimeBST( Tree *raiz ){
    
    if ( !raiz || !*raiz ) return;
    imprimeBST(&((*raiz)->esq));
    printf(" No: %d \n", (*raiz)->info);
    imprimeBST(&((*raiz)->dir));

}

int main(){
      
    Tree raiz = NULL;

    insereBST(&raiz, 10);
    insereBST(&raiz, 9);
    insereBST(&raiz, 12);
    insereBST(&raiz, 7);
    insereBST(&raiz, 4);

    imprimeBST(&raiz);
    printf("\n");

    if (contidoBST(&raiz, 6) == 1) printf("Valor encontrado");
    // removeBST(&raiz, 9);
    imprimeBST(&raiz);

    printf("\n");
    insereCodeBST(&raiz, 0, 9);

    return 0;

}