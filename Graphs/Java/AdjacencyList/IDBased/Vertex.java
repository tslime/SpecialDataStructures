import java.io.*;

class Vertex<T1,T2>{
    
    int id;
    T1 label;
    T2 data;
    int edge_weight;
    Vertex<T1,T2> next;

    public Vertex(int id,T1 label,T2 data){
        this.id = id;
        this.label = label;
        this.data = data;
        this.edge_weight = 0;
        this.next = null;
    }
   
}