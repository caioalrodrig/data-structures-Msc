#ifndef NO_H
#define NO_H

typedef struct Fila{
    int lenght;
    struct No *head;
    struct No *tail; 
};

typedef struct No{
    struct No *prox;
    int chave;
};

void insereFSEncad( struct Fila *fila, int );
void removeFSEncad( struct Fila *fila );
int contidoFSEncad( struct Fila *fila, int );
void imprimeFSEncad( struct Fila *fila);


#endif 
