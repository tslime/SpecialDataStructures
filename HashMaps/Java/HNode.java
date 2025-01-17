import java.io.*;

class HNode<T1,T2>{

    T1 key; 
    T2 value;
    HNode<T1,T2> next; 

    public HNode(T1 k,T2 v){
        this.key = k;
        this.value = v;
        this.next = null;
    }

}