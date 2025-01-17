#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include <limits.h>

typedef struct Vertex{
int ID;
char *label;
char *data;
int edge_weight;
struct Vertex *next;
}Vertex;

typedef struct Edge{
Vertex *v;
}Edge;

typedef struct Graph{
int size;
int order;
int degree;
Edge *e[];
}Graph;

typedef struct PQueue{
int s;
int numv;
Vertex *vd[];
}PQueue;

//Priority Queue functions
void printPQ(PQueue *pq);
Vertex *peek(PQueue *pq);
void insert(PQueue *pq,Vertex *v);
void dsizePQ(PQueue *pq);
Vertex *pop(PQueue *pq);
void bubbleUP(PQueue *pq);
void bubbleDOWN(PQueue *pq);

//Graph functions
void printG(Graph *g);
void addVertex(Graph *g,Vertex *v);
void deleteVertex(Graph *g,int v_id);
void addEdge(Graph *g,int src,int dst,int e_w);
void deleteEdge(Graph *g,int src,int dst);

Vertex **dijkstraAlgo(Graph *g, int src);

void main(){

    int N;
    int s;

    //initialization of the graph
    printf("Give me the size of your graph \n");
    scanf("%d",&s);
    Graph *g = (Graph*)malloc(sizeof(Graph)+s*sizeof(Edge));
    g->size = s;
    g->order = 0;
    g->degree = 0;

    int a;
    for(a=0;a<s;a++){
        g->e[a] = (Edge*)(malloc(sizeof(Edge)));
        g->e[a]->v = NULL;
    }
    
    /*
    //initialization  of priority queue
    printf("Give me the size of your queue: \n");
    scanf("%d",&N);
    PQueue *pq = (PQueue*)(malloc(sizeof(PQueue)+N*sizeof(Vertex)));
    pq->s = N;
    pq->numv = 0;
   

  
    int i;
    for(i=0;i<N;i++){
        pq->vd[i] = (Vertex*)(malloc(sizeof(Vertex)));
        pq->vd[i] = NULL;
    }
    */

    int nv;
    printf("Give me the number of vertices would you like to insert: \n");
    scanf("%d",&nv);

    int x = 0;
    int v_id;
    //int v_w;
    while(x<nv){
        char *v_l = (char*)(malloc(100*sizeof(char)));
        char *v_d = (char*)(malloc(100*sizeof(char)));

        printf("Give me the id, label, and the data of your vertex \n");
        scanf("%d",&v_id);
        scanf("%s",v_l);
        scanf("%s",v_d);
        //scanf("%d",&v_w);

        Vertex *temp = (Vertex*)(malloc(sizeof(Vertex)));
        temp->ID = v_id;
        temp->label = v_l;
        temp->data = v_d;
        //temp->edge_weight = v_w;

        addVertex(g,temp);
        x++;
    }

    int c = 1;
    int sr;
    int ds;
    int vw;
    while(c){
        printf("Would you like to add an edge 1 for yes/0 for no\n");
        scanf("%d",&c);
        if(c){
        printf("Give me the ids of the source and destination vertices and the edge weight: \n");
        scanf("%d",&sr);
        scanf("%d",&ds);
        scanf("%d",&vw);
        addEdge(g,sr,ds,vw);
        printf("\n");
         }
    }
    
    printf("\n");
    printG(g);
    printf("\n");

    while(true){
    int src_v;
    printf("Give me the source vertex for which you want to calculate the distance to other vertices:\n");
    scanf("%d",&src_v);

    Vertex **r = dijkstraAlgo(g,src_v);
    printf("\n");

    printf("The distances from %s to other vertices is: \n",g->e[src_v]->v->label);
    int k;
    for(k=0;k<g->order;k++){
        printf("=========> %s, distance: %d \n",r[k]->label,r[k]->edge_weight);
    }
    printf("\n");

    }
}




//Graph functions

Vertex **dijkstraAlgo(Graph *g, int src){

    Vertex **res = (Vertex**)(malloc(g->order*sizeof(Vertex*)));
    PQueue *pq = (PQueue*)(malloc(sizeof(PQueue)));
    pq->s = g->order;
    pq->numv = 0;

    int i;
    for(i=0;i<g->order;i++){
        res[i] = (Vertex*)(malloc(sizeof(Vertex)));
        res[i] = NULL;
        pq->vd[i] = (Vertex*)(malloc(sizeof(Vertex)));
        pq->vd[i] = NULL;
    

        Vertex *temp = (Vertex*)(malloc(sizeof(Vertex)));
        temp->ID = g->e[i]->v->ID;
        temp->label = g->e[i]->v->label;
        temp->data = g->e[i]->v->data;

        if(g->e[i]->v->ID == src){
            temp->edge_weight = 0;
            insert(pq,temp);
        }else temp->edge_weight = INT_MAX;
    
        res[i] = temp;
    }

    int totald = 0;
    while(pq->numv > 0){
        Vertex *temp = pop(pq);
        Vertex *aux = g->e[temp->ID]->v->next;

        while(aux != NULL){
            totald = temp->edge_weight + aux->edge_weight; 

            if(totald < res[aux->ID]->edge_weight){
                res[aux->ID]->edge_weight = totald;
                insert(pq,res[aux->ID]);
            }
            aux = aux->next;
        }
    }

    return res;
}

void printG(Graph *g){
    if(g->order == 0)
    printf("The graph is empty");
    else{
        int i;
        for(i=0;i<g->size;i++){
           if(g->e[i]->v != NULL){ 
            printf("Vertex: %s \n",g->e[i]->v->label);
            if(g->e[i]->v->next == NULL){
            printf("This vertex has no connections \n");
            printf("\n");
            }else{
                printf("This Vertex has the following connections: \n");
                Vertex *aux = g->e[i]->v->next;
                while(aux != NULL){
                    printf("==========> %s , with edge weight: %d \n",aux->label,aux->edge_weight);
                    aux = aux->next;
                }
                printf("\n");
            }
        }
      } 
    }
    printf("\n");
}


void addVertex(Graph *g,Vertex *ve){
    if(g->order >= g->size)
    printf("There is no space left to add a vertex \n");
    else{
        g->e[g->order]->v = ve;
        g->order++;
    }
}

void deleteVertex(Graph *g,int v_id){
    if(v_id < 0 || v_id >g->size)
    printf("The vertex ID is invalid");
    else{
        if(g->e[v_id]->v == NULL)
        printf("This vertex does not exist in the graph");
        else{
            int i;
            for(i=0;i<g->size;i++){
                if(g->e[i]->v != NULL)
                {
                 if(g->e[i]->v->ID == v_id)
                 g->e[i]->v = NULL;
                 else{
                    Vertex *aux = g->e[i]->v->next;
                    Vertex *prev = NULL;
                    bool b = false;

                    while(!b && aux != NULL){
                        if(aux->ID != v_id){
                            prev = aux;
                            aux = aux->next;
                        }else b = true;
                    }

                    if(b){
                        
                        if(prev == NULL)
                        g->e[i]->v->next = g->e[i]->v->next->next;
                        else prev->next = aux->next;

                        g->order--;
                    }
                 }   
                }
            }
        }
    }
}

void addEdge(Graph *g,int src,int dst,int e_w){
    if(src >= g->size || dst >= g->size || src < 0 || dst <0)
    printf("Either the source or destination are invalid\n");
    else{
        if(g->e[src]->v == NULL || g->e[dst]->v == NULL)
        printf("either the source or destination do not exist \n");
        else{
            Vertex *temp = (Vertex*)(malloc(sizeof(Vertex)));
            temp->ID = g->e[dst]->v->ID;
            temp->label = g->e[dst]->v->label;
            temp->data = g->e[dst]->v->data;
            temp->edge_weight = e_w;

            Vertex *aux = g->e[src]->v;
            while(aux->next != NULL)
            aux = aux->next;

            aux->next = temp;
            g->degree++;
        }
    }
}

void deleteEdge(Graph *g,int src,int dst){
    if(src < 0 || dst <0 || src > g->size || dst > g->size)
    printf("Either the source or destination are invalid");
    else{
        if(g->e[src]->v == NULL || g->e[dst]->v == NULL)
        printf("Either the source or destination do not exist");
        else{
            Vertex *aux = g->e[src]->v->next;
            Vertex *prev = NULL;
            bool b = false;
            while(!b && aux != NULL){
                if(aux->ID != dst){
                prev = aux;
                aux = aux->next;
                }else b = true;
            }

            if(b){
                if(prev == NULL)
                g->e[src]->v->next = g->e[src]->v->next->next;
                else prev->next = aux->next;

                g->degree--;
            }else printf("There is no edge between both vertices");

        }
    }
}




//Priority Queue functions

void printPQ(PQueue *pq){
    if(pq->numv == 0)
    printf("The queue is empty \n");
    else{
        
        int i;
        for(i=0;i<pq->numv;i++)
        printf("%d ",pq->vd[i]->edge_weight);
        
        
    }
    printf("\n");
}





Vertex *peek(PQueue *pq){

    if(pq->numv ==0)
    printf("The queue is empty \n");
    else{
        Vertex *rp = (Vertex*)(malloc(sizeof(Vertex)));
        rp = pq->vd[0];
        return rp;
    }
}

void dsizePQ(PQueue *pq){

}

void insert(PQueue *pq,Vertex *v){

    if(pq->numv >= pq->s)
    dsizePQ(pq);
    else{
        pq->vd[pq->numv] = v;
        pq->numv++;
        bubbleUP(pq);
    } 
}

void bubbleUP(PQueue *pq){

    int k = pq->numv-1;
    int p_index;
    bool b = false;

    while(!b){

        p_index = (k-1)/2;

        if( (k-1) < 0 || pq->vd[k]->edge_weight >= pq->vd[p_index]->edge_weight)
        b = true;
        else{
            Vertex *temp = pq->vd[p_index];
            pq->vd[p_index] = pq->vd[k];
            pq->vd[k] = temp;
            k = p_index;
        }   
    }
}

Vertex *pop(PQueue *pq){
    if(pq->numv > 0){
        Vertex *rp = (Vertex*)(malloc(sizeof(Vertex)));
        rp = pq->vd[0];
        pq->vd[0] = pq->vd[pq->numv-1];
        pq->vd[pq->numv-1] = NULL;
        pq->numv--;
        bubbleDOWN(pq);
        return rp;  
    }
}


void bubbleDOWN(PQueue *pq){
    int k = 0;
    bool b = false;
    int l_c;
    int r_c;

    while(!b){
        l_c = 2*k + 1;
        r_c = 2*k + 2;
         
         if(l_c >= pq->numv && r_c >= pq->numv)
         b = true;
         else{
            if(r_c < pq->numv){
               if(pq->vd[r_c]->edge_weight <= pq->vd[l_c]->edge_weight){
                    if(pq->vd[k]->edge_weight > pq->vd[r_c]->edge_weight){
                        Vertex *temp = pq->vd[k];
                        pq->vd[k] =  pq->vd[r_c];
                        pq->vd[r_c] = temp;
                        k = r_c;
                    }else b = true;

               }else{
                    if(pq->vd[k]->edge_weight > pq->vd[l_c]->edge_weight){
                        Vertex *temp = pq->vd[k];
                        pq->vd[k] =  pq->vd[l_c];
                        pq->vd[l_c] = temp;
                        k = l_c;
                    }else b = true;
               }     
            }else{
                  if(pq->vd[k]->edge_weight > pq->vd[l_c]->edge_weight){
                        Vertex *temp = pq->vd[k];
                        pq->vd[k] =  pq->vd[l_c];
                        pq->vd[l_c] = temp;
                        k = l_c;
                    }else b = true;
            }
         }
    }
   
}





    /*Priority Queue test
    printf("\n");
    printf("How many vertices would you like to insert: \n");
    int nv;
    scanf("%d",&nv);

    int x = 0;
    int v_id;
    int v_w;

    while(x < nv){

    char* v_l = (char*)(malloc(100*sizeof(char)));
    char* v_d = (char*)(malloc(100*sizeof(char)));

    printf("Give me the id, label,data and edge_weight of your vertex \n");
    scanf("%d",&v_id);
    scanf("%s",v_l);
    scanf("%s",v_d);
    scanf("%d",&v_w);

    Vertex *tmp = (Vertex*)(malloc(sizeof(Vertex)));
    tmp->ID = v_id;
    tmp->label = v_l;
    tmp->data = v_d;
    tmp->edge_weight = v_w;
    
    insert(pq,tmp);
    

    x++;
    }


    printf("\n");
    printPQ(pq);
    printf("\n");
    pop(pq);
    pop(pq);
    printf("\n");
    printPQ(pq);
    printf("\n");
    */



        /*
    int d_v;
    int y = 1;
    while(y){
        printf("Would you like to delete a vertex 1 for yes/0 for now\n");
        scanf("%d",&y);
        int bo = g->order;
        if(y){
        printf("Give me the id of the vertex you want to delete\n");
        scanf("%d",&d_v);
        deleteVertex(g,d_v);
        if(g->order < bo)
        printG(g);
      }
     }

    printf("\n \n");    
    int v_src;
    int v_dst;
    while(true){
        int bd = g->degree;
        printf("Give me the source and destination of the edge you would like to delete:\n");
        scanf("%d",&v_src);
        scanf("%d",&v_dst);
        deleteEdge(g,v_src,v_dst);
        printf("\n");
        if(g->degree < bd)
        printG(g);
    }
    */