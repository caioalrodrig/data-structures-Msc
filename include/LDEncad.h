#ifndef NO_H
#define NO_H

struct No {
    struct No *prox; 
    struct No *ant;
    int chave; 
};

void insereLDEncad( struct No *list , int val );
void removeLDEncad( struct No *list , int val );
int contidoLDEncad( struct No *list, int val );
void imprimeLDEncad( struct No *list );

#endif 
