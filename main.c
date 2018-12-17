#include "ArrayList.h"
#include "item.h"

#include<stdio.h>

int main()
{

    char str[50];
    int a,b,c, i;
    ArrayList *ar, *ar2;
    ITEM *it;

    ar = new_arrayList();

    scanf("%s", str);
    while(strcasecmp(str,"sair"))
    {
        if(!strcasecmp(str,"tamanho"))
        {
            printf("%d\n", size_arrayList(ar));
        }
        else
        {
            if(!strcasecmp(str,"add"))
            {
                scanf("%d %d", &a, &b);
                getchar();
                add_arrayList(ar, criar_item(b,a));
            }
            else
            {
                if(!strcasecmp(str,"sub"))
                {
                    scanf("%d %d", &a, &b);
                    getchar();
                    ar2 = subArray_arrayList(ar, a, b);
                    print_arrayList(ar2);
                    destruct_arrayList(ar2);
                    ar2=NULL;
                }
                else
                {
                    if(!strcasecmp(str,"set"))
                    {
                        scanf("%d %d %d", &a, &b, &c);
                        getchar();
                        set_arrayList(ar, a, criar_item(c, b));
                    }
                    else
                    {
                        if(!strcasecmp(str,"print"))
                        {
                            print_arrayList(ar);
                        }
                        else
                        {
                            if(!strcasecmp(str,"contem"))
                            {
                                scanf("%d", &a);
                                getchar();
                                printf("%d\n", contains_arrayList(ar, a));
                            }
                            else
                            {
                                if(!strcasecmp(str,"vazia"))
                                {
                                    printf("%d\n", isEmpty_arrayList(ar));
                                }
                                else
                                {
                                    if(!strcasecmp(str,"remover"))
                                    {
                                        scanf("%d", &a);
                                        getchar();
                                        remove_arrayList(ar, a);
                                    }
                                    else
                                    {
                                        if(!strcasecmp(str,"get"))
                                        {
                                            scanf("%d", &a);
                                            getchar();
                                            it = get_arrayList(ar, a);
                                            if(it!=NULL)
                                                printf("%d/%d\n", it->chave, it->valor);
                                        }
                                        else
                                        {
                                            if(!strcasecmp(str,"indice"))
                                            {
                                                scanf("%d", &a);
                                                getchar();
                                                b = indexOf_arrayList(ar,a);
                                                if(b>=0)
                                                    printf("%d\n", b);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        scanf("%s", str);
    }
    destruct_arrayList(ar);


    return 0;
}
