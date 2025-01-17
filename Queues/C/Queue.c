#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Node{
    void *data;
    struct Node *next;
}Node;

typedef struct Queue{
    struct Node *first; 
}Queue;


void printQueue(Queue *q);
void enQueue(Queue *q,int n);
void deQueue(Queue *q);
int peekQ(Queue *q);
bool isEmpty(Queue *Q);
int qSize(Queue *Q);

void main(){

int N;
int e;
Queue *Q = (Queue*)(malloc(sizeof(Queue)));

printf("Give me the size of your queue: \n");
scanf("%d",&N);

printf("Give me your elements: \n");
int i;
for(i=0;i<N;i++){
scanf("%d",&e);
enQueue(Q,e);
}

printf("Your queue is: \n");
printQueue(Q);
printf("\n");

printf("Your queue size is: %d \n",qSize(Q));
printf("\n");

deQueue(Q);
deQueue(Q);

if(isEmpty(Q))
printf("The queue is empty \n");
else printf("The queue is not empty \n");

printf("Your new queue is: \n");
printQueue(Q);
printf("\n");
deQueue(Q);
printf("\n");

if(isEmpty(Q))
printf("The queue is empty \n");
else printf("The queue is not empty \n");

printf("\n");
printf("Your new queue size %d \n",qSize(Q));

}

void printQueue(Queue *q){
    if(q->first == NULL)
    printf("The queue is empty \n");
    else{
        Node *aux = q->first;
        while(aux != NULL){
            printf("%d ",*(int*)aux->data);
            aux = aux->next;
        }
    }
    printf("\n");

}


void enQueue(Queue *q,int d){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = malloc(sizeof(int));
    *(int*)n->data = d;
    Node *aux;

    if(q->first == NULL){
        q->first = n;
        aux = q->first;
    }else{
        while(aux->next != NULL)
        aux = aux->next;
        
        aux->next = n;
        aux = aux->next;
    }
}

int peekQ(Queue *q){

    int r;

    if(q->first == NULL)
    r = -1;
    else{
            Node *aux = q->first;
            r = *(int*)q->first->data;
    }

return r;
}


void deQueue(Queue *q){

    if(q->first == NULL)
    printf("There are no elements to dequeue because your list is empty \n");
    else q->first = q->first->next;

}


bool isEmpty(Queue *Q){

    if(Q->first == NULL)
    return true;
    else return false;
}

int qSize(Queue *Q){
    int s = 0;

    Node *aux = Q->first;
    while(aux != NULL){
        s++;
        aux = aux->next;
    }

return s;
}



