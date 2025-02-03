#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

typedef struct Minheap{
int size;
int entries;
int slots[];
}Minheap;

void printMinheap(Minheap *mh);
void insertMinheap(Minheap *mh,int d);
void bubbleUp(Minheap *mh,int pos);
int deleteMinheap(Minheap *mh);
void bubbleDown(Minheap *mh,int n_entries);
void minheapSort(Minheap *mh);

void printMinheap(Minheap *mh){
    if(mh->entries == 0)
    printf("The heap is empty \n");
    else{
        int i;
        for(i=0;i<mh->entries;i++)
        printf("%d ",mh->slots[i]);
    }
    printf("\n");
}

void insertMinheap(Minheap *mh,int d){
    if(mh->entries >= mh->size)
    printf("The heap is full");
    else{
        mh->slots[mh->entries] = d;
        mh->entries++;
        bubbleUp(mh,mh->entries-1);
        printf("\n");
        printMinheap(mh);
    }
}

void bubbleUp(Minheap *mh,int pos){
    if(pos >= 1){
        int parent_index;
        bool b = true;

        while(b){
            parent_index = (pos-1)/2;
            if(pos-1 < 0)
            b = false;
            else{
                if(mh->slots[pos] >= mh->slots[parent_index])
                b = false;
                else{
                    int temp = mh->slots[parent_index];
                    mh->slots[parent_index] = mh->slots[pos];
                    mh->slots[pos] = temp;
                    pos = parent_index;
                }
            }
        }

    }
}



int deleteMinheap(Minheap *mh){
    
    int r;

    if(mh->entries == 0)
    printf("The heap is empty \n");
    else{
       if(mh->entries == 1){
        r = mh->slots[0];
        mh->slots[0] = INT_MAX;
        mh->entries--;
    }else{
        r = mh->slots[0];
        mh->slots[0] = mh->slots[mh->entries-1];
        mh->slots[mh->entries-1] = INT_MAX;
        mh->entries--;
        bubbleDown(mh,mh->entries);
    }
   } 

    return r;   
}

void bubbleDown(Minheap *mh,int n_entries){
    
    int parent = 0;
    bool b = true;

    while(b){
        int l_child = 2*parent + 1;
        int r_child = 2*parent + 2;
        
        if(l_child >= n_entries && r_child >= n_entries)
        b = false;
        else{
            if(r_child < n_entries){

                if(mh->slots[l_child] >= mh->slots[r_child]){
                    if(mh->slots[parent] <= mh->slots[r_child])
                    b = false;
                    else{
                        int temp = mh->slots[parent];
                        mh->slots[parent] = mh->slots[r_child];
                        mh->slots[r_child] = temp;
                        parent = r_child;
                    }
                }else{
                    if(mh->slots[parent] <= mh->slots[l_child])
                    b = false;
                    else{
                        int temp = mh->slots[parent];
                        mh->slots[parent] = mh->slots[l_child];
                        mh->slots[l_child] = temp;
                        parent = l_child;
                    }
                }

            }else{
                if(mh->slots[parent] <= mh->slots[l_child])
                b = false;
                else{
                    int temp = mh->slots[parent];
                    mh->slots[parent] = mh->slots[l_child];
                    mh->slots[l_child] = temp;
                    parent = l_child;
                }

            }
        }
    }
    

}



void minheapSort(Minheap *mh){

    int k = mh->entries; 

   while(k > 0){
    int temp = mh->slots[0];
    mh->slots[0] = mh->slots[k-1];
    mh->slots[k-1] = temp;
    k--;
    bubbleDown(mh,k);
    }

}

void main(){
    
    int N;
    printf("Give me the size of your min heap \n");
    scanf("%d",&N);

    //initialization 10, 20, 5, 30, 25, 15
    Minheap *h = (Minheap*)(malloc(sizeof(Minheap) + N*sizeof(int)));
    h->size = N;
    h->entries = 0;

    printf("Give me the number of elments you want to insert you heap \n");
    int e;
    scanf("%d",&e);

    int x;
    int entry;
    for(x=0;x<e;x++){
        printf("Give me entry number %d \n",x);
        scanf("%d",&entry);
        insertMinheap(h,entry);
        printf("\n");
    }

    printf("Your heap is: \n");
    printMinheap(h);


    printf("\n");
    deleteMinheap(h);
    printf("Your new heap is :\n");
    printMinheap(h);

    printf("\n");
    deleteMinheap(h);
    printf("Your new heap two is :\n");
    printMinheap(h);


    
    printf("\n");
    printf("Your heap after sorting \n");

    minheapSort(h);
    printMinheap(h);


    


 

}