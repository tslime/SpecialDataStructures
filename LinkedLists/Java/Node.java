import java.io.*;
import java.util.Scanner;

class Node<T>{

    T data;
    Node<T> next;

    public Node(T n){
        this.data = n;
        this.next = null;
    }
}