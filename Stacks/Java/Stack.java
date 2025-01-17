import java.io.*;
import java.util.Scanner;

class Stack<T>{
    
    Node<T> Top;

    public Stack(){
        this.Top = null;
    }

    public static <T>void printStack(Stack<T> s){
        if(s.Top == null)
        System.out.println("The stack is empty");
        else{
            Node<T> aux = s.Top;
            while(aux != null){
                System.out.print(aux.data+" ");
                aux = aux.next;
            }
        }
        System.out.println("\n");
    }

    public static <T>void pushS(Stack<T> s,T d){

            Node<T> n = new Node<>(d);
            if(s.Top == null)
            s.Top = n;
            else{
                n.next = s.Top;
                s.Top = n;
            }
            
    }

    public static <T>void popS(Stack<T> s){
        if(s.Top == null)
        System.out.println("The stack is empty");
        else s.Top = s.Top.next;
    }

    public static <T>Node<T> peekS(Stack<T> s){
        if(s.Top != null)
        return s.Top;
        else return null;
    }

    public static <T>boolean isEmpty(Stack<T> s){
        if(s.Top == null)
        return true;
        else return false;
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        Stack<Integer> s = new Stack<>();
        int N;

        System.out.println("How many elemnet would you like to stack:");
        N = sc.nextInt();
        
        System.out.println("Give me your elements");
        int i = 0;
        while(i<N){
            int e = sc.nextInt();
            pushS(s,e);
            i++;
        }   

        System.out.println("");
        printStack(s);

        System.out.println("");
        
        Node<Integer> r = peekS(s);

        if(r != null)
        System.out.println("The top is: "+r.data);
        else System.out.println("There is no top");

        popS(s);
        popS(s);
        popS(s);

        if(isEmpty(s))
        System.out.println("It is empty \n");
        else    System.out.println("It is full \n");

        r = peekS(s);
        if(r != null)
        System.out.println("The top is: "+r.data);
        else System.out.println("There is no top");


        System.out.println("\n");
        printStack(s);
    }
}