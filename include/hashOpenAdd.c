#include "hashOpenAdd.h"
#include <stdio.h>
#include <stdlib.h>

int hash(int chave){
    
    return chave % 7 % M;
}

int hash2 (int chave){
    int x = chave*2 % 17 % M;
    return x % 2 == 0? x+1 : x;
}

int doubleProbe( int idx, int chave, int i){    
    int h2 = hash2(chave);
    return (idx + h2*i) % M;
}

int linearProbe( int idx){
    return ++idx;
}

void insereHTable( struct HTable *ha, int val){
    
    int i = 1;
    int idx = hash( val );
    int idxNew;
    if ( !ha->tb[idx] ){

        ha->tb[idx] = val;
        return;
    }
    /*sondagem linear*/   /*sondagem dupla*/
    /* */
    idxNew = linearProbe(idx);
    idxNew = doubleProbe(idx, val, 1);
    for ( int cont = 1; cont < M+1; cont++ ){

        if ( !ha->tb[idxNew] ){

            ha->tb[idxNew] = val;
            return;        
        }
        /* */
        idxNew = doubleProbe(idx, val, cont);
        idxNew = linearProbe(idxNew);
        if ( idxNew > M-1 ){

            idxNew = 0;
        }
    }
}

void imprimeHTable(struct HTable *ha){
    
    for ( int cont = 0; cont < M; cont++ ){

        if ( ha->tb[cont] ){

            printf("Val: %d", ha->tb[cont] );
        }
    }

}

/*
8) Faça um algoritmo que recebe um vetor com inteiros não negativos podendo ter repetições e um
dado valor inteiro x. O algoritmo deve retornar o par de valores cuja a soma seja igual a x. Por
exemplo, para o vetor [3, 7, 5, 4] e x = 8 a resposta seria (3, 5). Para o vetor [3, 7, 4, 4] e x = 8, o

vetor seria (4,4). Contudo, para x = 20, não haveria resposta. Pense em soluçõs para o problema
abaixo considerando que a complexidade de tempo deve ser linear.
a) O vetor passado como entrada está ordenado e a complexidade de espaço é O(1)
b) O vetor passado como entrada não está ordenado e a complexidade de espaço é (n)

*/

void contidoChavesSoma( struct HTable *ha, int val ){
    int i = 1;
    int diferenca;
    int idx;
    int idxNew;
    if ( val % 2 == 0){
        idx =  hash(val/2);
        if ( ha->tb[idx]){
            printf(" Posicao encontrada: %d,%d",idx ,idx );
            return;
        }
    }
    idx = 0;
    while( idx < M  ){ 
        // varre a hash para achar o primeiro compartimento ocupado
        if( ha->tb[idx] ){ 
            diferenca = val - ha->tb[idx]; 
            idxNew = hash(diferenca);
            if ( ha->tb[idxNew] == diferenca ){
                //o complemento do elemento (diferenca) existe?
                printf(" Posicao encontrada: %d,%d ",idx ,idxNew );
                return;
            }
        }
        idx++;
    }
    printf("Não encontrado");
}