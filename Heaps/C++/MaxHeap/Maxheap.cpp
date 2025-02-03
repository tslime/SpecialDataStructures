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

                void printMaxheap(Maxheap& mh){
                    if(mh.num_entries == 0)
                    cout << "The heap is empty \n";
                    else{
                        for(int i=0;i<mh.num_entries;i++)
                        cout << mh.slots.at(i) << " ";
                        
                        cout << "\n";
                    }
                }

                void insertMaxheap(Maxheap& mh,int d){
                    if(mh.num_entries >= mh.size)
                    cout << "The heap is full";
                    else{
                        mh.slots[mh.num_entries] = d; 
                        mh.num_entries++;
                        bubbleUp(mh,mh.num_entries-1);
                    }
                }

                void bubbleUp(Maxheap& mh,int pos){
                    int parent = 0;
                    bool b = true;

                    while(b){
                        parent = (pos-1)/2;
                        if(pos-1 < 0)
                        b = false;
                        else{
                            if(mh.slots[parent] < mh.slots[pos]){
                                int temp = mh.slots[parent];
                                mh.slots[parent] = mh.slots[pos];
                                mh.slots[pos] = temp;
                                pos = parent;
                            }else b = false;
                        }
                    }
                }

                void deleteMaxheap(Maxheap& mh){
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

                void bubbleDown(Maxheap& mh,int pos){
                    int l_c = 0;
                    int r_c = 0;
                    int parent  = 0;
                    bool b = true;

                    while(b){
                        l_c = 2*parent + 1;
                        r_c = 2*parent + 2;
                        if(l_c > pos && r_c > pos)
                        b = false;
                        else{
                            if(r_c <= pos){
                                if(mh.slots[r_c] >= mh.slots[l_c]){

                                    if(mh.slots[parent] < mh.slots[r_c]){
                                        int temp = mh.slots[parent];
                                        mh.slots[parent] = mh.slots[r_c];
                                        mh.slots[r_c] = temp;
                                        parent = r_c;
                                    }else b = false;

                                }else{

                                    if(mh.slots[parent] < mh.slots[l_c]){
                                        int temp = mh.slots[parent];
                                        mh.slots[parent] = mh.slots[l_c];
                                        mh.slots[l_c] = temp;
                                        parent = l_c;
                                    }else b = false;
                                }

                            }else{

                                if(mh.slots[parent] < mh.slots[l_c]){
                                    int temp = mh.slots[parent];
                                    mh.slots[parent] = mh.slots[l_c];
                                    mh.slots[l_c] = temp;
                                    parent = l_c;
                                }else b = false;
                            }
                        }
                    }

                }

                void maxheapSort(Maxheap& mh){
                    if(mh.num_entries > 1){
                        int l = mh.num_entries-1;
                        bool b = false;
                        while(!b){
                        int temp = mh.slots[0];
                        mh.slots[0] = mh.slots[l];
                        mh.slots[l] = temp;
                        l--;
                        if(l > 0)
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
    Maxheap h(N);

    int entries;
    cout << "Give me the number of entries that you would like to insert \n";
    cin >> entries;

    cout << "Give me your entries \n";
    int i = 0;
    int e;
    while(i < entries){
        cin >> e;
        h.insertMaxheap(h,e);
        i++;
        cout << "\n";
    }

    cout << "Your heap is \n";
    h.printMaxheap(h);
    cout << "\n";

    cout << "Your heap after deleting once is \n";
    h.deleteMaxheap(h);
    h.printMaxheap(h);
    cout << "\n";

    cout << "Your heap after deleting twice is \n";
    h.deleteMaxheap(h);
    h.printMaxheap(h);
    cout << "\n";

    cout << "Your heap after sorting is \n";
    h.maxheapSort(h);
    h.printMaxheap(h);
    cout << "\n";



    exit(1);
}