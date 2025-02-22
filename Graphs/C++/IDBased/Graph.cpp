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
              int degree;
              vector<Edge<T1,T2,T3>> e;

              Graph(int size):size(size),num_vertices(0),e(size),degree(0){}

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


              void insertVertex(Graph<T1,T2,T3> gr,Vertex<T1,T2,T3> vx){
                if(gr.num_vertices >= gr.size)
                cout << "There are no spots where to insert a vertex \n";
                else{
                  if(gr.e[vx.id].v == nullptr){
                    gr.e[vx.id].v = vx;
                    gr.num_vertices++;
                  }else cout << "This vertex position is alread taken";            
                }
              }

              void insertEdge(Graph<T1,T2,T3> gr,T1 id1, T2 id2){
                    if(gr.e[id1].v == nullptr || gr.e[id2].v == nullptr)
                    cout << "One of the vertices does not exist \n";
                    else{
                      Vertex<T1,T2,T3> aux = gr.ed[id1].v;
                      while(aux->next != nullptr)
                      aux = aux->next;

                      Vertex<T1,T2,T3> vx = new Vertex<T1,T2,T3>(gr.ed[2].v.id,gr.ed[2].v.label,gr.ed[2].v.data);
                      aux->next = vx;
                      gr.degree++;
                    }
              }

              void deleteVertex(Graph<T1,T2,T3> gr,T1 id){

              }

               void deleteEdge(Graph<T1,T2,T3> gr,T1 id1, T2 id2){

              }

};


int main(){

    cout << "test\n";

    exit(1);
}