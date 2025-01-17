import java.io.*;

class Node<T>{

    T data;
    Node<T> next;

    public Node(T n){
        this.data = n;
        this.next = null;
    }
}