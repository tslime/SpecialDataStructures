#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>


struct Edge;
struct SNode;

//Hashmap data structure
typedef struct SHNode{
    char *key;
    struct Edge *e;
}SHNode;

typedef struct SHashmap{
int str_size;
int num_entries;
SHNode **slots;
}SHashmap;

//Edge data structure
typedef struct Edge{
int from;
int to;
struct SNode *child;

}Edge;

//SNode data structure
typedef struct SNode{
SHashmap *n;
struct SNode *suffix_link;
}SNode;










void main(){

    printf("test\n");
}