import java.io.*;
import java.util.Scanner;


class Graph<T1,T2,T3>{

    int order;
    int degree;
    int size;
    Edge<T1,T3> e[];
  

    @SuppressWarnings("unchecked")
    public Graph(int size){
        this.size = size;
        this.order = 0;
        this.degree = 0;
        this.e = (Edge<T1,T3>[])new Edge[size];

        for(int i=0;i<size;i++){
            e[i] = new Edge();
            e[i].v = null;
        }
    }

    public static<T1,T2,T3> void printGraph(Graph<T1,T2,T3> g){
        if(g.order == 0)
        System.out.println("The graph is empty");
        else{
            for(int i=0;i<g.size;i++){
                
                if(g.e[i].v != null){
                System.out.print("This is vertex: "+ g.e[i].v.label);
                Vertex<T1,T3> aux = g.e[i].v.next;
                if(aux == null)
                System.out.println("\n This vertex has no connections\n");
                else{
                    System.out.println(" and this Vertex has the following connections");
                    while(aux != null){
                        System.out.println("==========> "+aux.label);
                        aux = aux.next;
                    }
                 System.out.println("");
                }

             }  
            }
        }
    }

    @SuppressWarnings("unchecked")
    public static<T1,T2,T3> void addVertex(Graph<T1,T2,T3> g,Vertex<T1,T3> e,Hashtable<T1,T2> t){
        if(g.order >= g.size)
        System.out.println("The graph is full");
        else{
            g.e[g.order].v = e;
            Hashtable.insertHT(t,e.label,(T2)Integer.valueOf(g.order));
            g.order++;
        }

    }

    public static<T1 extends Comparable<T1>,T2,T3> void addEdge(Graph<T1,T2,T3> g,T1 src,T1 dst,int e_w,Hashtable<T1,T2> t){
        HNode<T1,T2> src_id = Hashtable.searchHT(t,src);
        HNode<T1,T2> dst_id = Hashtable.searchHT(t,dst);

        if(src_id == null || dst_id == null)
        System.out.println("Either the vertex source or destination does not exist");
        else{
            Vertex<T1,T3> aux = g.e[(Integer)src_id.value].v;
            boolean b = false;
            while(aux.next != null && !b){
                aux = aux.next;
                
                if(dst.compareTo(aux.label)==0)
                b = true;
            }
            
            if(b)
            System.out.println("A connection between "+src+" and "+dst+" already exists");
            else{
                Vertex<T1,T3> temp = new Vertex<>(g.e[(Integer)dst_id.value].v.label,g.e[(Integer)dst_id.value].v.ID,g.e[(Integer)dst_id.value].v.data);
                temp.edge_weight = e_w;
                aux.next = temp;
                g.degree++;
            }
           
        }
    }

    public static<T1 extends Comparable<T1>,T2,T3> void deleteVertex(Graph<T1,T2,T3> g, T1 src,Hashtable<T1,T2> t){
        HNode<T1,T2> v_src = Hashtable.searchHT(t,src);

        if(v_src == null)
        System.out.println("This vertex does not exist");
        else{
            for(int i=0;i<g.size;i++){
                Vertex<T1,T3> aux = g.e[i].v;
                Vertex<T1,T3> prev = null;
                boolean b = false;

                while(aux != null && !b){
                    if(src.compareTo(aux.label) == 0)
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
                }
            }
            Hashtable.deleteHT(t,src);
            g.order--;
        }
    } 


    public static<T1 extends Comparable<T1>,T2,T3> void deleteEdge(Graph<T1,T2,T3> g,T1 src,T1 dst,Hashtable<T1,T2> t){
        HNode<T1,T2> src_v = Hashtable.searchHT(t,src);
        HNode<T1,T2> dst_v = Hashtable.searchHT(t,dst);

        //System.out.println("Test 1 "+ dst_v.key);

        if(src_v == null || dst_v == null)
        System.out.println("Either the destination or source vertex does not exist");
        else{
            Vertex<T1,T3> aux = g.e[(Integer)src_v.value].v.next;
            Vertex<T1,T3> prev = null;
            boolean b = false;

            while(aux != null && !b){
                if(dst.compareTo(aux.label) == 0)
                b = true;
                else{
                    prev = aux;
                    aux = aux.next;
                }
            }

            //System.out.println("test: "+aux.label);
            if(b){
                g.degree--;
                if(prev == null)
                g.e[(Integer)src_v.value].v.next = g.e[(Integer)src_v.value].v.next.next;
                else prev.next = aux.next;
            }else System.out.println("There is no connection between "+src+" and "+dst);
        }
    }

    @SuppressWarnings("unchecked")
    public static<T1 extends Comparable<T1>,T2,T3> Vertex<T1,T3>[] DijkstraAlgo(Graph<T1,T2,T3> g,T1 src,Hashtable<T1,T2> t){
        Vertex<T1,T3> res[] = (Vertex<T1,T3> [])new Vertex[g.size];
        HNode<T1,T2> src_v = Hashtable.searchHT(t,src);
        PQueue q = new PQueue(g.size);

        if( src == null)
        System.out.println("This vertex does not exist");
        else{
        for(int i=0;i<g.size;i++){
            Vertex<T1,T3> temp = new Vertex(g.e[i].v.label,g.e[i].v.ID,g.e[i].v.data);
            if(src.compareTo(g.e[i].v.label) == 0){
                temp.edge_weight = 0;
                PQueue.insert(q,temp);

            } else temp.edge_weight = Integer.MAX_VALUE;
            res[i] = temp;
        }

        int total_d;
        while(q.num_vd > 0){
         Vertex<T1,T3> popped_v = PQueue.pop(q);
         HNode<T1,T2> popped_v_id = Hashtable.searchHT(t,popped_v.label);
         Vertex<T1,T3> aux = g.e[(Integer)popped_v_id.value].v.next;

         while( aux != null){
            total_d = popped_v.edge_weight + aux.edge_weight;
            Integer aux_id = (Integer)(Hashtable.searchHT(t,aux.label).value);

            if(total_d < res[aux_id].edge_weight){
                res[aux_id].edge_weight = total_d;
                PQueue.insert(q,res[aux_id]);
            }

            aux = aux.next;
         }   
         

        }
      }

        return res;
    }



public static void main(String arg[]){

    int N;
    Scanner sc = new Scanner(System.in);


    System.out.println("Give me the size of you graph");
    N = sc.nextInt();

    Graph<String,Integer,String> g = new Graph<>(N);
    Hashtable<String,Integer> t = new Hashtable<>(N);
    
    int i = 0;
    Integer v_id;
    String v_l,v_d;
    while(i<N){
        System.out.println("Give me the label, id, and data for vertex: "+i);
        v_l = sc.next();
        v_id = sc.nextInt();
        v_d = sc.next();
       
        
        Vertex<String,String> temp = new Vertex<>(v_l,v_id,v_d);
        addVertex(g,temp,t);
        System.out.println("");
        i++;
    }

    System.out.println("");

    int b = 1;
    String v_src,v_dst;
    int v_w;
    while(b == 1){
        System.out.println("Would you like to add an edge 1 for yes/0 for no");
        b = sc.nextInt();
        
        if(b == 1){
        System.out.println("Give me the source and destination vertices as well as the edge weight: ");
        v_src = sc.next();
        v_dst = sc.next();
        v_w = sc.nextInt();

        addEdge(g,v_src,v_dst,v_w,t);

        }
    }

    System.out.println("");
    printGraph(g);
    System.out.println("");
    
    String src;
    Vertex<String,String> r[];
    while(true){
        System.out.println("Give me the source vertex for which you would like to find the shortest distances to other vertices: ");
        src = sc.next();
        r = DijkstraAlgo(g,src,t);
        System.out.println("");

        System.out.println("The distance from A "+" to: ");
        for(int x=0;x<r.length;x++)
        System.out.println("====================> "+r[x].label+", distance = "+r[x].edge_weight);
        
        System.out.println("");

    }
}

}