#ifndef PQUEUE_H
#define PQUEUE_H

#include "Vertex.h"


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<vector>
#include<string>


using std::cin;
using std::cout;
using std::end;
using std::vector;
using std::string;

template <typename T1,typename T2,typename T3>
class PQueue{

        public:
             
             vector<Vertex<T1,T2,T3>*> vd;
             int size;
             int num_v;

             PQueue(int s):num_v(0),size(s),vd(s,nullptr){}

             void printQ(PQueue<T1,T2,T3>& pq){
                if(pq.num_v == 0)
                cout << "The queue is empty";
                else{
                    cout << "Your queue elements are: \n";
                    for(int i=0;i<pq.num_v;i++)
                    cout << pq.vd[i]->weight << " ";
                    
                    cout << "\n";
                }
    
             }

             void insert(PQueue<T1,T2,T3>& pq,Vertex<T1,T2,T3> *vx){
                if(pq.num_v >= pq.size)
                cout << "The queue is full";
                else{
                    pq.vd[pq.num_v] = vx;
                    pq.num_v++;
                    
                    bubbleUP(pq);
                }
             }

            
             void bubbleUP(PQueue<T1,T2,T3>& pq){
                    int parent = 0;
                    int child = pq.num_v-1;
                    bool b = true;

                    while(b){
                        parent = (child-1)/2;

                        if(child-1 < 0)
                        b = false;
                        else{
                            if(pq.vd[parent]->weight > pq.vd[child]->weight){
                                Vertex<T1,T2,T3> *temp = pq.vd[parent];
                                pq.vd[parent] = pq.vd[child];
                                pq.vd[child] = temp;
                                child = parent;
                            }else b = false;
                        }
                        
                    }
             }

             Vertex<T1,T2,T3> *pop(PQueue<T1,T2,T3>& pq){

                    Vertex<T1,T2,T3> *r = pq.vd[0]; 
                    pq.vd[0] = pq.vd[pq.num_v-1];
                    pq.vd[pq.num_v-1] = nullptr;
                    pq.num_v--;
                    bubbleDown(pq);
                    
                    return r;
                
             }

             void bubbleDown(PQueue<T1,T2,T3>& pq){
                int l_c = 0;
                int r_c = 0;
                int parent = 0;
                bool b = true;
               
                while(b){
                    l_c = 2*parent+1;
                    r_c = 2*parent+2;

                    if(l_c >= pq.num_v && r_c >= pq.num_v)
                    b = false;
                    else{
                        if(r_c < pq.num_v){
                        
                            if(pq.vd[l_c]->weight <= pq.vd[r_c]->weight){

                                if(pq.vd[parent]->weight > pq.vd[l_c]->weight){
                                    Vertex<T1,T2,T3> *temp = pq.vd[parent];
                                    pq.vd[parent] = pq.vd[l_c];
                                    pq.vd[l_c] = temp;
                                    parent = l_c;
                                }else b = false;

                            }else{
                                
                                if(pq.vd[parent]->weight > pq.vd[r_c]->weight){
                                    Vertex<T1,T2,T3> *temp = pq.vd[parent];
                                    pq.vd[parent] = pq.vd[r_c];
                                    pq.vd[r_c] = temp;
                                    parent = r_c;
                                }else b = false;
                            }

                        }else{
                            if(pq.vd[parent]->weight > pq.vd[l_c]->weight){
                                Vertex<T1,T2,T3> *temp = pq.vd[parent];
                                pq.vd[parent] = pq.vd[l_c];
                                pq.vd[l_c] = temp;
                                parent = l_c;
                            }else b = false;
                        }
                    }
                    
                }
             }
};

#endif

/*
int main(){

    int N;
    int e;
    cout << "Give me the size of your queue \n";
    cin >> N;
    
    PQueue<int,string,string> q(N);
    cout << "\n";

    cout << "Give me the number of elements that you would like to insert \n";
    cin >> e;
    int k = 0;
    int v_id,v_w;
    string v_label,v_data;

    while(k<e){
        cout << "Give me your id, label, and data for vertex, and weight" << k +1 << "\n";
        cin >> v_id;
        cin >> v_label;
        cin >> v_data;
        cin >> v_w;
        Vertex<int,string,string> *vx = new Vertex<int,string,string>(v_id,v_label,v_data);
        vx->weight = v_w;
        q.insert(q,vx);
        
        k++;
    }

    cout << "\n";
    q.printQ(q);
    cout << "\n";

    cout <<"first pop \n";
    q.pop(q);
    q.printQ(q);
    cout << "\n";

    cout << "second pop \n";
    q.pop(q);
    q.printQ(q);
    cout << "\n";


    exit(1);
}*/