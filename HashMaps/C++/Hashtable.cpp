#include "HNode.h"
#include "HLinkedlist.h"

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<vector>

using std::cin;
using std::cout;
using std::end;
using std::vector;

template <typename T1,typename T2>
class Hashtable{

    public:

           vector<HLinkedlist<T1,T2>> slot;
           int num_entries;

           Hashtable(int size): slot(size), num_entries(0){}

           void printHT(Hashtable& t){
            if(t.num_entries == 0)
            cout << "The table is empty \n";
            else{
                for(int i = 0;i<t.slot.size();i++){
                    cout << "The entries of slot " << i << " are: \n";
                    if(t.slot.at(i).entry == nullptr)
                    cout << "\n this slot is empty \n";
                    else{
                        HNode<T1,T2> *aux = t.slot.at(i).entry;
                        while(aux != nullptr){
                            cout << "Key: " << aux->key << " Value: " << aux->value << " || ";
                            aux = aux->next;
                        }
                        cout << " \n \n";
                    }
                }
            }

           }

           int hashCode(Hashtable& t,T1 key){
            return 0;
           }

           void insertHT(Hashtable& t,T1 k,T2 v){

                int code = hashCode(k);
                
                HNode<T1,T2> *aux = t.slot.at(code).entry;
                if(aux == nullptr)
                t.slot.at(code).entry = new HNode<T1,T2>(k,v);
                else{
                    while(aux->next != nullptr)
                    aux = aux->next;
                    
                    aux->next = new HNode<T1,T2>(k,v);

                }
                t.num_entries++;


           }

};


int main(){

    cout << "test \n";
    exit(0);
}