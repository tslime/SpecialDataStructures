#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Node{
    void *data;
    struct Node *next;
}Node;

typedef struct Stack{
    struct Node *Top;
}Stack;


void printStack(Stack *S);
void pushS(Stack *S, int d);
void popS(Stack *S);
bool isEmpty(Stack *S);
int sizeS(Stack *S);

void main(){

    Stack *s = (Stack*)(malloc(sizeof(Stack)));
    int N;
    int e;

    printf("Give me the number of elements you want to store in the Stack \n");
    scanf("%d",&N);

    printf("Give me your elemnets: \n");
    int i = 0;
    while( i < N ){
     scanf("%d",&e);
     pushS(s,e);
     i++;
    }

    printf("\n");
    printStack(s);
    printf("\n");
    
    printf("The size of the stack is: %d \n",sizeS(s));
    popS(s);

    printf("\n");
    printStack(s);
    printf("\n");

     popS(s);
     popS(s);

    if(isEmpty(s))
    printf("The stack is empty \n");
    else printf("The stack is not empty \n");

}

void printStack(Stack *S){
    if(S->Top == NULL)
    printf("The stack is empty \n");
    else{
        Node *aux = S->Top;
        while(aux != NULL){
             printf("%d ", *(int*)aux->data);
             aux = aux->next;
        }
       
    }
}

void pushS(Stack *S, int d){
    Node *n = (Node*)(malloc(sizeof(Node)));
    n->data = (int*)(malloc(sizeof(int)));
    *(int*)n->data = d;

    if(S->Top == NULL)
    S->Top = n;
    else{
        n->next = S->Top;
        S->Top = n;
    }
}

void popS(Stack *S){
    if(S->Top == NULL)
    printf("The stack is empty");
    else S->Top = S->Top->next;
}

bool isEmpty(Stack *S){
    if(S->Top == NULL)
    return true;
    else return false;
}


int sizeS(Stack *S){
    int z = 0;

    Node *aux = S->Top;
    while(aux != NULL){
        z++;
        aux = aux->next;
    }

return z;
}