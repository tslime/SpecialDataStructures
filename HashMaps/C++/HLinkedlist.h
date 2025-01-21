#ifndef HLINKEDLIST_H
#define HLINKEDLIST_H

#include "HNode.h"

template <typename T1,typename T2>
class HLinkedlist{

    public:

          HNode<T1,T2> *entry;

          HLinkedlist(): entry(nullptr){}
};


#endif