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
                      cout << "This is vertex " << gr.e[i].v->label;
                      Vertex<T1,T2,T3> *aux = gr.e[i].v->next;
                      if(aux == nullptr)
                      cout << " \n This vertex has no connections \n \n";
                      else{
                        cout << " which has the following connections: \n";
                        while(aux != nullptr){
                          cout << "============> " << aux->label << "\n";
                          aux = aux->next;
                        }
                        cout << "\n";
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

              void insertEdge(Graph<T1,T2,T3> gr,T1 id1, T1 id2){
                    if(id1 >= gr.num_vertices || id2 >= gr.num_vertices || id1 < 0 || id2 < 0 || gr.e[id1].v == nullptr || gr.e[id2].v == nullptr || id1 == id2)
                    cout << "One of the vertices does not exist or you are inputting the same vertex id\n";
                    else{
                      Vertex<T1,T2,T3> *aux = gr.e[id1].v;
                      bool b = false;

                      while(aux->next != nullptr && !b){
                        if(aux->next->id == id2)
                        b = true;
                        else aux = aux->next;
                      }
                      
                      if(b)
                      cout << "this connection already exist \n";
                      else{
                          Vertex<T1,T2,T3> *vx = new Vertex<T1,T2,T3>(gr.e[id2].v->id,gr.e[id2].v->label,gr.e[id2].v->data);
                          aux->next = vx;
                          gr.degree++;
                      }
                    }
              }

              void deleteVertex(Graph<T1,T2,T3>& gr,T1 id){
                if(gr.e[id].v == nullptr || id < 0 || id >= gr.num_vertices)
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
                        gr.e[i].v = nullptr;
                        else prev->next = aux->next;
                      }

                    }

                  }
                }
              }

               void deleteEdge(Graph<T1,T2,T3>& gr,T1 id1, T1 id2){
                if(id1 < 0 || id2 < 0 || id1 >= gr.num_vertices || id2 >= gr.num_vertices || gr.e[id1].v == nullptr || gr.e[id2].v == nullptr)
                cout << "either Vertex" << id1 << " or Vertex " << id2 << " does not exist \n";
                else{
                  Vertex<T1,T2,T3> *aux = gr.e[id1].v->next;
                  Vertex<T1,T2,T3> *prev = nullptr;
                  bool b = false;

                  while(aux !=nullptr && !b){
                    if(aux->id == id2)
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

              Vertex<T1,T2,T3> *dijsktraAlgor(Graph<T1,T2,T3> gr, T1 id){

                return nullptr;
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


   bool b = true;
   int id1,id2;
   while(b){
    cout << "Would you like to add an edge 1=(yes)/0(no) \n";
    cin >> b;
    if(b){
     cout << "Give me the ids of your vertices \n";
     cin >> id1;
     cin >> id2;
     g.insertEdge(g,id1,id2);
     cout << "\n";
    }
    cout << "\n";

   }

   g.printGraph(g);

   cout << "\n";
   
   int vd1,vd2;
   while(true){
    cout << "give me the id of the vertices that you would like to unlink \n";
    cin >> vd1;
    cin >> vd2;
    g.deleteEdge(g,vd1,vd2);
    cout << "\n";
    g.printGraph(g);
    cout << "\n";
   }
   

    exit(1);
}