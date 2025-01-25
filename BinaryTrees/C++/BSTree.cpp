#include<iostream>
#include<stdlib.h>
#include<malloc.h>

#include "BNode.h"

using std::cin;
using std::cout;
using std::cend;


template <typename T>
class BSTree{

            public:
                   BNode<T> *root;

                   BSTree():root(nullptr){}

                   void printBSTree(BNode<T> *r){
                        if(r !=nullptr){
                           
                           printBSTree(r->left);
                           cout << r->data << " ";
                           printBSTree(r->right); 
                        }
                   }

                   void insertBSTree(BNode<T> **r, T d){

                    if(*r == nullptr){
                        *r = new BNode<T>(d);

                   }else{
                        if(d <= (*r)->data)
                        insertBSTree(&((*r)->left),d);
                        else insertBSTree(&((*r)->right),d);
                   }
                }
                
                BNode<T>* searchBSTree(BNode<T> *r,T d){
                    
                    if(r == nullptr || r->data == d)
                    return r;
                    else{
                         if(d <= r->data )
                         return searchBSTree(r->left,d);
                         else return searchBSTree(r->right,d);
                    }
                    
                }

                void deleteBSTree(BNode<T> **r,T d){
                    
                }



};


int main(){

        int N;
        BSTree<int> t;

        cout << "Give me the number of elements you would like to insert \n";
        cin >> N;
        cout << "\n";

        int i = 0;
        int entry;
        while(i < N){
            cout << "Give me entry number: " << i+1 << " \n";
            cin >> entry;
            t.insertBSTree(&t.root,entry);
            i++;
        }
        cout << "\n";

        t.printBSTree(t.root);
        cout << "\n";

        int e;
        while(true){
          cout << "What is the element you are looking for \n";
          cin >> e;
        
          BNode<int> *res = t.searchBSTree(t.root,e);
          cout << "\n";

          if(res == nullptr)
          cout << "This element does not exist \n";
          else cout << "element found and it is: "<< res->data;
          
          cout << "\n";
        }

exit(0);

}