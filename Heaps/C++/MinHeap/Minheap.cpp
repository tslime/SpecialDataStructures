#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<vector>
#include<limits>

using std::cout;
using std::cin;
using std::end;
using std::vector;
using std::numeric_limits;

class Minheap{
        
        public:
                int size;
                int num_entries;
                vector<int> slots;
                Minheap(int size):size(size),num_entries(0),slots(size){}

                void printMinheap(Minheap& mh){
                    if(mh.num_entries == 0)
                    cout << "There are no entries in the heap \n";
                    else{
                        for(int i = 0;i<mh.num_entries;i++)
                        cout << mh.slots[i] << " ";

                        cout << "\n";    
                    }
                }

                void insertMinheap(Minheap& mh,int d){
                    if(mh.num_entries >= mh.size)
                    cout << "The heap is full \n";
                    else{
                        mh.slots[mh.num_entries] = d;
                        mh.num_entries++;
                        bubbleUp(mh,mh.num_entries-1);
                    }
                }  

                void bubbleUp(Minheap& mh,int pos){

                }

                void deleteMinheap(Minheap& mh){
                    int r;

                    if(mh.num_entries == 0)
                    cout << "The heap is empty \n";
                    else{
                        r = mh.slots[0];
                        mh.slots[0] = mh.slots[mh.num_entries-1];
                        mh.slots[mh.num_entries-1] = numeric_limits<int>::max(); 
                        mh.num_entries--;
                        bubbleDown(mh);
                    }
                }

                void bubbleDown(Minheap& mh){

                }


                void minheapSort(Minheap& h){
                    
                }
};

int main(){

    cout << "test \n";
    exit(1);
}



