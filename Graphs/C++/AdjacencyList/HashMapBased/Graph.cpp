#include "Vertex.h"
#include "Edge.h"
#include "Hashtable.h"
#include "PQueue.h"

#include<iostream>
#include<string>
#include<vector>
#include<limits>

using std::cin;
using std::cout;
using std::end;
using std::vector;
using std::string;
using std::numeric_limits;

template<typename T1,typename T2,typename T3>
class Graph{

            public:
                int num_vertices,degree;
                vector<Edge<T1,T2,T3>> e;

                Graph(int size):num_vertices(0),degree(0),e(size){}

                void printG(Graph<T1,T2,T3> g){
                    if(g.num_vertices == 0)
                    cout << "The graph is empty \n";
                    else{
                        for(int i=0;i<g.e.size();i++){
                            if(g.e[i].v != nullptr){
                                cout << "This is vertex " << g.e[i].v->label << " ";
                                Vertex<T1,T2,T3> *aux = g.e[i].v->next;

                                if(aux == nullptr)
                                cout << " and this vertex has no connections \n \n";
                                else{
                                    cout << " and this vertex has the following connections: \n";
                                    while(aux!=nullptr){
                                        cout << " ========> " << aux->label << "\n";
                                        aux = aux->next;
                                    }
                                    cout << "\n \n";
                                }
                            }
                        }

                        cout <<"\n";
                    }
                }


                void insertVertex(Graph<T1,T2,T3>& g,Vertex<T1,T2,T3> *vx,Hashtable<T1,T2>& tb){
                    if(g.num_vertices >= g.e.size())
                    cout << "The graph is full \n";
                    else{
                        if(g.e[vx->id].v != nullptr)
                        cout << "This vertex already exist \n";
                        else{
                            g.e[vx->id].v = vx;
                            g.num_vertices++;
                            tb.insertHT(tb,vx->label,vx->id);
                        }

                    }
                    
                }

                void deleteVertex(Graph<T1,T2,T3>& g,T1 lb,Hashtable<T1,T2>& tb){
                    HNode<T1,T2> *item = tb.retrieveItem(tb,lb);

                    if(item == nullptr)
                    cout << "This vertex does not exist";
                    else{
                        for(int i=0;i<g.e.size();i++){
                            if(g.e[i].v != nullptr){
                                Vertex<T1,T2,T3> *aux = g.e[i].v;
                                Vertex<T1,T2,T3> *prev = nullptr;
                                bool b = false;

                                while(aux != nullptr && !b){
                                    if(aux->label == lb)
                                    b = true;
                                    else{
                                        prev = aux;
                                        aux = aux->next;
                                    }
                                }

                                if(b){
                                   

                                    if(prev == nullptr)
                                    g.e[i].v = nullptr;
                                    else prev->next = aux->next;
                                }
                            }
                        }
                     
                     tb.removeHT(tb,lb);
                     g.num_vertices--;
                    }
                }

                void insertEdge(Graph<T1,T2,T3>& g,T1 lb1,T1 lb2,int w,Hashtable<T1,T2>& tb){
                    HNode<T1,T2> *item1 = tb.retrieveItem(tb,lb1);
                    HNode<T1,T2> *item2 = tb.retrieveItem(tb,lb2);

                    if(item1 == nullptr || item2 == nullptr)
                    cout << "Either " << lb1 << " or " << lb2 << " does not exist \n";
                    else{
                        Vertex<T1,T2,T3> *temp = new Vertex<T1,T2,T3>(g.e[item2->value].v->label,g.e[item2->value].v->id,g.e[item2->value].v->data);
                        temp->edge_weight = w;

                        Vertex<T1,T2,T3> *aux = g.e[item1->value].v;
                        while(aux->next != nullptr)
                        aux = aux->next;

                        aux->next = temp;
                        g.degree++;
                    }

                }

                void removeEdge(Graph<T1,T2,T3>& g,T1 lb1,T1 lb2,Hashtable<T1,T2>& tb){
                    HNode<T1,T2> *item1 = tb.retrieveItem(tb,lb1);
                    HNode<T1,T2> *item2 = tb.retrieveItem(tb,lb2);

                    if(item1 == nullptr || item2 == nullptr)
                    cout << "Either " << lb1 << " or "<< lb2 << " do not exist \n";
                    else{
                        Vertex<T1,T2,T3> *aux = g.e[item1->value].v->next;
                        Vertex<T1,T2,T3> *prev = nullptr;
                        bool b = false;

                        while(aux != nullptr && !b){
                            if(aux->label == lb2)
                            b = true;
                            else{
                                prev = aux;
                                aux = aux->next;
                            }
                        }

                        if(!b)
                        cout << "There is no connection between "<< lb1 << " and " << lb2 << "\n";
                        else{
                            if(prev == nullptr)
                            g.e[item1->value].v->next = g.e[item1->value].v->next->next;
                            else prev->next = aux->next;
                            
                            g.degree--;
                        }

                    }

                }


                vector<Vertex<T1,T2,T3>*> DijkstraAlgo(Graph<T1,T2,T3>& g,T1 lb,Hashtable<T1,T2>& tb){

                    vector<Vertex<T1,T2,T3>*> res(g.num_vertices);
                    HNode<T1,T2> *item = tb.retrieveItem(tb,lb);

                    if(item == nullptr)
                    return res;

                    PQueue<T1,T2,T3> q(g.num_vertices);
                    
                    //Initiliaze distances
                    for(int i=0;i<g.e.size();i++){
                        if(g.e[i].v != nullptr){
                            res[g.e[i].v->id] = new Vertex<T1,T2,T3>(g.e[i].v->label,g.e[i].v->id,g.e[i].v->data);
                            
                            if(g.e[i].v->label == lb){
                                res[g.e[i].v->id]->edge_weight = 0;
                                q.insert(q,res[g.e[i].v->id]);
                            }else res[g.e[i].v->id]->edge_weight = numeric_limits<int>::max();
                        }
                    }

                   
                    while(q.num_v > 0){
                        Vertex<T1,T2,T3> *temp = q.pop(q);
                        int total = 0;
                        
                        Vertex<T1,T2,T3> *aux = g.e[temp->id].v->next;
                        while(aux != nullptr){
                            total = temp->edge_weight;
                            total = total + aux->edge_weight;

                            if(total < res[aux->id]->edge_weight){
                                res[aux->id]->edge_weight = total;
                                q.insert(q,res[aux->id]);
                            }
                            aux = aux->next;
                        }
                    }

                    return res;
                }

};


int main(){

    int N;
    

    cout << "Give me the size of your graph \n";
    cin >> N;
    Graph<string,int,string> g(N);
    Hashtable<string,int> t(N);
  
    
    cout << "\n";

    int e;
    cout << "Give me the number of vertices you would like to insert \n";
    cin >> e;

    int i = 0;
    string v_lb,v_d;
    int v_id;
    
    while(i < e){
        cout << "Give me the lable, id, data for vertex number " << i << "\n";
        cin >> v_lb;
        cin >> v_id;
        cin >> v_d;
        Vertex<string,int,string> *temp = new Vertex<string,int,string>(v_lb,v_id,v_d);
        g.insertVertex(g,temp,t);
       
        i++;
    }

    cout << "\n";

    int b = 1, w = 0;
    string v_lb1,v_lb2;
    while(b){
        cout << "Would you like to add an edge 1 for yes/0 for no: \n";
        cin >> b;
        if(b){
        cout << "Give me the labels for your edges and the edge weight \n";
        cin >> v_lb1;
        cin >> v_lb2;
        cin >> w;
        g.insertEdge(g,v_lb1,v_lb2,w,t);
        cout << "\n";
         }
    }
    
    cout <<"\n";
    g.printG(g);
    cout << " \n";

    string target_v;
    while(true){
        cout << "Give me the vertex for which you would like to calculate the distance to other vertices: \n";
        cin >> target_v;


        
        vector<Vertex<string,int,string>*> r = g.DijkstraAlgo(g,target_v,t);
        cout << "\n";
        
        if(r[0] == nullptr)
        cout << "This vertex does not exist \n";
        else{
            cout << "The distance from " << target_v << " To: \n";
            for(int i = 0;i<r.size();i++){
                cout << " =================> " << r[i]->label << " Distance: " << r[i]->edge_weight << " \n"; 
            }
            cout << " \n";
        }
    }


    /*cout << "Your table is \n";
    t.printHT(t);
    cout << "\n \n";
    */


    /*
    string v1,v2;
    while(true){
        int n = g.degree;
        cout << "Give me the vertices of the edge you would like to delete \n";
        cin >> v1;
        cin >> v2;
        g.removeEdge(g,v1,v2,t);
        
        cout << "\n";
        if(g.degree < n)
        g.printG(g);

        cout << "\n";
    }*/




    exit(1);
}