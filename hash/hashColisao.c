#include "../include/hashOpenAdd.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    struct HTable *ha = (struct HTable *)malloc(sizeof(struct HTable));

    int numbers[12] = { 1 ,3 ,4 ,5 ,7 ,2 ,13 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // popula table
    for (int n = 0; n < size - 1; n++) {

        insereHTable(ha, numbers[n]);
    }
    // busca na table
    int busca = 9;
    // if (contidoHTable( ha, busca) == 1){
    //     printf(" O valor %d foi encontrado", busca);
    // } else {
    //     printf(" Não encontrado");
    // }
    
    imprimeHTable( ha );
    
    // destroiHTable( ha );
    
    // imprimeHTable( ha );

    return 0;

}