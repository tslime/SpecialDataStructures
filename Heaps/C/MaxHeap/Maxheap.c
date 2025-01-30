#include<stdio.h>
#include<malloc.h>
#include<limits.h>


typedef struct Maxheap{
    int size;
    int num_entries;
    int slots[];
}Maxheap;

void printMaxheap(Maxheap *mh);
void insertMaxheap(Maxheap *mh,int d);
void bubbleUP(Maxheap *mh,int pos);
void deleteMAxHeap(Maxheap *mh);
void bubbleDown(Maxheap *mh,int pos);
void heapSort(Maxheap *mh);

void printMaxheap(Maxheap *mh){
    if(mh->num_entries == 0)
    printf("The heap is empty \n");
    else{
        int i;
        for(i=0;i<mh->num_entries;i++)
        printf("%d ",mh->slots[i]);
        
        printf("\n");
    }
}

void insertMaxheap(Maxheap *mh,int d){
    if(mh->num_entries >= mh->size)
    printf("The heap is full \n");
    else{
        mh->slots[mh->num_entries] = d;
        mh->num_entries++;
        bubbleUP(mh,mh->num_entries-1);
    }
}

void bubbleUP(Maxheap *mh,int pos){

}

void deleteMAxHeap(Maxheap *mh){
    int r;

    if(mh->num_entries == 0)
    printf("The heap is empty \n");
    else{
        r = mh->slots[0];
        mh->slots[0] = mh->slots[mh->num_entries-1];
        mh->slots[mh->num_entries] = INT_MAX;
        mh->num_entries--;
        bubbleDown(mh,mh->num_entries-1);
    }
}

void bubbleDown(Maxheap *mh,int pos){

}

void heapSort(Maxheap *mh){

}

void main(){
    
    int N;
   
   
    //initialization

    printf("give me the size of your heap \n");
    scanf("%d",&N);
    Maxheap *h = (Maxheap*)(malloc(sizeof(Maxheap) + N*sizeof(int)));
    h->num_entries = 0;
    h->size = N;
}