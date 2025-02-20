#include "Vertex.h"
#include "Edge.h"

#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<vector>



using std::cin;
using std::cout;
using std::end;
using std::vector;

template <typename T1,typename T2,typename T3>
class Graph{

        public:
              
              int size;
              int num_vertices;
              vector<Edge<T1,T2,T3>> e;

              Graph(int size):size(size),num_vertices(0),e(size){}

              void printGraph(Graph<T1,T2,T3> gr){

                if(gr.num_vertices == 0)
                cout << "The graph is empty";
                else{
                   for(int i = 0;i<gr.size;i++){
                    if(gr.e[i] != nullptr)
                    {
                      cout << "This is vertex: " << gr.e[i].v.label << " \n";
                      Vertex<T1,T2,T3> aux = gr.e[i].v;
                      if(aux.next == nullptr)
                      cout << "This vertex has no connections \n";
                      else{
                        cout << "This vertex has the following connections: \n";
                        while(aux != nullptr){
                          cout << "============> " << aux.label << "\n";
                          aux = aux.next;
                        }
                      }
                    }
                   }
                    
               }
              }

};


int main(){

    cout << "test\n";

    exit(1);
}