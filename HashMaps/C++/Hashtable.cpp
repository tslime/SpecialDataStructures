#include "HNode.h"
#include "HLinkedlist.h"

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

template <typename T1,typename T2>
class Hashtable{

    public:

           vector<HLinkedlist<T1,T2>> slot;
           int num_entries;

           Hashtable(int size): slot(size), num_entries(0){}

           void printHT(const Hashtable& t){
            if(t.num_entries == 0)
            cout << "The table is empty \n";
            else{
                for(int i = 0;i<t.slot.size();i++){
                    cout << "The entries of slot " << i << " are: \n";
                    if(t.slot.at(i).entry == nullptr)
                    cout << "This slot is empty \n \n";
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
            
            int code = ((key << 4)^key)%t.slot.size();

            return code;
           }

           void insertHT(Hashtable& t,T1 k,T2 v){

                int code = t.hashCode(t,k);
                
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

           HNode<T1,T2> *searchHT(Hashtable& t,T1 k){
            HNode<T1,T2> *res = nullptr;
            int code = t.hashCode(t,k);

            HNode<T1,T2> *aux = t.slot.at(code).entry;
            while(aux != nullptr && aux->key != k)
            aux = aux->next;

            if(aux != nullptr)
            res = new HNode<T1,T2>(aux->key,aux->value);

            return res;
           }

           void deleteHT(Hashtable& t,T1 k){
            int code = t.hashCode(t,k);

            HNode<T1,T2> *aux = t.slot.at(code).entry;
            HNode<T1,T2> *prev = nullptr;
            bool b = false;
            while(aux != nullptr && !b){
                if(aux->key == k)
                b = true;
                else{
                    prev = aux;
                    aux = aux->next;
                }
            }

            if(b){
                if(prev == nullptr)
                t.slot.at(code).entry = t.slot.at(code).entry->next;
                else prev->next = aux->next;

                t.num_entries--;
            }
           }

};


int main(){

    int N;

    cout << "Give me the size of your hash tabel: \n";
    cin >> N;
    Hashtable<int,string> t(N);
    cout << "\n";
    
    int i = 0;
    int e_k;
    string e_v;

    while(i < N){
        cout << "Give me the key and the value of entyry: " << i << " \n";
        cin >> e_k;
        cin >> e_v;
        t.insertHT(t,e_k,e_v);
        i++;
        cout << "\n";
        
    }

    t.printHT(t);

    cout << "\n";

    
    while(true){

        cout << "give me the key of the entry you are looking for: \n";
        cin >> e_k;
        HNode<int,string> *r = t.searchHT(t,e_k);
        cout << "\n";
        if(r==nullptr)
        cout << "entry not found \n";
        else cout << "the entry key " << r->key <<" the entry value: "<< r->value << "\n";

        cout << "\n";

    }
    exit(0);
}