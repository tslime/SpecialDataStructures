#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct TNode{
    void *data;
    struct TNode *left;
    struct TNode *right;
}TNode;

typedef struct BTree{
        TNode *root;
}BTree;

void printInOBSTree(TNode *r);
void insertBSTree(TNode **r,int d);
bool searchBSTree(TNode *r,int e);
void deleteBSTree(TNode **r,int e);


void main(){

int N;

BTree *t = (BTree*)(malloc(sizeof(BTree)));
t->root = NULL;


printf("Give me the number of elments you want to insert: \n");
scanf("%d",&N);

printf("Give me your elements:\n");

int i;
int e = 0;
for(i=0;i<N;i++){
scanf("%d",&e);
insertBSTree(&(t->root),e);
}


printf("Your sorted tree is: \n");

printInOBSTree(t->root);

printf("\n");

int n;
bool r;
while(1){
printf("Give me the element you want to delete: \n");
scanf("%d",&n);
deleteBSTree(&(t->root),n);
printf("Your new tree is: \n");
printInOBSTree(t->root);
printf("\n");
}

}


void printInOBSTree(TNode *r){

    if(r != NULL)
    {   
        printInOBSTree(r->left);
        printf("%d ",*(int*)r->data);
        printInOBSTree(r->right);
    }
}


void insertBSTree(TNode **r,int d){
    if(*r == NULL){

     TNode *n = (TNode*)(malloc(sizeof(TNode)));
     n->data = (int*)(malloc(sizeof(int)));
     n->left = NULL;
     n->right = NULL;
     *(int*)n->data = d;
     
    *r = n;

       
    }else{
        
        if( d <= *(int*)((*r)->data) ) 
        insertBSTree( &((*r)->left),d);
        else insertBSTree( &((*r)->right),d);
        
    }
}


bool searchBSTree(TNode *r,int e){
    
    bool b = false;

    if( r != NULL ){
        if(*(int*)r->data == e){
            return true;
        }else{
            if( e <= *(int*)r->data)
            b = searchBSTree(r->left,e);
            else b = searchBSTree(r->right,e);
        }
    }
    return b;
}



void deleteBSTree(TNode **r,int e){

    if( *r != NULL){
        if( *(int*)((*r)->data) == e ){
                if((*r)->right == NULL)
                *r = (*r)->left;
                else{

                    TNode *prev = NULL;
                    TNode *aux = (*r)->right;
                    while( aux->left != NULL){
                       prev = aux; 
                       aux = aux->left;
                    }
                    
                    *(int*)((*r)->data) = *(int*)aux->data;

                    if(prev == NULL)
                    (*r)->right = aux->right;
                    else prev->left = aux->right;
            }

        }else{
            if( e <= *(int*)((*r)->data) )
            deleteBSTree(&((*r)->left),e);
            else deleteBSTree(&((*r)->right),e);
        }
    }
}


/*
void deleteBSTree(TNode *r,int e){

    if( r != NULL){

        if(*(int*)r->data == e){
           
                if(r->right == NULL)
                r = r->left;
                else{

                    TNode *prev = NULL;
                    TNode *aux = r->right;
                    while( aux->left != NULL){
                       prev = aux; 
                       aux = aux->left;
                    }
                    
                    *(int*)r->data = *(int*)aux->data;

                    if(prev == NULL)
                    r->right = aux->right;
                    else prev->left = aux->right;
            }

        }else{
            if( *(int*)r->data <= e)
            deleteBSTree(r->left,e);
            else deleteBSTree(r->right,e);
        }
    }
}*/