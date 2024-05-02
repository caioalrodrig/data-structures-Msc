#include "hashEncadExt.h"
#include <stdio.h>
#include <stdlib.h>

int hash(int chave){
    return chave % 7;
}

void insereHTable( struct HTable *ha, int val ){
    //complexidade O(1)
    int idx = hash(val);
    
    struct No *no = (struct No *)malloc(sizeof(struct No));
    no->x = val;

    if ( !ha->table[idx] ) {
        ha->table[idx] = no;
    } 
    else {
        no->x = val;
        no->prox = ha->table[idx]->prox;
        ha->table[idx]->prox = no;
    }
}

int contidoHTable( struct HTable *ha, int val ) {
    // complexidade O(n) pior caso e O(1/[1+FC]) no caso médio
    int idx = hash(val);
    struct No *p = (struct No *)malloc(sizeof(struct No));
    p = ha->table[idx];
    
    if ( p->x == val ) {
        return 1;
    }
    while ( p->prox != NULL){
        if ( p->prox->x == val){
            return 1;
        }
        p = p->prox;
    }

    return 0;

}

void imprimeHTable( struct HTable *ha ){
    int cont = 0;
    while (cont < ha->m ){
        if( ha->table[cont] ){
            printf( " Val: %d ", ha->table[cont]->x);
            while ( ha->table[cont]->prox != NULL){
                printf( " Val: %d ", ha->table[cont]->prox->x);
                ha->table[cont] = ha->table[cont]->prox;
            }
        }
        cont++;
    }
}

void destroiHTable( struct HTable *ha ){
    // complexidade O(n) no pior caso
    int cont = 0;
    struct No *p;
    struct No *aux;

    while ( cont < ha->m && ha->table[cont] ){
        p = ha->table[cont];
        if ( p->prox ){ //remoção de LSEncad na cabeça
            aux = p->prox;
            while ( aux->prox != NULL){ 
                free( ha->table[cont]->prox );
                ha->table[cont]->prox = aux->prox;
            }
        }
        cont++;
    }
    
    free( ha );
}
