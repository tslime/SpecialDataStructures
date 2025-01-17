#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct HNode{
    void *key;
    void *value;
    struct HNode *next;
}HNode;

typedef struct HLinkedlist{
    HNode *head;
}HLinkedlist;

typedef struct Htable{
    int size;
    HLinkedlist *slot[];  
}Htable;


void printHT(Htable *t);
int calcHashCode(Htable *t,void *key);
void insertHT(Htable *t,void *k,void *v);
void deleteHT(Htable *t,void *k);
void searchHT(Htable *t,void *key);

void main(){

   
    int N;
   

    printf("Give me the size of your table: \n");
    scanf("%d",&N);
    Htable *ht = (Htable*)malloc(sizeof(Htable) + N*sizeof(HLinkedlist));
    ht->size = N;

    //initialization
    int i;
    for(i=0;i<N;i++){
    ht->slot[i] = (HLinkedlist*)malloc(sizeof(HLinkedlist));
    ht->slot[i]->head = NULL;
    }
    printf("\n");
    printf("\n");

    int elem; 
    printf("Give me the number of elements you would like to insert: \n");
    scanf("%d",&elem);
    int a;

    

    for(a=0;a<elem;a++){    
        int *k = (int*)(malloc(sizeof(int)));
        char *c =(char*)(malloc(100*sizeof(char)));
        printf("Give me the key for you element %d \n",a+1);
        scanf("%d",k);
        void *kh = k;
        printf("Give me the value for your element %d\n",a+1);
        scanf("%s",c);
        void *vh = c;
        
        insertHT(ht,kh,vh);
        
    }
    printf("\n");
    printHT(ht);
    printf("\n");

    int hk;
    while(1){
        printf("Give me the key of the entry you want to delete \n");
        scanf("%d",&hk);
        deleteHT(ht,&hk);
        printf("\n");
        printHT(ht);
    }
}


int calcHashCode(Htable *t, void *key){
    return (*(int*)key)%(t->size);
}

void printHT(Htable *t){
    if(t == NULL)
    printf("The table is empty:\n");
    else{
        int i;
        for(i=0;i<t->size;i++){
            if(t->slot[i]->head == NULL){
                printf("\nthere are no elements at slot %d \n",i);
                printf("\n");
            }else{
                printf("\n");
                printf("The entries at slot %d \n",i);
                HNode *aux = t->slot[i]->head;
                while(aux != NULL){
                    
                    printf("Key: %d Value: %s || ",*(int*)aux->key,(char*)aux->value);
                    aux = aux->next;
                }
                printf("\n");
            }
        }
    }
    
}

void insertHT(Htable *t,void *k, void *v){

    HNode *n = (HNode*)(malloc(sizeof(HNode)));
    n->key = k;
    n->value = v;
    n->next = NULL;


    int code = calcHashCode(t,k);

    if(t->slot[code]->head == NULL)
    t->slot[code]->head = n;
    else{
        HNode *aux = t->slot[code]->head;
        while(aux->next != NULL)
        aux = aux->next;
        
        aux->next = n;
    }
}

void searchHT(Htable *t,void *k){

    if(t == NULL)
    printf("The table is empty \n");
    else{
        int code = calcHashCode(t,k);
        HNode *aux = t->slot[code]->head;

        while(aux != NULL && *(int*)aux->key != *(int*)k)
        aux = aux->next;
        
        if(aux != NULL)
        printf("The key exists and it is at slot %d \n",code);
        else printf("The key does  not exist");

    }
}

void deleteHT(Htable *t,void *k){
    if(t == NULL)
    printf("The table is empty \n");
    else{
        int code = calcHashCode(t,k);
        HNode *aux = t->slot[code]->head;
        HNode *prev = NULL;

        while(aux != NULL && *(int*)aux->key != *(int*)k){
            prev = aux;
            aux = aux->next;
        }

        if(aux == NULL)
        printf("The key does not exist \n");
        else{
            if(prev == NULL)
            t->slot[code]->head = aux->next;
            else prev->next = aux->next;
        }

    }
}