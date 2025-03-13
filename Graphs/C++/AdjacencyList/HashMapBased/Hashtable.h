#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Vertex.h"
#include "HNode.h"
#include "HLinkedlist.h"

#include<vector>


#include<iostream>
#include<stdlib.h>

#include<string>


using std::cin;
using std::cout;
using std::end;
using std::string;
using std::vector;

template<typename T1,typename T2>
class Hashtable{
            
            public:

                int num_elem;
                vector<HLinkedlist<T1,T2>> slot;

                Hashtable(int size):slot(size),num_elem(0){}

                void printHT(Hashtable<T1,T2> tb){
                    if(tb.num_elem == 0)
                    cout << "The hash table is empty \n";
                    else{
                        for(int i=0;i<tb.slot.size();i++){
                            if(tb.slot[i].head == nullptr)
                            cout << "This is slot " << i << " and this slot is empty \n \n";
                            else{
                                cout << "This is slot " << i << " and it contains the follwing items: \n";
                                HNode<T1,T2> *aux = tb.slot[i].head;
                                while(aux != nullptr){
                                    cout << "Key: " << aux->key << " Value: " << aux->value << " || ";
                                    aux = aux->next;
                                }
                                cout << "\n \n ";
                            }
                        }
                        cout << "\n";
                    }
                }   

                int hashcode(Hashtable<T1,T2> tb,T1 k){
                    int code,total = 0;

                    for(int i =0;i<k.length();i++)
                    total = total + k[i]-'0';
                    
                    
                    code = ((total << 4)^total)%tb.slot.size();

                    return code;
                }

                void insertHT(Hashtable<T1,T2>& tb,T1 k,T2 v){
                        
                        if(tb.num_elem >= tb.slot.size())
                        cout << "The hashtable is full \n";
                        else{
                            int code = hashcode(tb,k);

                            if(tb.slot[code].head == nullptr)
                            tb.slot[code].head = new HNode<T1,T2>(k,v);
                            else{
                                HNode<T1,T2> *aux = tb.slot[code].head;
                                while(aux->next != nullptr)
                                aux = aux->next;
                                
                                aux->next = new HNode<T1,T2>(k,v);
                            }
                            tb.num_elem++;
                        }  
                }

                void removeHT(Hashtable<T1,T2>& tb,T1 k){

                    int code = hashcode(tb,k);
                    

                    HNode<T1,T2> *aux = tb.slot[code].head;
                    HNode<T1,T2> *prev = nullptr;
                    bool b = false;

                    while(aux != nullptr && !b){
                        if(aux->key != k){
                            prev = aux;
                            aux = aux->next;
                        }else{
                           
                            b = true;
                            if(prev == nullptr)
                            tb.slot[code].head = tb.slot[code].head->next;
                            else prev->next = aux->next;

                            tb.num_elem--;
                        }
                    }

                    if(!b)
                    cout << "This entry does not exist";
                }

                HNode<T1,T2> *retrieveItem(Hashtable<T1,T2>& tb,T1 k){

                    int code = hashcode(tb,k);
                    HNode<T1,T2> *r = nullptr;

                    HNode<T1,T2> *aux = tb.slot[code].head;

                    while(aux != nullptr && aux->key != k)
                    aux = aux->next;
                    
                    if(aux != nullptr)
                    r = new HNode<T1,T2>(aux->key,aux->value);

                    return r;
                }

};

#endif
/*
int main(){

    int N;
    cout << "Give me the size of your hashtable \n";
    cin >> N;

    Hashtable<string,int> t(N);

    int e;
    cout << "Give me the number of elements you would like to insert \n";
    cin >> e;

    int i = 0;
    int v;
    string k;
    while(i<e){
        cout << "Give me the key and the value of your item number: " << i+1 << "\n";
        cin >> k;
        cin >> v;
        t.insertHT(t,k,v);
        i++;
    }

    cout <<"\n";
    t.printHT(t);

    string elem;
    while(true){
        int nume = t.num_elem;
        cout << "Give me the item that you would like to retrieve \n";
        cin >> elem;
        HNode<string,int> *temp = t.retrieveItem(t,elem);

        cout << "\n";
        if(temp == nullptr)
        cout << "This element does not exist \n";
        else cout << "This element exist and its key is: " << temp->key << " and its value is: " << temp->value << " \n"; 

    }
    


    exit(1);
}*/