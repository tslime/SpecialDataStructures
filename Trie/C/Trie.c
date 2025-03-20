#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>



//TrieNode data structure
typedef struct Trienode{
    bool endofw;
    struct THashtable *tn;
}Trienode;

//Hashtable data structure
typedef struct TNode{
    char *key;
    Trienode *child;
}TNode;

typedef struct THashtable{
    int size;
    int num_c;
    TNode *children[];
}THashtable;

void initTNode();

void resize();



void main(){

    int s; 
    printf("Give me the size of your trie \n");
    scanf("%d",&s);
    printf("\n");

    //initialization
    Trienode *root = (Trienode*)(malloc(sizeof(Trienode))); 
    root->tn = (THashtable*)(malloc(sizeof(THashtable) + s*sizeof(TNode)));
    root->tn->size = s;
    root->tn->num_c = 0;

    int i;
    for(i=0;i<s;i++){
        root->tn->children[i] = (TNode*)(malloc(sizeof(TNode)));
        root->tn->children[i]->key = NULL;
        root->tn->children[i]->child = (Trienode*)(malloc(sizeof(Trienode)));
        printf("test");
    }

    root->tn->children[0]->key = "test zero";
    printf("test %d \n",root->tn->size);
    printf("another test %s\n",root->tn->children[0]->key);
}