#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>


//struct Edge;
//struct SNode;

//Hashmap data structure
typedef struct SHNode{
    char *key;
    struct Edge *e;
}SHNode;

typedef struct SHashmap{
int str_size;
int num_entries;
SHNode *slots[];
}SHashmap;

//Edge data structure
typedef struct Edge{
int from;
int to;
struct SNode *child;

}Edge;

//SNode data structure
typedef struct SNode{
SHashmap *map;
struct SNode *suffix_link;
}SNode;


void initNode(SNode **n,int size);




void initNode(SNode **n,int size){
    *n = (SNode*)(malloc(sizeof(SNode)));
    (*n)->map = (SHashmap*)(malloc(sizeof(SHashmap)+size*sizeof(SHNode)));
    int i;
    for(i=0;i<size;i++)
    (*n)->map->slots[i] = (SHNode*)(malloc(sizeof(SHNode)));

}







void main(){


    //Initialization
    int N;
    SNode *root;
    printf("Give me the size of your string \n");
    scanf("%d",&N);
    initNode(&root,N);
    
    char *k = "a";
    printf("test \n");
    root->map->slots[0]->key = k;

    printf("%s \n ",root->map->slots[0]->key);
}