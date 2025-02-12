#include<stdio.h>
#include<malloc.h>
#include<limits.h>
#include<stdbool.h>

typedef struct Maxheap{
    int size;
    int num_entries;
    int slots[];
}Maxheap;

void printMaxheap(Maxheap *mh);
void insertMaxheap(Maxheap *mh,int d);
void bubbleUP(Maxheap *mh,int pos);
void deleteMAxHeap(Maxheap *mh);
void bubbleDown(Maxheap *mh,int nleaf,int pos);
void heapSort(Maxheap *mh);
void heapify(Maxheap *mh);



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


void heapify(Maxheap *mh){
    if(mh->num_entries > 1){
        int nleaf = (mh->num_entries/2) - 1;
        while(nleaf >= 0){
            bubbleDown(mh,nleaf,mh->num_entries-1);
            nleaf--;
        }
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
    int parent = 0;
    bool b = true;

    while(b){
        parent = (pos-1)/2;
        if(pos-1 < 0)
        b = false;
        else{
            if(mh->slots[parent] < mh->slots[pos]){
                int temp = mh->slots[parent];
                mh->slots[parent] = mh->slots[pos];
                mh->slots[pos] = temp;
                pos = parent;
            }else b = false;
        }
    }

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
        bubbleDown(mh,0,mh->num_entries-1);
    }
}

void bubbleDown(Maxheap *mh,int nleaf,int pos){
    int l_c = 0;
    int r_c = 0;
    int parent = nleaf;
    bool b = true;

    while(b){
        l_c = 2*parent + 1;
        r_c = 2*parent + 2;

        if(l_c > pos && r_c > pos)
        b = false;
        else{
            if(r_c <= pos){

                if(mh->slots[r_c] >= mh->slots[l_c]){

                    if(mh->slots[parent] < mh->slots[r_c]){
                        int temp = mh->slots[parent];
                        mh->slots[parent] = mh->slots[r_c];
                        mh->slots[r_c] = temp;
                        parent = r_c;
                    }else b = false;

                }else{

                     if(mh->slots[parent] < mh->slots[l_c]){
                        int temp = mh->slots[parent];
                        mh->slots[parent] = mh->slots[l_c];
                        mh->slots[l_c] = temp;
                        parent = l_c;
                    }else b = false;

                }

            }else{

                if(mh->slots[parent] < mh->slots[l_c]){
                        int temp = mh->slots[parent];
                        mh->slots[parent] = mh->slots[l_c];
                        mh->slots[l_c] = temp;
                        parent = l_c;
                    }else b = false;

            }
        }
    }
}

void heapSort(Maxheap *mh){
    if(mh->num_entries > 1){
        int l = mh->num_entries -1;
        bool b = false;

        while(!b){
            int temp = mh->slots[0];
            mh->slots[0] = mh->slots[l];
            mh->slots[l] = temp;
            l--;
            if(l > 0)
            bubbleDown(mh,0,l);
            else b = true;

        }
    }
}

void main(){
    
    int N;
   
   
    //initialization

    printf("give me the size of your heap \n");
    scanf("%d",&N);
    Maxheap *h = (Maxheap*)(malloc(sizeof(Maxheap) + N*sizeof(int)));
    h->num_entries = 0;
    h->size = N;

    printf("Give me the number of entries you would like to insert \n");
    int entries;
    scanf("%d",&entries);
    
    printf("Insert your entries \n");
    int i = 0;
    int e;
    while(i < entries){
        scanf("%d",&e);
        h->slots[i] = e;
        h->num_entries++;
        //insertMaxheap(h,e);
        printf("\n");
        i++;
    }

    printf("Your array is \n");
    printMaxheap(h);
    printf("\n");

    printf("Your heapified array is \n");
    heapify(h);
    printMaxheap(h);
    printf("\b");
    
    /*
    printf("Your heap after deleting once is \n");
    deleteMAxHeap(h);
    printMaxheap(h);
    printf("\n");

    printf("Your heap after deleting twice is \n");
    deleteMAxHeap(h);
    printMaxheap(h);
    printf("\n");

    printf("Your heap after sorting is \n");
    heapSort(h);
    printMaxheap(h);
    printf("\n");
    */
}