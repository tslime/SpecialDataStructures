#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

//Hashmap data structure

typedef struct HNode{

}HNode;

typedef struct Hashmap{
    int size;
    HNode *slot[];
}Hashmap;

//Edge data structure
typedef struct Edge{
HNode *ini;
HNode *fin;
Hashmap **next;
}Edge;

//Suffix tree node data structure
typedef struct SNode{

}SNode;

void main(){

    printf("test\n");
}