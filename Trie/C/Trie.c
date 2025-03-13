#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

//Forward declaration
//struct TrieNode;
//struct THashtable;


//TrieNode data structure
typedef struct TrieNode{
    bool endofw;
    struct THashtable *tn;
}TrieNode;

//Hashtable data structure
typedef struct TNode{
    char *key;
    TrieNode *child;
}TNode;

typedef struct THashtable{
    int size;
    TNode *children[];
}THashtable;





void main(){


    printf("test \n");
}