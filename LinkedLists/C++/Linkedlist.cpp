#include<iostream>
#include<stdlib.h>
#include<malloc.h>

#include "Node.h"

using std::cout;
using std::cin;
using std::end;

template <typename T>
class Linkedlist{

    public:
            Node<T> *head;

            Linkedlist(): head(nullptr){}

            void printLinkedlist(const Linkedlist& l){
                if(l.head == nullptr)
                cout << "The list is empty \n";
                else{
                    Node<T> *aux = l.head;
                    while(aux != nullptr){
                        cout << aux->data << " ";
                        aux = aux->next;
                    }
                    cout << "\n";
                }
            }

            void insertLinkedlist(Linkedlist& l,T d){
                if(l.head == nullptr)
                l.head = new Node<T>(d);
                else{
                    Node<T> *aux = l.head;
                    while(aux->next != nullptr)
                    aux = aux->next;
                    
                    aux->next = new Node<T>(d);
                }
            }

            void deleteLinkedlist(Linkedlist& l,T d){
                if(l.head == nullptr)
                cout << "the list is empty \n";
                else{
                    Node<T> *aux = l.head;
                    Node<T> *prev = nullptr;

                    while(aux != nullptr && aux->data != d){
                        prev = aux;
                        aux = aux->next;
                    }

                    if(aux != nullptr){
                        if(prev == nullptr)
                        l.head = l.head->next;
                        else prev->next = aux->next;
                    }
                }
            }

            Node<T>* searchLinkedlist(const Linkedlist& l,T d){
                
                Node<T> *res = nullptr;
                
                if(l.head == nullptr)
                cout << "The list is empty \n";
                else{
                    Node<T> *aux = l.head;
                    while(aux != nullptr && aux->data != d)
                    aux = aux->next;

                    if(aux != nullptr)
                    res = new Node<T>(d);
                }
                
                return res;
            }


            
};

    int main(){

        int N;
        Linkedlist<int> l;
        
        cout << "Introduce the number of elements you would like to insert:\n";
        cin >> N;
        
        int d;
        for(int i=0;i<N;i++){
            cout << "Give me data number "<< i+1 << " \n";
            cin >> d;
            l.insertLinkedlist(l,d);
        }
        cout << "\n";

        l.printLinkedlist(l);
        cout << "\n";

      

        while(true){
              cout << "Give me the element you are looking for \n";
              int e;
              cin >> e;
            
            Node<int> *r = l.searchLinkedlist(l,e);

            if( r != nullptr)
            cout << r->data << " \n";
            else cout << "element does not exist";

            cout << "\n";
        }

        exit(0);
    }