#ifndef HNODE_H
#define HNODE_H

template<typename T1,typename T2>
class HNode{
         
         public:
            T1 key;
            T2 value;
            HNode<T1,T2> *next;

            HNode(T1 k,T2 v):key(k),value(v),next(nullptr){}
};

#endif