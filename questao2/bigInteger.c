#include "..\include\PSEncad.h"
#include <stdio.h>
#include <stdlib.h>

/*
Considere duas listas encadeadas L1 e L2 representando números grandes (cada digito por nó).
Faça um algoritmo que faça a soma de dois inteiros grandes e retorne a lista L3 = L1 + L2.
*/

static int dezena = 0;

void somaNode ( struct No *p1, struct No *p2, struct Pilha *s3){
    
    int unidade;
    int resultado;
    
    if ( !p1 ){
        inserePSEncad(s3, p2->chave);
    }
    else if ( !p2 ){
        inserePSEncad(s3, p1->chave);
    }
    else{
        resultado = p1->chave + p2->chave + dezena;
        if ( resultado > 9){
            dezena = 1;
            unidade = resultado % 10;
        } else{
            dezena = 0;
            unidade = resultado;
        }
        inserePSEncad(s3, unidade);
    }
}

void somaBigInts( struct Pilha *s1, struct Pilha *s2, struct Pilha *s3){
    struct No *p1 = s1->top;
    struct No *p2 = s2->top;

    while (p1->prox != NULL && p2->prox != NULL){
        somaNode(p1, p2, s3);
        p1 = p1->prox;
        p2 = p2->prox;
    }

    somaNode(p1, p2, s3);
    if (dezena == 1){ //cria um novo digito se houver overflow de s3
        inserePSEncad(s3, 1);            
    }
}

int main(){
    struct Pilha *s1 = (struct Pilha *)malloc(sizeof(struct Pilha));
    struct Pilha *s2 = (struct Pilha *)malloc(sizeof(struct Pilha));
    struct Pilha *s3 = (struct Pilha *)malloc(sizeof(struct Pilha));

    int l1[10] = { 4, 3, 2, 5, 8, 7 ,9, 1, 4};
    int l2[10] = { 1, 3, 4, 5, 8, 1 ,9, 10, 3};

    int size = sizeof(l1) / sizeof(l1[0]);

    // popula fila
    for (int n = 0; n < size - 1; n++) {
        inserePSEncad(s1, l1[n]);
        inserePSEncad(s2, l2[n]);
    }
    imprimePSEncad(s1);
    imprimePSEncad(s2);
    
    somaBigInts(s1, s2, s3);
    return 0;

}