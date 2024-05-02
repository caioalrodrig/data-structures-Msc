#ifndef NO_H
#define NO_H

#define M 101

struct No {
    struct No *prox;
    int x;
};

struct HTable {
    int m;
    struct No **table;
};

void insereHTable( struct HTable *tb, int val);
int contidoHTable( struct HTable *tb, int val );
void imprimeHTable( struct HTable *tb );
void destroiHTable( struct HTable *tb );
void contidoChavesSoma( struct HTable *tb, int val );
int hash( int chave );

#endif 