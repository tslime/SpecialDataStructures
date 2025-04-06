#ifndef TNODE_H
#define TNODE_H


#include <string>

using std::string;

class Trienode;

class TNode{
        
        public:
               string key;
               Trienode *child;

               TNode(string k):key(k),child(nullptr){} 

       



};

#endif