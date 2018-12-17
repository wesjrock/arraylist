#include "item.h"

#include <stdlib.h>
#include <stdio.h>

ITEM *criar_item(int valor, int chave)  //a funcao poderia se chamar aloca
{
    ITEM *item = (ITEM *)malloc(sizeof(ITEM)); //cria e aloca valor e chave

    if(item != NULL)
    {
        item->valor = valor;
        item->chave = chave;
    }

    return item;
}


void apagar_item(ITEM **item)   //a funcao poderia se chamar desalcoca
{
    if(item != NULL && *item != NULL)   //item poderia ser ponteiro comum, aí os outros dentro da função seriam sem ponteiro
    {
        free(*item);
        *item = NULL;
    }
}

void imprimir_item(ITEM *item)
{
    if(item != NULL)
    {
        printf("%d - %d\n", item->chave, item->valor);
    }
}
