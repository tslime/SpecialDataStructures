import java.io.*;

class Vertex<T1,T3>{

    T1 label;
    Integer ID;
    T3 data;
    int edge_weight;
    Vertex<T1,T3> next;

    public Vertex(T1 label, Integer ID, T3 data){
        this.label = label;
        this.ID = ID;
        this.data = data;
        this.edge_weight = 0;
        this.next = null;
    }
}