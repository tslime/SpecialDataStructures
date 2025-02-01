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
                    int parent = 0;
                    bool b = true;

                    while(b){
                        parent = (pos-1)/2;
                        if(pos-1 < 0)
                        b = false;
                        else{
                            if(mh.slots[parent] > mh.slots[pos]){
                                int temp = mh.slots[parent];
                                mh.slots[parent] = mh.slots[pos];
                                mh.slots[pos] = temp;
                                pos = parent;
                            }else b = false;
                        }
                    }
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
                        bubbleDown(mh,mh.num_entries-1);
                    }
                }

                void bubbleDown(Minheap& mh,int pos){
                    int l_c = 0;
                    int r_c = 0;
                    int parent  = 0;
                    bool b = true;

                    while(b){
                        l_c = 2*parent + 1;
                        r_c = 2*parent + 2;
                        if(l_c >= pos && r_c >= pos)
                        b = false;
                        else{
                            if(r_c < pos){
                                if(mh.slots[r_c] >= mh.slots[l_c]){

                                    if(mh.slots[parent] > mh.slots[l_c]){
                                        int temp = mh.slots[parent];
                                        mh.slots[parent] = mh.slots[l_c];
                                        mh.slots[l_c] = temp;
                                        parent = l_c;
                                    }else b = false;

                                }else{

                                     if(mh.slots[parent] > mh.slots[r_c]){
                                        int temp = mh.slots[parent];
                                        mh.slots[parent] = mh.slots[r_c];
                                        mh.slots[r_c] = temp;
                                        parent = r_c;
                                    }else b = false;
                                }

                            }else{

                                if(mh.slots[parent] > mh.slots[l_c]){
                                    int temp = mh.slots[parent];
                                    mh.slots[parent] = mh.slots[l_c];
                                    mh.slots[l_c] = temp;
                                    parent = l_c;
                                }else b =false;

                            }
                        }
                    }

 
                }


                void minheapSort(Minheap& mh){
                    if(mh.num_entries > 1){
                        int l = mh.num_entries-1;
                        bool b = false;
                        while(!b){
                            int temp = mh.slots[0];
                            mh.slots[0] = mh.slots[l];
                            mh.slots[l] = temp;
                            l--;

                            if(l>0)
                            bubbleDown(mh,l);
                            else b = true;
                        }
                    }
                    
                }
};

int main(){

    int N;
    
    cout << "Give me the size of your heap \n";
    cin >> N;
    Minheap h(N);

    cout << "\n";
    int e;
    cout<< "Give me the number of entries you would like to insert \n";
    cin >> e;

    int i = 0;
    cout << "Give me your entries: \n";
    int x;
    while(i < e){
        cin >> x;
        h.insertMinheap(h,x);
        cout << "\n";
        i++;
    }
    cout << "\n";
    h.printMinheap(h);
    cout << "\n";

    h.deleteMinheap(h);
    cout << "Your heap after the first deletion \n";
    h.printMinheap(h);

    cout << "\n";

    h.deleteMinheap(h);
    cout << "Your heap after the second deletion \n";
    h.printMinheap(h);


    h.minheapSort(h);
    cout <<"Your sorted heap is \n";
    h.printMinheap(h);



    exit(1);
}



