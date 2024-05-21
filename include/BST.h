/*
    -Binary -Search -Tree
*/

#ifndef NO_H
#define NO_H
#define M 20


struct No {
    int info;
    struct No *esq;
    struct No *dir;
};

typedef struct No *Tree;

void insereBST( Tree *raiz, int val );
void removeBST( Tree *raiz, int val );
struct No* removeAtualBST(struct No *no);
void insereCodeBST(Tree *raiz, int altura, int codesAtual);
int contidoBST( Tree *raiz, int val );
int checkBST(Tree *raiz);
void imprimeBST(Tree *raiz);
void destroiBST(Tree *raiz);

#endif 