#include "Vertex.h"
#include "Edge.h"
#include "PQueue.h"

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

              void printGraph(Graph<T1,T2,T3>& gr){

                if(gr.num_vertices == 0)
                cout << "The graph is empty";
                else{
                   for(int i = 0;i<gr.size;i++){
                    if(gr.e[i].v != nullptr)
                    {
                      cout << "This is vertex: " << gr.e[i].v->label << " \n";
                      Vertex<T1,T2,T3> *aux = gr.e[i].v;
                      if(aux->next == nullptr)
                      cout << "This vertex has no connections \n \n";
                      else{
                        cout << "This vertex" << aux->label << " which has the following connections: \n";
                        while(aux != nullptr){
                          cout << "============> " << aux->label << "\n";
                          aux = aux->next;
                        }
                      }
                    }
                   }    
               }
              }


              void insertVertex(Graph<T1,T2,T3>& gr,Vertex<T1,T2,T3> *vx){
                if(gr.num_vertices >= gr.size)
                cout << "There are no spots where to insert a vertex \n";
                else{
                  if(gr.e[vx->id].v == nullptr){
                    gr.e[vx->id].v = vx;
                    gr.num_vertices++;
                  }else cout << "This vertex position is alread taken";            
                }
              }

              void insertEdge(Graph<T1,T2,T3> gr,T1 id1, T2 id2){
                    if(gr.e[id1].v == nullptr || gr.e[id2].v == nullptr)
                    cout << "One of the vertices does not exist \n";
                    else{
                      Vertex<T1,T2,T3> *aux = gr.ed[id1].v;
                      while(aux->next != nullptr)
                      aux = aux->next;

                      Vertex<T1,T2,T3> *vx = new Vertex<T1,T2,T3>(gr.ed[2].v.id,gr.ed[2].v.label,gr.ed[2].v.data);
                      aux->next = vx;
                      gr.degree++;
                    }
              }

              void deleteVertex(Graph<T1,T2,T3> gr,T1 id){
                if(gr.e[id].v == nullptr)
                cout << "This vertex does not exist";
                else{
                  for(int i = 0;i<gr.size;i++){
                    if(gr.e[i].v != nullptr){
                      Vertex<T1,T2,T3> *aux = gr.e[i].v;
                      Vertex<T1,T2,T3> *prev = nullptr;

                      while(aux != nullptr && aux->id != id){
                        prev = aux;
                        aux = aux->next;
                      }

                      if(aux != nullptr){
                        if(prev == nullptr)
                        gr.e[i].v =gr.e[i].v->next;
                        else prev->next = aux->next;
                      }

                    }
                  }
                }
              }

               void deleteEdge(Graph<T1,T2,T3> gr,T1 id1, T2 id2){
                if(gr.e[id1].v == nullptr || gr.e[id2].v == nullptr)
                cout << "either Vertex" << id1 << " or Vertex " << id2 << " does not exist \n";
                else{
                  Vertex<T1,T2,T3> *aux = gr.e[id1].v->next;
                  Vertex<T1,T2,T3> *prev = nullptr;
                  bool b = false;

                  while(aux !=nullptr && !b){
                    if(aux.id == id2)
                    b = true;
                    else{
                      prev = aux;
                      aux = aux->next;
                    }
                  }

                  if(!b)
                  cout << "There is no connection between vertex " << id1 << " and Vertex " << id2 << " \n";
                  else{
                    if(prev == nullptr)
                    gr.e[id1].v->next = gr.e[id1].v->next->next;
                    else prev->next = aux->next;
                  } 

                }
              }

};


int main(){
    
    int N;
    cout << "Give me the size of your graph\n";
    cin >> N;

    Graph<int,string,string> g(N);

    int numv;
    cout << "Give me the number of vertices you would like to insert in your graph \n";
    cin >> numv;
    cout << "\n";

    int i = 0;
    int v_id;
    string v_l, v_d;

    while(i<numv){
      cout << "Give me the id, label and data of vertex " << i << " \n";
      cin >> v_id;
      cin >> v_l;
      cin >> v_d;
      Vertex<int,string,string> *ve = new Vertex<int,string,string>(v_id,v_l,v_d);
      g.insertVertex(g,ve);
      i++; 
      cout << "\n";
    }

   g.printGraph(g);

   cout << "\n";

    exit(1);
}