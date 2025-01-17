#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
#include <limits.h>



//Vertex structure

typedef struct Vertex{
char *label;
int id;
char *data;
int edge_weight;
struct Vertex *next;
}Vertex;


//Hashtable structure and functions

typedef struct HNode{
char *key;
int value;
struct HNode *next;
}HNode;

typedef struct HLinkedlist{
HNode *head;
}HLinkedlist;

typedef struct Hashtable{
int size;
int numEntries;
HLinkedlist *slot[];
}Hashtable;


int calcHashCode(Hashtable *ht,char *k);
void printHT(Hashtable *ht);
void insertHT(Hashtable *ht,char *k,int v);
void removeHT(Hashtable *ht,char *k);
int retrieveID(Hashtable *ht,char *k);


int calcHashCode(Hashtable *ht,char *k){
    int code = 0;
    int total = 0;
    int i;
    
    
    for(i=0;i<strlen(k);i++)
    total = total + (int)k[i];
    
    code = (total^(total >> 4))%ht->size;

    return code;
}

void printHT(Hashtable *ht){
    if(ht->numEntries == 0)
    printf("The hash table is empty");
    else{
     int i;
     for(i=0;i<ht->size;i++){
        HNode *aux = ht->slot[i]->head;
        if(aux == NULL)
        printf("There are no entries in slot %d \n \n", i);
        else{
            printf("The entries in slot %d are: \n",i);
            while(aux != NULL){
                printf("Key: %s, Value: %d || ",aux->key,aux->value);
                aux = aux->next;
        }
        printf("\n \n");
        }
        
     }
    }
}

void insertHT(Hashtable *ht,char *k,int v){

    HNode *n = (HNode*)(malloc(sizeof(HNode)));
    n->key = k;
    n->value = v;

    int code = calcHashCode(ht,k);
    HNode *aux = ht->slot[code]->head;
    

    if(aux == NULL){
    ht->slot[code]->head = n;
    ht->numEntries++;
    }else{
        while(aux->next != NULL)
        aux = aux->next;
        
        aux->next = n;
        ht->numEntries++;
    }
}

void removeHT(Hashtable *ht,char *k){
    int code = calcHashCode(ht,k);
    bool b = false;

    HNode *aux = ht->slot[code]->head;
    HNode *prev = NULL;
    while(aux != NULL && !b){
        if(strcmp(k,aux->key) == 0)
        b = true;
        else{
            prev = aux;
            aux = aux->next;
        }
    }
    
    if(b){
        if(prev == NULL)
        ht->slot[code]->head = ht->slot[code]->head->next;
        else prev->next = aux->next;

        ht->numEntries--;
    }else printf("Entry not found \n");
}



int retrieveID(Hashtable *ht,char *k){
    int id = -1;
    int code = calcHashCode(ht,k);
    bool b = false;

    HNode *aux = ht->slot[code]->head;
    while(aux != NULL && !b){
        if(strcmp(k,aux->key) == 0)
        b = true;
        else aux = aux->next;
    }

    if(b)
    id = aux->value;

    return id;
}




//Priority Queue structure and functions

typedef struct PQueue{
int size;
int numv;
Vertex *vd[];
}PQueue;


void printQ(PQueue *pq);
void dsizeQ(PQueue *pq);
void insertQ(PQueue *pq,Vertex *v);
void bubbleUP(PQueue *pq);
Vertex *popQ(PQueue *pq);
void bubbleDown(PQueue *pq);

void printQ(PQueue *pq){
    if(pq->numv == 0)
    printf("The queue is empty \n");
    else{
        printf("The vertices in the queue are: \n");
        int i = 0;      
        while(i<pq->numv){
            printf("%d ",pq->vd[i]->edge_weight);
            i++;
        }
    }
}


void dsizeQ(PQueue *pq){

}

void insertQ(PQueue *pq,Vertex *v){
    if(pq->numv >= pq->size){
        dsizeQ(pq);
        pq->vd[pq->numv] = v;
        pq->numv++;
        bubbleUP(pq);
    }else{
        pq->vd[pq->numv] = v;
        pq->numv++;
        bubbleUP(pq);
    } 
}

void bubbleUP(PQueue *pq){

    Vertex *temp; 
    int p_index = 0;
    int c_index = pq->numv-1;
    bool b = false;

    while(!b){
        if(c_index > 0){
         p_index = (c_index - 1)/2;

         if(pq->vd[p_index]->edge_weight > pq->vd[c_index]->edge_weight){
            temp = pq->vd[p_index];
            pq->vd[p_index] = pq->vd[c_index];
            pq->vd[c_index] = temp;
            c_index = p_index;
         }else b = true;

        }else b = true;
    }
}

Vertex *popQ(PQueue *pq){
    Vertex *rp;

    if(pq->numv > 0){
    rp = pq->vd[0];
    pq->vd[0] = pq->vd[pq->numv-1];
    pq->vd[pq->numv-1] = NULL;
    pq->numv--;
    bubbleDown(pq);
    }
    
    return rp;
}

void bubbleDown(PQueue *pq){

    int p_index = 0;
    int lc_index;
    int rc_index;
    bool b = false;

    while(!b){

        lc_index = 2*p_index + 1;
        rc_index = 2*p_index + 2;

        if(lc_index >= pq->numv && rc_index >= pq->numv)
        b = true;
        else{
            if(rc_index < pq->numv){
                if(pq->vd[lc_index]->edge_weight <= pq->vd[rc_index]->edge_weight){
                    if(pq->vd[p_index]->edge_weight > pq->vd[lc_index]->edge_weight){
                        Vertex *temp = pq->vd[p_index];
                        pq->vd[p_index] = pq->vd[lc_index];
                        pq->vd[lc_index] = temp;
                        p_index = lc_index;
                    } else b = true;
                }else{
                     if(pq->vd[p_index]->edge_weight > pq->vd[rc_index]->edge_weight){
                        Vertex *temp = pq->vd[p_index];
                        pq->vd[p_index] = pq->vd[rc_index];
                        pq->vd[rc_index] = temp;
                        p_index = rc_index;
                    }else b = true;
                }

            }else{
                 if(pq->vd[p_index]->edge_weight > pq->vd[lc_index]->edge_weight){
                        Vertex *temp = pq->vd[p_index];
                        pq->vd[p_index] = pq->vd[lc_index];
                        pq->vd[lc_index] = temp;
                        p_index = lc_index;
                    } else b = true;
            }
        }
    }

}


//Graph structure and functions

typedef struct Edge{
Vertex *v;
}Edge;

typedef struct Graph{
int size;
int order;
int degree;
Edge *e[];
}Graph;


void printGraph(Graph *g);
void addVertex(Graph *g,Vertex *nv,Hashtable *ht);
void deleteVertex(Graph *g,char *label,Hashtable *ht);
void addEdge(Graph *g,char *src, char *dst,int e_w,Hashtable *ht);
void deleteEdge(Graph *g,char *src,char *dst,Hashtable *ht);


void printGraph(Graph *g){
    if(g->order == 0)
    printf("The graph is empty \n");
    else{
        int i;
        for(i=0;i<g->size;i++){
            
           if(g->e[i]->v != NULL){
             printf("This is vertex: %s",g->e[i]->v->label);
        
             Vertex *aux = g->e[i]->v->next;

             if(aux == NULL)
             printf("\n This vertex has no connections \n \n");
             else{
                printf(" and it has the following connections \n");
                while(aux !=NULL){
                    printf("=======> %s\n",aux->label);
                    aux = aux->next;
                }
                printf("\n \n");
             }
           }
          
        }
    }
}


void addVertex(Graph *g,Vertex *nv,Hashtable *ht){
    if(g->order >= g->size)
    printf("There is no space where to add a vertex \n");
    else{
        g->e[g->order]->v = nv;
        insertHT(ht,nv->label,g->order);
        g->order++;
    }
}


void deleteVertex(Graph *g,char *label,Hashtable *ht){
    int id = retrieveID(ht,label);

    if(id == -1)
    printf("This vertex does not exist \n");
    else{
        int i;
        for(i=0;i<g->size;i++){
            Vertex *aux = g->e[i]->v;
            Vertex *prev = NULL;
            bool b = false;

     
            while(aux != NULL && !b){

                if((strcmp(aux->label,label) == 0))
                b = true;
                else{
                    prev = aux;
                    aux = aux->next;
                }
                
            }
        
            if(b){
                if(prev == NULL)
                g->e[id]->v = NULL;
                else prev->next = aux->next;
            }  
        }
        g->order--;
        removeHT(ht,label);
    }
}

void addEdge(Graph *g,char *src, char *dst,int e_w,Hashtable *ht){
    int src_code = retrieveID(ht,src);
    int dst_code = retrieveID(ht,dst);

    if(src_code == -1 || dst_code == -1)
    printf("Either the source or destination vertex do not exist");
    else{
        Vertex *aux = g->e[src_code]->v;
        bool b = false;

        while(aux->next != NULL && !b){
            if( strcmp(dst,aux->next->label) == 0)
            b = true;
            else aux = aux->next;
        }
        
        if(b)
        printf("This connection already exist");
        else{
             Vertex *temp = (Vertex*)(malloc(sizeof(Vertex)));
             temp->label = g->e[dst_code]->v->label;
             temp->id = g->e[dst_code]->v->id;
             temp->data = g->e[dst_code]->v->data;
             temp->edge_weight = e_w;

             aux->next = temp;
             g->degree++;
        } 
    }
}


void deleteEdge(Graph *g,char *src,char* dst,Hashtable *ht){
    int src_id = retrieveID(ht,src);
    int dst_id = retrieveID(ht,dst);

    if(src_id == -1 || dst_id == -1)
    printf("Either the source or destination do not exist");
    else{
        Vertex *prev = NULL;
        Vertex *aux = g->e[src_id]->v->next;
        bool b = false;

        while(aux != NULL && !b){
            if(strcmp(aux->label,dst) == 0)
            b = true;
            else{
                prev = aux;
                aux = aux->next;
            }
        }

        if(b){
            if(prev == NULL)
            g->e[src_id]->v->next = g->e[src_id]->v->next->next;
            else prev->next = aux->next;
            g->degree--;
        }else printf("There is no connection between %s and %s ",src,dst);
    }
}

Vertex **dijkstraAlgo(Graph *g,char *src,Hashtable *ht){
    Vertex **res = (Vertex**)(malloc(g->order*sizeof(Vertex*)));
    PQueue *q = (PQueue*)(malloc(sizeof(PQueue)+ g->order*sizeof(Vertex)));

    int i;
    for(i=0;i<g->order;i++){
        Vertex *temp = (Vertex*)(malloc(sizeof(Vertex)));
        temp->label = g->e[i]->v->label;
        temp->id = g->e[i]->v->id;
        temp->data = g->e[i]->v->data;

        if(strcmp(temp->label,src)==0){
            temp->edge_weight = 0;
            insertQ(q,temp);
        }else temp->edge_weight = INT_MAX;
        
        res[i] = temp;
    }

    int temp_id;
    int temp_weight;
    int aux_id;
    int total;
    while(q->numv > 0){
        Vertex *temp = popQ(q);
        temp_id = retrieveID(ht,temp->label);
        temp_weight = temp->edge_weight; 

        Vertex *aux = g->e[temp_id]->v->next;

        while(aux != NULL){
            total = temp_weight + aux->edge_weight; 
            aux_id = retrieveID(ht,aux->label);

            if(total < res[aux_id]->edge_weight){
                res[aux_id]->edge_weight = total;
                insertQ(q,res[aux_id]);
            }
            
            aux = aux->next;
        }

    }

    return res;
}


void main(){

  int N;
  printf("Give me the size of you graph \n");
  scanf("%d",&N);

  //graph initialization
  Graph *g = (Graph*)(malloc(sizeof(Graph)+N*sizeof(Edge)));
  g->size = N;
  g->order = 0;
  g->degree = 0;
  int i;
  for(i=0;i<N;i++){
    g->e[i] = (Edge*)(malloc(sizeof(Edge)));
    g->e[i]->v = NULL;
  }

  //Hash table initialization
  Hashtable *t = (Hashtable*)(malloc(sizeof(Hashtable) + N*sizeof(HLinkedlist)));
  t->size = N;
  t->numEntries = 0;
  int a;
  for(a=0;a<N;a++){
    t->slot[a] = (HLinkedlist*)(malloc(sizeof(HLinkedlist)));
    t->slot[a]->head = NULL;
  }

    int x = 0;
    while(x < g->size){
        char *v_l = (char*)(malloc(100*sizeof(char)));
        char *v_d = (char*)(malloc(100*sizeof(char)));
        Vertex *v_entry = (Vertex*)(malloc(sizeof(Vertex)));
        int v_id;
        printf("Give me the label, id, and data of vertex %d\n",x);
        scanf("%s",v_l);
        scanf("%d",&v_id);
        scanf("%s",v_d);
        v_entry->label = v_l;
        v_entry->id = v_id;
        v_entry->data = v_d;
        v_entry->edge_weight = 0;
        addVertex(g,v_entry,t);

        x++;
    }


    printf("Time to add edges: \n\n");

    int d = 1;

    while(d){
        printf("Would you like to add edges  1 for yes / 0 for no \n");
        scanf("%d",&d);

        if(d){

        char *v_src = (char*)(malloc(100*sizeof(char)));
        char *v_dst = (char*)(malloc(100*sizeof(char)));
        int weight;

        printf("Give me your source and destination and edge weight: \n");
        scanf("%s",v_src);
        scanf("%s",v_dst);
        scanf("%d",&weight);
        addEdge(g,v_src,v_dst,weight,t);
        printf("\n");
     } 
    }

    printf("\n\n");
    printGraph(g);
    printf("\n");

    Vertex **r = (Vertex**)(malloc(g->order*sizeof(Vertex*)));
    char *s = (char*)(malloc(100*sizeof(char)));
    while(true){
        printf("Give me the source vertex for which you want to find the distances to other vertices: \n");
        scanf("%s",s);
        r = dijkstraAlgo(g,s,t);
        printf("\n \n");

        printf("The shortest distance from %s to other vertices is: \n\n",s);
        int x;
        for(x=0;x<g->order;x++){
            printf("=======> %s: %d \n",r[x]->label,r[x]->edge_weight);
        }
     printf("\n \n");
    }

  }


/*
   while(true){
        char *s = (char*)(malloc(100*sizeof(char)));

        printf("Give me the vertex's source you want to delete: \n");
        scanf("%s",s);
        int ord = g->order;
        deleteVertex(g,s,t);
        printf("\n");
        if(g->order < ord){
            printGraph(g);
            printf("\n Your updated hashtable is: \n\n");
            printHT(t);
            printf("\n\n");
        }
        

        printf("\n");

    }
*/






/*
  int x = 0;
  while(x < t->size){
    char *e_k = (char*)(malloc(100*sizeof(char)));
    int e_val;
    printf("Give me the key and value of entry %d \n",x+1);
    scanf("%s",e_k);
    scanf("%d",&e_val);
    insertHT(t,e_k,e_val);
    x++;
  }

  printf("\n");
  printHT(t);
  printf("\n");

  char *k_entry = (char*)(malloc(100*sizeof(char)));
  while(true){
    int nentry = t->numEntries;
    printf("Give me the key of the entry that you would like to retried\n");
    scanf("%s",k_entry);
    printf("\n");
    int r = retrieveID(t,k_entry);
    printf("The ID of your entry is: %d",r);

    printf("\n");
  }

*/

/*
  int Nq;
    printf("Give me the size of your queue \n");
    scanf("%d",&Nq);

    //initialization
    PQueue *q = (PQueue*)(malloc(sizeof(PQueue))+Nq*sizeof(Vertex));
    int i;
    q->size = Nq;
    for(i=0;i<Nq;i++){
        q->vd[i] = (Vertex*)(malloc(sizeof(Vertex)));
        q->vd[i] = NULL;
    }

    printf("\n");
    int v_id,v_w;
    
    int x = 0;
    while(x < q->size ){
    char *v_l = (char*)(malloc(100*sizeof(char)));
    char *v_d = (char*)(malloc(100*sizeof(char)));
    printf("Give me the label, id, data, and edge weight of vertex %d\n",x+1);
    scanf("%s",v_l);
    scanf("%d",&v_id);
    scanf("%s",v_d);
    scanf("%d",&v_w);

    Vertex *e = (Vertex*)(malloc(sizeof(Vertex)));
    e->label = v_l;
    e->id = v_id;
    e->data = v_d;
    e->edge_weight = v_w;
    
    insertQ(q,e);
    x++;
    }
    printf("\n");
    printQ(q);
    printf("\n");
    printf("\n");
    printf("The first pop \n");
    popQ(q);
    printQ(q);
    printf("\n");
    printf("The second pop \n");
    popQ(q);
    printQ(q);
    printf("\n");
*/