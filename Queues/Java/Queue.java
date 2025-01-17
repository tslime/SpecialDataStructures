import java.io.*;
import java.util.Scanner;

class Queue<T>{
    
    Node<T> first;

    public Queue(){
        this.first = null;
    }

    // why q == null not working
    public static <T>void printQ(Queue<T> q){
        if(q.first == null)
        System.out.println("The queue is empty");
        else{
            Node<T> aux = q.first;
            while(aux != null){
                System.out.print(aux.data+" ");
                aux = aux.next;
            }

            System.out.println(" ");
        }

    }

    public static <T>void enQueue(Queue<T> q, T d){
        Node<T> temp = new Node<>(d);
        
        if(q.first == null)
        q.first = temp;
        else{
            Node<T> aux = q.first;
            while(aux.next != null)
            aux = aux.next;

            aux.next = temp;
        }
    } 

    public static <T>void deQueue(Queue<T> q){
        if(q.first == null)
        System.out.println("cant dequeue the queue is empty");
        else q.first = q.first.next;
    }

    public static <T>boolean isEmpty(Queue<T> q){
        if(q.first == null)
        return true;
        else return false;
    }

    public static <T>Node<T> peekQ(Queue<T> q){
        
        if(q.first != null)
        return q.first;
        else return null;
        
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        Queue<Integer> Q = new Queue<>();
        int N; 
        int e;

        System.out.println("Give me the size of your queue");
        N = sc.nextInt();
    
        System.out.println("Give me your elements:");
        for(int i = 0;i<N;i++){
            e = sc.nextInt();
            enQueue(Q,e);
        }

        System.out.println("");
        printQ(Q);

        deQueue(Q);
        
        System.out.println("");
        printQ(Q);

        Node<Integer> n = peekQ(Q);
        if(n!=null)
        System.out.println("The first element is: "+ n.data);
        
        deQueue(Q);
        deQueue(Q);
        deQueue(Q);

        if(isEmpty(Q))
        System.out.println("The queue is empty I just checked");

        System.out.println("");
        printQ(Q);
    }   

}