#include<iostream>
#include<limits>
#include<vector>


using std::cin;
using std::cout;
using std::end;
using std::vector;
using std::numeric_limits;


class Maxheap{

        public:
                int size;
                int num_entries;
                vector<int> slots;

                Maxheap(int size):size(size), num_entries(0),slots(size){}

                void printMaxheap(Maxheap mh){
                    if(mh.num_entries == 0)
                    cout << "The heap is empty \n";
                    else{
                        for(int i=0;i<mh.num_entries;i++)
                        cout << mh.slots.at(i) << " ";
                        
                        cout << "\n";
                    }
                }

                void insertMaxheap(Maxheap mh,int d){
                    if(mh.num_entries >= mh.size)
                    cout << "The heap is full";
                    else{
                        mh.slots[mh.num_entries] = d; 
                        mh.num_entries++;
                        bubbleUp(mh,mh.num_entries-1);
                    }
                }

                void bubbleUp(Maxheap mh,int pos){

                }

                void deleteMaxheap(Maxheap mh){
                    int r;

                    if(mh.num_entries == 0)
                    cout << "The heap is empty \n";
                    else{
                        r = mh.slots[0];
                        mh.slots[0] = mh.slots[mh.num_entries-1];
                        mh.slots[mh.num_entries-1] = numeric_limits<int>::max();
                        mh.num_entries--;
                        bubbleDown(mh,mh.num_entries-1);
                    }
                }

                void bubbleDown(Maxheap mh,int pos){

                }

                void maxheapSort(Maxheap mh){
                    
                }
};

int main(){


    cout << "test \n";

    exit(1);
}