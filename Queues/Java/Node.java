import java.io.*;

class Node<T>{

    T data;
    Node<T> next;

    public Node(T d){
        this.data = d;
        this.next = null;
    }

}