#ifndef EDGE_H
#define EDGE_H

#include<iostream>
#include<stdlib.h>

#include "Vertex.h"

template <typename T1,typename T2,typename T3>

class Edge{
        
        public:

              Vertex<T1,T2,T3> v;

              Edge():v(nullptr){}


};

#endif