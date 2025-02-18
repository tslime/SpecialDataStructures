#ifndef VERTEX_H
#define VERTEX_H

#include<iostream>
#include<stdlib.h>




template <typename T1,typename T2,typename T3>

class Vertex{

        public:
              T1 id;
              T2 label;
              T3 data;
              int weight;
              Vertex<T1,T2,T3> *next;

              Vertex(T1 id,T2 label,T3 data):id(id),label(label),data(data),weight(0),next(nullptr) {}



};

#endif