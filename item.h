#ifndef ITEM_H
#define ITEM_H

typedef struct
{
    int valor;
    int chave;
} ITEM;

ITEM *criar_item(int valor, int chave);
void apagar_item(ITEM **item);
void imprimir_item(ITEM *item);

#endif
