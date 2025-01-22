#include<iostream>
#include<stdlib.h>
#include<malloc.h>

#include "Node.h"


using std::cin;
using std::cout;
using std::cend;


template <typename T>
class Stack{

        public:

              Node<T> *top;

              Stack():top(nullptr){} 

              void printS(Stack<T>& s){
                if(s.top == nullptr)
                cout << "The stack is empty \n";
                else{
                    Node<T> *aux = s.top;
                    while(aux!=nullptr){
                        cout << aux->data << " ";
                        aux = aux->next;
                    }
                    cout << "\n";
                }
              }

              void pushS(Stack<T>& s,T d){
                if(s.top == nullptr)
                s.top = new Node<T>(d);
                else{
                    Node<T> *temp = new Node<T>(d);
                    temp->next = s.top;
                    s.top = temp;

                }
              }

};


int main(){

    Stack<int> s;
    int N;

    cout << "give me the number of entires you would like to insert \n";
    cin >> N;

    int i = 0;
    int entry;
    while(i<N){
        cout << "Give me entry number: "<< i << " \n";
        cin >> entry;
        s.pushS(s,entry);
        i++;
        cout << "\n";
    }
    cout << "\n";

    s.printS(s);

    exit(0);
}