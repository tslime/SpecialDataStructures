import java.io.*;
import java.util.Scanner;



class Graph<T1,T2>{

    int order;
    int size; 
    Edge<T1,T2> e[];

    @SuppressWarnings("unchecked")
    public Graph(int degree){

        this.order = 0; 
        this.size = 0;      
        this.e = (Edge<T1,T2>[])new Edge[degree];
    
        for(int i=0;i<degree;i++){
           e[i] = new Edge<>();
           e[i].v = null;
        }
    }


    public static<T1,T2> void printG(Graph<T1,T2> g){
      
      for(int i=0;i<g.e.length;i++){
        if(g.e[i].v == null)
        System.out.println("ID "+i+" has no vertices \n");
        else{
            System.out.println("Vertex "+g.e[i].v.label+" has the ID "+g.e[i].v.id+" and data "+g.e[i].v.data);
            if(g.e[i].v.next == null)
            System.out.println("This vertex has no connections \n");
            else{
                Vertex<T1,T2> aux = g.e[i].v.next;
                System.out.println("This vertex have the following connections");
                while(aux != null){
                    System.out.println("=============> "+aux.label+"  "+"Weight "+aux.edge_weight);                    
                    aux = aux.next;
                }
                System.out.println("\n");
            }
        }
      }
    }

    public static<T1,T2> void addVertex(Graph<T1,T2> g, int id,T1 l,T2 data){


        if(g.order == g.e.length)
        System.out.println("There are no free slots to insert a new vertex");
        else{

        Vertex<T1,T2> ve = new Vertex<>(id,l,data);
        g.e[id].v = ve;
        g.order++; 
     } 

    }

    public static<T1,T2> int graphDegree(Graph<T1,T2> g){
        return g.order;
    }

    
    public static<T1,T2> void addEdge(Graph<T1,T2> g,int src_id,int dst_id,int e_weight){

            Vertex<T1,T2> aux = g.e[src_id].v;
            boolean b = (aux.id == dst_id);

            while(aux.next != null && !b){                
                aux = aux.next;
                b = (aux.id == dst_id);
            } 
            
            if(b)
            System.out.println("This connection already exist");
            else{
            int tmp_id = dst_id;
            T1 tmp_label = g.e[dst_id].v.label;
            T2 tmp_data = g.e[dst_id].v.data;
            Vertex<T1,T2> tmp = new Vertex<>(tmp_id,tmp_label,tmp_data);
            tmp.edge_weight = e_weight;
            aux.next = tmp;
            g.size++;
            }
            
    }

    public static<T1,T2> void deleteVertex(Graph<T1,T2> g,int id){

        if(g.e[id].v == null)
        System.out.println("This vertext does not exist in the graph");
        else{
            for(int i=0;i<g.e.length;i++){
              
                    Vertex<T1,T2> prev = null;
                    Vertex<T1,T2> aux = g.e[i].v;
                    boolean b = false;

                    while(aux != null && !b){
                        if(aux.id == id)
                        b = true;
                        else{
                            prev = aux;
                            aux = aux.next;
                         }
                    }
                    
                    if(b){
                        if(prev == null)
                        g.e[i].v = null;
                        else prev.next = aux.next;
                        g.order--;
                    }
                
            }

        }
    }


    public static<T1,T2> void deleteEdge(Graph<T1,T2> g,int source_id,int destination_id){

        if(g.e[source_id] == null || g.e[destination_id] == null)
        System.out.println("one of the vertices does not exist in the graph");
        else{
            Vertex<T1,T2> aux = g.e[source_id].v.next;
            Vertex<T1,T2> prev = null;

            while(aux != null && aux.id != destination_id){
                prev = aux;
                aux = aux.next;
            }

            if(aux == null)
            System.out.println("There is no connection between vertex "+g.e[source_id].v.label+" and the vertex "+g.e[destination_id].v.label);
            else{
                if(prev == null)
                g.e[source_id].v.next = aux.next;
                else prev.next = aux.next;
                g.size--;
            }
            
        }
    }

    @SuppressWarnings("unchecked")
    public static<T1,T2> Vertex<T1,T2>[] dijkstraAlgo(Graph<T1,T2> g, Vertex<T1,T2> src){

        Vertex<T1,T2> resd[] = (Vertex<T1,T2>[])new Vertex[g.order];
        PQueue<T1,T2> pq = new PQueue<>(g.order);
        pq.insert(pq,src);
        src.edge_weight = 0;
        
        int i = 0;
        while(i<resd.length){
            if(g.e[i].v.id != src.id)
            {
              resd[i] = new Vertex<>(g.e[i].v.id,g.e[i].v.label,g.e[i].v.data);
              resd[i].edge_weight = Integer.MAX_VALUE;
              i++;
            }else{
                resd[i] = new Vertex<>(g.e[i].v.id,g.e[i].v.label,g.e[i].v.data);
                i++;
            }
        }

        while(pq.num_vd > 0){
            Vertex<T1,T2> temp = pq.pop(pq);

            Vertex<T1,T2> aux = g.e[temp.id].v;
            while(aux != null){

                if(aux.id != src.id){

                 int new_weight = temp.edge_weight + aux.edge_weight;
                 
                 if( new_weight < resd[aux.id].edge_weight){
                 resd[aux.id].edge_weight = new_weight; 
                 pq.insert(pq,resd[aux.id]); 
                 }  
                    
               
                }

                aux = aux.next;
            }
        } 
       

        return resd;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        int N;
        int num_v;

        System.out.println("Give me the order of your graph");
        N = sc.nextInt();

        Graph<String,String> g = new Graph<>(N);


        System.out.println("How many vertices would you like to insert");
        num_v = sc.nextInt();

        int i = 0;
        while(i < num_v){
            System.out.println("Give me the id, the label, and data of your vertice number: "+(i+1));
            int id_v = sc.nextInt();
            sc.nextLine();
            String label_v = sc.nextLine();
            String data_v = sc.nextLine();
        
            if(id_v < 0 || id_v >= g.e.length)
            System.out.println("This ID is invalid, try a different ID \n");
            else{
                if(g.e[id_v].v != null)
                System.out.println("This ID already exist, try a different ID \n");
                else{
                    addVertex(g,id_v,label_v,data_v);
                    i++;
                     }
                }
        }
        
        

        int b;
        System.out.println("Would you like to add edges? yes/1, no/0");
        b = sc.nextInt();

        while(b == 1){
            System.out.println("Give me the id of your source");
            int src = sc.nextInt();
            System.out.println("Give me the id of your destination");
            int dst = sc.nextInt();
            System.out.println("Give me the edge weight");
            int w = sc.nextInt();

            if(src < 0 || src >= g.e.length || dst < 0 || dst >= g.e.length)
            System.out.println("Either the source or destination are invalid, try again");
            else{
                if( g.e[src].v == null || g.e[dst].v == null)
                System.out.println("Either the source or destination vertex do not exist yet, try again");
                else{
                    addEdge(g,src,dst,w);
                    System.out.println("Would you like to add more edges, yes/1, no/0");
                    b = sc.nextInt();
                }
            }
        }


        System.out.println("");
        printG(g);
        System.out.println("\n");
        System.out.println("The degree of your grapph is: "+graphDegree(g));

        System.out.println("\n");
        

        System.out.println("Give me the the source id of your vertex for which you want to find the distances for all other vertices:");
        int s_id = sc.nextInt();
        Vertex<String,String> src_v = new Vertex<>(s_id,g.e[s_id].v.label,g.e[s_id].v.data); 
        
        Vertex<String,String> result[] = dijkstraAlgo(g,src_v); 

        System.out.println("The distances from "+src_v.label+" to other vertices are:");
        for(int a=0;a<result.length;a++){
            System.out.println("============> "+result[a].label+" distance: "+result[a].edge_weight);
            System.out.println("");
        }



        /*
        while(true){
            int current_size = g.size;
            System.out.println("Give me the id of the source of the edge that you would like to delete");
            int s_v = sc.nextInt();
            System.out.println("Give me the id of the destination of the edge that you would like to delete");
            int d_v = sc.nextInt();
            deleteEdge(g,s_v,d_v);
            int new_size = g.size;
            if(new_size < current_size)
            printG(g);
            System.out.println("\n");

        }*/
    }   
}