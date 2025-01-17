#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    void *data;
    struct Node *next;
}Node;

typedef struct Linkedlist{
        Node *head;
}Linkedlist;

void printList(Linkedlist *l);
void insertLast(Linkedlist *l,int d);
void insertFirst(Linkedlist *l, int d);
void deleteElem(Linkedlist *l,int d);
Linkedlist *mergeLists(Linkedlist *lone, Linkedlist *ltwo);
Node *splitList(Node *ini, Node *fin);
Linkedlist *mergeSortList(Node *ini, Node *fin);


void main(){


    Linkedlist *L1 = (Linkedlist*)(malloc(sizeof(Linkedlist)));
    Linkedlist *L2 = (Linkedlist*)(malloc(sizeof(Linkedlist)));
    int N1;
    int N2;
    int e;

    printf("Give me the size of your first list: \n");
    scanf("%d", &N1);
    
    

    printf("Give me the elements for list 1: \n");
    int i;
    for(i=0;i<N1;i++)
    {
        scanf("%d",&e);
        insertLast(L1,e);
    }


    printf("\n");
    Linkedlist *res = mergeSortList(L1->head,NULL);
    printList(res);
    printf("\n");


}

void printList(Linkedlist *l){

    if(l->head == NULL)
    printf("Your list is empty \n");
    else{
        Node *aux = l->head;
        while(aux != NULL){
            printf("%d ",*(int*)aux->data);
            aux = aux->next;
            }
    }

}

//Why initiliazing void pointer or mallocing them?
void insertLast(Linkedlist *l, int d){

    Node *n = (Node*)(malloc(sizeof(Node)));
    n->data = malloc(sizeof(int));
    *(int*)n->data = d;

    if(l->head == NULL)
    l->head = n;
    else{
        Node *aux = l->head;
        while( aux->next != NULL)
        aux = aux->next;
        
        aux->next = n;
    }
    
}


void insertFirst(Linkedlist *l, int d){
    Node *n = (Node*)(malloc(sizeof(Node)));
    n->data = malloc(sizeof(int));
    *(int*)n->data = d;

    if(l->head == NULL)
    l->head = n;
    else{
        n->next = l->head;
        l->head = n;
    }
}


void deleteElem(Linkedlist *l,int d){

    if(l->head == NULL)
    printf("Your element is not found because your list is empty \n");
    else{
        Node *aux = l->head;
        Node *prev = NULL;
        bool b = false;

        while(aux != NULL && !b){

            if(*(int*)aux->data == d)
            b = true;
            else{
                prev = aux;
                aux = aux->next;
            }
        }

        if(b){
            if(prev == NULL)
            l->head = l->head->next;
            else prev->next = aux->next;
        }else printf("Element is not found \n");
    }
}


//Merge sort with linked lists aka Von Nuemann's Algorithm
Linkedlist *mergeSortList(Node *ini, Node *fin){/* 4 2 0 1 5 0 19 11 1 9 [0,1,2,0,0,2,2,1]*/

    if(ini == fin){
        Linkedlist *aux = (Linkedlist*)(malloc(sizeof(Linkedlist)));
        aux->head = ini;
        return aux;
    }else{
        
        Node *split = splitList(ini,fin);
        Node *mid = split->next;
        split->next = NULL;

        return mergeLists(mergeSortList(ini,split),mergeSortList(mid,fin));
    }

}


Node *splitList(Node *ini, Node *fin){
 
Node *auxf = ini;
Node *auxb = ini;

while( auxf != NULL){
    
    auxf = auxf->next;
    if(auxf != NULL)
    auxf = auxf->next;

    if(auxf != NULL)
    auxb = auxb->next;

}

return auxb;
}


Linkedlist *mergeLists(Linkedlist *lone, Linkedlist *ltwo){
        
        if(lone->head == NULL)
        return ltwo;

        if(ltwo->head == NULL)
        return lone;
      

        Linkedlist *result = (Linkedlist*)(malloc(sizeof(Linkedlist)));
        result->head = NULL;
        Node *none = lone->head;
        Node *ntwo = ltwo->head;
        Node *aux = NULL;

        while(none != NULL && ntwo != NULL){

            if(*(int*)none->data <= *(int*)ntwo->data){
                if(result->head == NULL){
                    result->head = none;
                    aux = result->head;
                }else{
                    aux->next = none;
                    aux = aux->next;
                    
                }

                none = none->next;

            }else{

                if(result->head == NULL){
                    result->head = ntwo;
                    aux = result->head;
                }else{
                    aux->next = ntwo;
                    aux = aux->next;
                }

                ntwo = ntwo->next;
            }
        }

        if(none!=NULL)
        aux->next = none;

        if(ntwo!=NULL)
        aux->next = ntwo;

    return result;
}


