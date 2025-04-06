#include "TNode.h"
#include "THashtable.h"
#include "Trienode.h"

#include<iostream>
#include<malloc.h>
#include<vector>
#include<string>

using std::cin;
using std::cout;
using std::end;
using std::vector;
using std::string;

class Trie{

        public:
            Trienode *root;

            Trie():root(nullptr){}

            
            void initTrienode(Trienode **r,int ini_size){
                *r = new Trienode();
                (*r)->tn = new THashtable(ini_size);
            
                for(int i=0;i<ini_size;i++)
                (*r)->tn->slots[i] = new TNode("");

            }

            void resizeTrienode(Trienode *r,int new_size){
                THashtable *t = new THashtable(new_size);

                for(int i=0;i<new_size;i++){
                    if(i < r->tn->size)
                    t->slots[i] = r->tn->slots[i];
                    else t->slots[i] = new TNode("");
                }

                t->num_c = r->tn->num_c;
                r->tn = t;
            } 


            void insertString(Trienode **r,string w){
                int index;
                TNode *aux = nullptr;

                for(int i=0;i<w.length();i++){
                    index = w[i] - 'a';
                    
                    if(i == 0){
                        if(*r == nullptr)
                        initTrienode(r,index+1);
                        
                        if(index >= (*r)->tn->size)
                        resizeTrienode(*r,index+1);
                        
                        if( (*r)->tn->slots[index]->key == ""){
                            (*r)->tn->slots[index]->key = w[i];
                            (*r)->tn->num_c++;
                        }
                        aux = (*r)->tn->slots[index];

                    }else{
                        
                        if(aux->child == nullptr)
                        initTrienode(&(aux->child),index+1);
                        
                        if(index >= aux->child->tn->size)
                        resizeTrienode(aux->child,index+1);
                        
                        if(aux->child->tn->slots[index]->key == ""){
                            aux->child->tn->slots[index]->key = w[i];
                            aux->child->tn->num_c++;
                        }

                        aux = aux->child->tn->slots[index];
                    }
                }
            }

            void printTrie(Trienode *r,char *k,int ct){
                if(r != nullptr){
                     
                    int i = 0;
                    int j = 0;
                    bool b = false;

                    while(i < r->tn->size && !b){

                        if(j == r->tn->num_c)
                        b = true;
                        else{
                            if(r->tn->slots[i]->key != ""){
                                k[ct] = r->tn->slots[i]->key[0];
                                cout << k << " | ";
                                j++;
                                
                                Trienode *aux = r->tn->slots[i]->child;
                                if(aux != nullptr){
                                 ct++;
                                 printTrie(aux,k,ct);
                                 k[ct] = '\0';
                                 //cout << k << " ";
                                 ct--;
                                }

                                if(ct == 0)
                                cout << "\n \n";
                            }
                        }
                        
                        i++;
                    }
                }
            }




};


int main(){

    Trie *t = new Trie();
    string wr;

    while(true){
        cout << "Give me a word \n";
        cin >> wr;
        t->insertString(&(t->root),wr);
        cout << "\n";
        char *c = (char*)(malloc(100*sizeof(char)));
        t->printTrie(t->root,c,0);
         
    }    

    exit(1);
}
