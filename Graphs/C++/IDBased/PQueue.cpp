#include "Vertex.h"


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<vector>



using std::cin;
using std::cout;
using std::end;
using std::vector;


template <typename T1,typename T2,typename T3>
class PQueue{

        public:
             
             vector<Vertex<T1,T2,T3>> pq;
             int num_v;

             PQueue(int size):pq(size),num_v(0){}

             void printQ(PQueue<T1,T2,T3>& pq){
                if(pq.num_v == 0)
                cout << "The queue is empty";
                else{
                    cout << "Your queue elements are: \n";
                    for(int i=0;i<pq.num_v;i++)
                    cout << pq[i].label << " ";
                    
                    cout << "\n";
                }
    
             }

             void insert(PQueue<T1,T2,T3>& pq,Vertex<T1,T2,T3> vx){
                if(pq.num_v >= pq.size())
                cout << "The queue is full";
                else{
                    pq[pq.num_v] = vx;
                    pq.num_v++;
                    bubbleUP(pq);
                }
             }

             void bubbleUP(PQueue<T1,T2,T3> pq){
                    int parent = 0;
                    int child = pq.num_v-1;
                    bool b = true;

                    while(true){
                        parent = (child-1)/2;

                        if(child-1 < 0)
                        b = false;
                        else{
                            if(pq[parent].weight > pq[child].weight){
                                Vertex<T1,T2,T3> temp = pq[parent];
                                pq[parent] = pq[child];
                                pq[child] = temp;
                                child = parent;
                            }else b = false;
                        }
                        
                    }
             }

             Vertex<T1,T2,T3> pop(PQueue<T1,T2,T3>& pq){
                if(pq.num_v == 0)
                cout << "The queue is empty \n";
                else{
                    Vertex<T1,T2,T3> r = new Vertex<T1,T2,T3>(pq[0].id,pq[0].label,pq[0].data);
                    pq[0] = pq[pq.num_v-1];
                    pq[pq.num_v-1] = nullptr;
                    pq.num_v--;
                    bubbleDown(pq);
                    
                    return r;
                }
             }

             void bubbleDown(PQueue<T1,T2,T3>& pq){
                int l_c = 0;
                int r_c = 0;
                int parent = 0;
                bool b = true;

                while(b){
                    l_c = 2*parent+1;
                    r_c = 2*parent+1;

                    if(l_c > pq.num_v && r_c > pq.num_v)
                    b = false;
                    else{
                        if(r_c <= pq.num_v){

                            if(pq[l_c].weight <= pq[r_c].weight){

                                if(pq[parent].weight > pq[l_c].weight){
                                    Vertex<T1,T2,T3> temp = pq[parent];
                                    pq[parent] = pq[l_c];
                                    pq[l_c] = temp;
                                    parent = l_c;
                                }else b = false;

                            }else{
                                
                                if(pq[parent].weight > pq[r_c].weight){
                                    Vertex<T1,T2,T3> temp = pq[parent];
                                    pq[parent] = pq[r_c];
                                    pq[r_c] = temp;
                                    parent = r_c;
                                }else b = false;
                            }

                        }else{
                            if(pq[parent].weight > pq[l_c].weight){
                                Vertex<T1,T2,T3> temp = pq[parent];
                                pq[parent] = pq[l_c];
                                pq[l_c] = temp;
                                parent = l_c;
                            }else b = false;
                        }
                    }
                    
                }
             }
};



int main(){

    cout << "test\n";

}