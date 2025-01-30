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

            void reverseLinkedlist(Linkedlist<T>& l){


                if(l.head != nullptr && l.head->next != nullptr){
                    Node<T> *prev = nullptr;
                    Node<T> *curr = l.head;
                    Node<T> *succ = l.head->next;

                    while(succ != nullptr){
                        curr->next = prev;
                        prev = curr;

                        curr = succ;
                        succ = succ->next;
                    }
                    curr->next = prev;
                    l.head = curr;

                 
                } 

            }


            Linkedlist<T> merge(Linkedlist<T> l1, Linkedlist<T> l2){

                if(l1.head == nullptr)
                return l2;
                
                if(l2.head == nullptr)
                return l1;

                Linkedlist<T> res;

                Node<T> *aux1 = l1.head;
                Node<T> *aux2 = l2.head;
                Node<T> *temp;

                while(aux1 != nullptr && aux2 != nullptr){
                    if(aux1->data <= aux2->data){
                        if(res.head == nullptr){       
                        res.head = aux1;
                        temp = res.head;
                        aux1 = aux1->next;
                    }else{
                        temp->next = aux1;
                        aux1 = aux1->next;
                        temp = temp->next;
                    }

                }else{
                      if(res.head == nullptr){
                        res.head = aux2;
                        temp = res.head;
                        aux2 = aux2->next;
                      }else{
                            temp->next = aux2;
                            aux2 = aux2->next;
                            temp = temp->next;
                      }
                    
                    }

               }

           
               if(aux1 != nullptr)
               temp->next = aux1;
               
               if(aux2 != nullptr)
               temp->next = aux2;

                return res;
            }


        Node<T>* middleLinkedlist(Linkedlist<T> l){

            Node<T> *prev = l.head;
            Node<T> *aux = l.head;

            while(aux != nullptr){
                aux = aux->next;
                
                if(aux != nullptr){
                    prev = prev->next;
                    aux = aux->next;
                }
            }
            /*
            while(aux != nullptr){[2,1]
             aux = aux->next;
             if(aux != nullptr)
             aux = aux->next;

            if(aux != nullptr)
            prev = prev->next;
             
            }*/

            return prev;
        }


        Linkedlist<T> mergeSortLinkedlist(Linkedlist<T> l,Node<T> *ini,Node<T> *fin){

            if(ini == fin){
                //cout << ini->data << "\n";
                //cout << fin->data << "\n";
                 cout << "test 1\n";
                Linkedlist<T> temp;
                temp.head = ini;
                return temp;
            }else{
                Node<T> *mid = middleLinkedlist(l);
                //cout << mid->data << "\n";
                cout << "test \n";
                Linkedlist<T> split;
                split.head = mid->next;  
                mid->next = nullptr;

                return merge(mergeSortLinkedlist(l,ini,mid),mergeSortLinkedlist(split,split.head,fin));  
                
            }
        }
            
};

    int main(){

        int N1;
        int N2;
        Linkedlist<int> l1;
        Linkedlist<int> l2;
        
        cout << "Introduce the number of elements you would like to insert for the first list:\n";
        cin >> N1;
        
        //cout << "Introduce the number of elements you would like to insert for the second list:\n";
        //cin >> N2;
        
        int d;
        for(int i=0;i<N1;i++){
            cout << "for the first list Give me data number "<< i+1 << " \n";
            cin >> d;
            l1.insertLinkedlist(l1,d);
        }
        cout << "\n";

        /*
        for(int x=0;x<N2;x++){
            cout << "for the second list Give me data number "<< x+1 << " \n";
            cin >> d;
            l2.insertLinkedlist(l2,d);
        }
        cout << "\n";*/

        

        l1.printLinkedlist(l1);
        cout << "\n";

        /*l2.printLinkedlist(l2);
        cout << "\n";
        cout << "\n";*/

        /*Linkedlist<int> r = l1.merge(l1,l2);
        cout << "Your merged list is: \n";
        r.printLinkedlist(r);*/

        /*
        Node<int> *r = l1.middleLinkedlist(l1);
        cout << "your middle point is: " << r->data;
        cout << "\n";*/
        

        /* 4 2 0 1 5 0 19 11 1 9 [0,1,2,0,0,2,2,1]*/

        
        cout << "\n";
        Linkedlist<int> res = l1.mergeSortLinkedlist(l1,l1.head,nullptr); 
        cout << "\n";

        res.printLinkedlist(res);
        cout << "\n";
        exit(0);
    }