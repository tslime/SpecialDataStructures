#ifndef BNODE_H
#define BNODE_H


template <typename T>
class BNode{
         
         public:
                T data;
                BNode<T> *left;
                BNode<T> *right;

                BNode(T data): data(data), left(nullptr),right(nullptr){}
};

#endif