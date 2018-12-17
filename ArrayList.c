#include "ArrayList.h"

ArrayList *new_arrayList()  //cria o arraylist
{
    ArrayList *A;

    A = (ArrayList*)malloc(sizeof(ArrayList));
    if(A != NULL)
    {
        A->inicio = NULL;
        A->qtd = 0;
    }

    return A;
}

void shift_direita(NO *ponteiro, int pos)
{
    int i;
    NO *aux, *aux2;

    aux = ponteiro;

    while(aux!=NULL)
    {
        aux2 = aux;
        aux = aux->prox;
    }
    if(aux2->fim >= aux2->tamanho)  //ultimo no esta cheio
    {
        aux = (NO*)malloc(sizeof(NO));
        if(aux != NULL)
        {
            aux->tamanho = aux2->tamanho*2;
            aux->Lista = (ITEM**)malloc(aux->tamanho*sizeof(ITEM*));
            aux->fim = 1; //no shift vc coloca um elemento no ultimo nó
            aux->prox = NULL;
            aux->ant = aux2;
        }
    }
    else
    {
        aux2->fim++;
    }
    aux = aux2;
    while(aux!=ponteiro)
    {
        for(i=aux->fim; i>0; i--)
        {
            aux->Lista[i] = aux->Lista[i-1];
        }
        aux->Lista[0] = aux->ant->Lista[aux->ant->fim-1];
        aux = aux->ant;
    }
    if(aux == ponteiro)
    {
        for(i=aux->fim; i>pos; i--)
        {
            aux->Lista[i] = aux->Lista[i-1];
        }
    }
}


int add_arrayList(ArrayList *arrayList, ITEM *element)
{
    NO *aux, *aux2;
    int i;
    //CASO 1: vazio, cria o primeiro nó
    if(isEmpty_arrayList(arrayList))
    {
        aux = (NO*)malloc(sizeof(NO));
        if(aux != NULL)
        {
            aux->tamanho = TAM;
            aux->Lista = (ITEM**)malloc(aux->tamanho*sizeof(ITEM*));
            aux->fim = 0;
            aux->prox = NULL;
            aux->ant = NULL;
        }
        else
        {
            return 0;
        }
        arrayList->inicio = aux;
        arrayList->qtd=1;
        aux->Lista[aux->fim] = element;
        aux->fim++;
        return 1;
    }
    else
    {
        aux = arrayList->inicio;
        aux2 = aux;
        //CASO 2: element nao eh o maior elemento
        while(aux!=NULL)
        {
            for(i=0; i<aux->fim; i++)
            {
                if(aux->Lista[i]->chave > element->chave)
                {
                    shift_direita(aux, i);
                    aux->Lista[i] = element;
                    //aux->fim++;
                    arrayList->qtd++;
                    return 1;
                }
            }
            aux2=aux;
            aux=aux->prox;
        }
        //CASO 3: element é o maior elemento:
        if(aux2->fim < aux2->tamanho)  //vetor do ultimo aux analisado nao esta cheio
        {
            aux2->Lista[aux2->fim] = element;
            aux2->fim++;
            arrayList->qtd++;
            return 1;
        }
        else
        {
            aux = (NO*)malloc(sizeof(NO));
            if(aux != NULL)
            {
                aux->tamanho = aux2->tamanho*2;
                aux->Lista = (ITEM**)malloc(aux->tamanho*sizeof(ITEM*));
                aux->fim = 0;
                aux->prox = NULL;
                aux->ant = aux2;
            }
            else
            {
                return 0;
            }
            aux2->prox = aux;
            aux->Lista[aux->fim] = element;
            aux->fim++;
            arrayList->qtd++;
            return 1;
        }
    }
    return 0;
}

int clear_arrayList(ArrayList *arrayList)
{
    NO *aux, *aux2;
    aux = arrayList->inicio;
    aux2 = aux;
    while(aux!=NULL)
    {
        aux = aux->prox;
        free(aux2->Lista);
        free(aux2);
        aux2 = aux;
    }
    arrayList->inicio = NULL;
    arrayList=0;
    return 1;
}

ArrayList *clone_arrayList(ArrayList *arrayList)
{
    ArrayList *ar;
    NO *aux;
    int i;

    ar = new_arrayList();

    aux = arrayList->inicio;
    while(aux!=NULL)
    {
        for(i=0; i<aux->fim; i++)
        {
            add_arrayList(ar,criar_item(aux->Lista[i]->chave,aux->Lista[i]->valor));
        }
        aux = aux->prox;
    }
    return ar;
}


int contains_arrayList(ArrayList *arrayList, int chave)
{
    NO *aux;
    int d, e, m;

    aux = arrayList->inicio;
    while(aux!=NULL)
    {
        if(aux->Lista[aux->fim-1]->chave < chave)
            aux = aux->prox;
        else
        {
            d = aux->fim-1;
            e = 0;
            m = (d+e)/2;
            while(d >= e)
            {
                if(aux->Lista[m]->chave == chave)
                    return 1;
                else
                {
                    if(chave > aux->Lista[m]->chave)
                        e = m+1;
                    else
                    {
                        d = m-1;
                    }
                    m = (e+d)/2;
                }
            }
            return 0;
        }
    }
    return 0;
}


ITEM *get_arrayList(ArrayList *arrayList, int pos)
{
    int i;
    NO *aux;

    i = TAM;
    aux = arrayList->inicio;
    if(pos > size_arrayList(arrayList))
    {
        return NULL;
    }

    while(pos>i-1)
    {
        pos = pos - i;
        i=i*2;
        aux=aux->prox;
    }

    return criar_item(aux->Lista[pos]->valor,aux->Lista[pos]->chave);
}

int indexOf_arrayList(ArrayList *arrayList, int chave)
{
    NO *aux;
    int d, e, m;
    int taman = 0;

    aux = arrayList->inicio;
    while(aux!=NULL)
    {
        if(aux->Lista[aux->fim-1]->chave < chave)
        {
            taman = taman + aux->tamanho;
            aux = aux->prox;
        }
        else
        {
            d = aux->fim-1;
            e = 0;
            m = (d+e)/2;
            while(d >= e)
            {
                if(aux->Lista[m]->chave == chave)
                {
                    return m+taman;
                }
                else
                {
                    if(chave > aux->Lista[m]->chave)
                        e = m+1;
                    else
                    {
                        d = m-1;
                    }
                    m = (e+d)/2;
                }
            }
            return -1;
        }
    }
    return -1;
}


int isEmpty_arrayList(ArrayList *arrayList)
{
    if(arrayList->inicio == NULL)
        return 1;
    return 0;
}

void shift_esquerda(NO *ponteiro, int pos)
{
    NO *aux;
    int i;

    aux = ponteiro;
    while(aux!=NULL)
    {
        for(i=pos; i<aux->fim-1; i++)
        {
            aux->Lista[i] = aux->Lista[i+1];
        }
        if(aux->prox != NULL)
        {
            aux->Lista[aux->fim-1] = aux->prox->Lista[0];
            pos = 0;
        }
        else
        {
            aux->fim--;
            if(aux->fim == 0)  //se o ultimo no só tem 1 elemento
            {
                aux=aux->ant;
                free(aux->prox->Lista);
                free(aux->prox);
                aux->prox = NULL;
            }
        }
        aux = aux->prox;
    }
}

int remove_arrayList(ArrayList *arrayList, int pos)
{
    int i;
    NO *aux;

    i = TAM;
    aux = arrayList->inicio;
    if(pos > size_arrayList(arrayList))
    {
        return 0;
    }

    while(pos>i-1)
    {
        pos = pos - i;
        i=i*2;
        aux=aux->prox;
    }


    if(pos >= aux->fim)
        return 0;
    else
    {
        free(aux->Lista[pos]);
        shift_esquerda(aux, pos);
        arrayList->qtd--;
        return 1;
    }
}


int set_arrayList(ArrayList *arrayList, int pos, ITEM *element)
{
    /*Como tem que manter a lista ordenada, modificar um item tem que apagar o item e inserir o novo*/
    if(remove_arrayList(arrayList, pos))
    {
        if(add_arrayList(arrayList, element))
            return 1;
    }
    return 0;
}


int size_arrayList(ArrayList *arrayList)
{
    return arrayList->qtd;
}

ArrayList *subArray_arrayList(ArrayList *arrayList, int beginIndex, int endIndex)
{
    int i;
    NO *aux, *aux2;
    ArrayList *ar;

    if(endIndex > beginIndex)
    {
        i = TAM;
        aux = arrayList->inicio;

        while(beginIndex>i-1)
        {
            beginIndex = beginIndex - i;
            i=i*2;
            aux=aux->prox;
        }

        i = TAM;
        aux2 = arrayList->inicio;

        while(endIndex>i-1)
        {
            endIndex = endIndex - i;
            i=i*2;
            aux2=aux2->prox;
        }

        ar = new_arrayList();

        while(aux != NULL && aux!=aux2)
        {
            for(i=beginIndex; i<aux->fim; i++)
                add_arrayList(ar,criar_item(aux->Lista[i]->valor, aux->Lista[i]->chave));
            aux = aux->prox;
            beginIndex = 0;
        }

        if(aux != NULL)
        {
            for(i=beginIndex; i<endIndex; i++)
                add_arrayList(ar,criar_item(aux->Lista[i]->valor, aux->Lista[i]->chave));
        }
        return ar;
    }
    return NULL;

}

int destruct_arrayList(ArrayList *arrayList)
{
    NO *aux;
    int i;

    aux = arrayList->inicio;
    while(aux!=NULL)
    {
        for(i=0; i<aux->fim; i++)
            free(aux->Lista[i]);
        free(aux->Lista);
        aux = aux->prox;
        if(aux!=NULL)
            free(aux->ant);
    }
    free(arrayList);
    arrayList = NULL;
    return 1;
}

void print_arrayList(ArrayList *arrayList)
{
    NO *aux;
    int i, j;

    aux = arrayList->inicio;

    j = 0;
    while(aux!=NULL)
    {
        for(i=0; i<aux->fim; i++)
        {
            printf("%d: ", j);
            printf("%d/%d\n", aux->Lista[i]->chave, aux->Lista[i]->valor);
            j++;
        }
        aux = aux->prox;
        printf("\n\n");
    }

}
