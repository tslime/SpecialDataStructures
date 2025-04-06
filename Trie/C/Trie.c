#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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






//Function to initialize a trie node
void initTNode(Trienode **nd,int s){
    
    *nd = (Trienode*)(malloc(sizeof(Trienode)));
    (*nd)->tn = (THashtable*)(malloc(sizeof(THashtable) + s*sizeof(TNode)));
    (*nd)->tn->size = s;
    (*nd)->tn->num_c = 0;

    int i;
    for(i=0;i<s;i++){
        (*nd)->tn->children[i] = (TNode*)(malloc(sizeof(TNode)));
        (*nd)->tn->children[i]->key = NULL;
        (*nd)->tn->children[i]->child = (Trienode*)(malloc(sizeof(Trienode)));
        (*nd)->tn->children[i]->child = NULL;
    }

}

//Function to resize a trie node hashtable 
void resize(Trienode *nd,int new_size){

    THashtable *t = (THashtable*)(malloc(sizeof(THashtable) + new_size*sizeof(TNode)));
    t->size = new_size;

    int i;
    for(i=0;i<new_size;i++){

        if( i < nd->tn->size)
        t->children[i] = nd->tn->children[i];
        else{
            t->children[i] = (TNode*)(malloc(sizeof(TNode)));
            t->children[i]->child = NULL;
            t->children[i]->key = NULL;
        }

    }

    t->num_c = nd->tn->num_c; 
    nd->tn = t;
}



    
//Insert word, iterative
void insertString(Trienode **root,char *w){
    
    TNode *aux;
    int index;

    int i;
    for(i=0;i<strlen(w);i++){
        index = w[i] - 'a';   

        if(i == 0){

            if(*root == NULL)
            initTNode(root,index+1);

            if(index >= (*root)->tn->size)
            resize(*root,index+1);

            if((*root)->tn->children[index]->key == NULL){
                (*root)->tn->children[index]->key = &w[i];
                (*root)->tn->num_c++;
            }
            
            aux = (*root)->tn->children[index];

        }else{
            
            if(aux->child == NULL)
            initTNode(&(aux->child),index+1);
                     
            if(index >= aux->child->tn->size)
            resize(aux->child,index+1);
                    
            if(aux->child->tn->children[index]->key == NULL){
                aux->child->tn->children[index]->key = &w[i]; 
                aux->child->tn->num_c++;  
            }
                    
            aux = aux->child->tn->children[index];        
        }
     }
}

void printTrie(Trienode *root,char *k,int ct){

    if(root != NULL){
        int i = 0;
        int j = 0;
        bool b = false;

        while(i < root->tn->size && !b){
            
            if(j == root->tn->num_c)
            b = true;
            else{
                
                if(root->tn->children[i]->key != NULL){
                k[ct] = *(root->tn->children[i]->key);
                printf("%s",k);
                printf(" | ");
                j++;

                Trienode *aux = root->tn->children[i]->child;
                if(aux != NULL){
                     ct++;
                     printTrie(aux,k,ct);
                     k[ct] = '\0';
                     ct--;

                     if(ct == 0)
                     printf("\n \n");
                }
            }  
          }
         i++;
        }
      }
}




void main(){


    //initialization
    Trienode *root;
    root = NULL;


    //Insertion process
    while(1){
    printf("Give me a word \n");
    char *test =(char*)(malloc(100*sizeof(char)));
    scanf("%s",test);
    insertString(&root,test);
    printf("\n");
    char *c = (char*)malloc(100*sizeof(char));
    printTrie(root,c,0);
    }
    


}