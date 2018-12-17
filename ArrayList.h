#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"

#define TAM 10

typedef struct node
{
    ITEM **Lista;//lista interna de void
    int fim;//tamanho ocupado na lista
    int tamanho;//tamanho da lista interna
    struct node *prox; //ponteiro pro proximo no
    struct node *ant; //ponteiro pro no anterior (usei pra fazer shift principalmente)
} NO;

typedef struct
{
    NO *inicio;
    int qtd;
} ArrayList;

ArrayList *new_arrayList();//Cria a ArrayList e aloca toda memória necessaria
int add_arrayList(ArrayList *arrayList, ITEM *element);//adiciona elemento ao arraylist
int contains_arrayList(ArrayList *arrayList, int chave);//verifica no arraylist se existe um elemento com a chave informada
ITEM *get_arrayList(ArrayList *arrayList, int pos);//recupera um ITEM na posicao informada
int indexOf_arrayList(ArrayList *arrayList, int chave);//retorna qual a posicao do primeiro elemento com a chave informada
int isEmpty_arrayList(ArrayList *arrayList);//verifica se o arraylist esta vazio
int remove_arrayList(ArrayList *arrayList, int pos);//remove um elemento do arraylist
int set_arrayList(ArrayList *arrayList, int pos, ITEM *element);//modifica um elemento do arraylist
int size_arrayList(ArrayList *arrayList);//retorna o tamanho total do arraylist
ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex, int endIndex);//recupera um novo subarray no intervalo [beginIndex, endIndex[
int destruct_arrayList(ArrayList *arrayList);//desaloca memoria alocada pelo arraylist
void print_arrayList(ArrayList *arrayList);//imprime toda a lista

#endif

