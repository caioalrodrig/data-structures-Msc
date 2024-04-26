#ifndef NO_H
#define NO_H

typedef struct Pilha{
    int lenght;
    struct No *top;
};

typedef struct No{
    struct No *prox;
    int chave;
};

void inserePSEncad( struct Pilha *pilha , int );
void removePSEncad( struct Pilha *pilha);
int contidoPSEncad( struct Pilha *pilha, int );
void imprimePSEncad( struct Pilha *pilha);



#endif 