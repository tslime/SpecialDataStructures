#ifndef VERTEX_H
#define VERTEX_H

template <typename T1,typename T2,typename T3>
class Vertex{

            public:
                T1 label;
                T2 id;
                T3 data;
                Vertex<T1,T2,T3> *next;
                int edge_weight;

                Vertex(T1 label,T2 id,T3 data):label(label),id(id),data(data),edge_weight(0),next(nullptr){}
};

#endif  