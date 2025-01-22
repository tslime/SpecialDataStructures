#include<iostream>
#include<stdlib.h>
#include<malloc.h>

#include "Node.h"


using std::cin;
using std::cout;
using std::end;


template <typename T>
class Queue{
    
    public:
           Node<T> *first;

           Queue():first(nullptr){}

           void printQ(Queue<T>& q){
            if(q.first == nullptr)
            cout << "The queue is empty";
            else{
                Node<T> *aux = q.first;
                while(aux != nullptr){
                    cout << aux->data << " ";
                    aux = aux->next;
                }
                cout << "\n";
            }
           }

           void pushQ(Queue<T>& q,T d){
            if(q.first == nullptr)
            q.first = new Node<T>(d);
            else{
                Node<T> *aux = q.first;
                while(aux->next != nullptr)
                aux = aux->next;
                
                aux->next = new Node<T>(d);
            }
           }

};


int main(){

    Queue<int> q;
    int N;

    cout << "enter the number of elements you would like to insert \n";
    cin >> N;
    cout << "\n";

    int i =0;
    int entry;
    while(i < N){
        cout << "Give me your entry number: " << i << "\n";
        cin >> entry;
        q.pushQ(q,entry);
        i++;
        cout << "\n";

     }

    cout << "\n";
    q.printQ(q);

    exit(0);
}