import java.io.*;
import java.util.Scanner;

class Linkedlist<T>{

    Node<T> head;

    public Linkedlist(){
       this.head = null;
        
    }

    public static <T>void printList(Linkedlist<T> L){
        
        if(L.head == null)
        System.out.println("The list is empty");
        else{  
            Node<T> aux = L.head;

            while(aux != null){
                System.out.print(aux.data+" ");
                aux = aux.next;
            }
            System.out.println("");
        }
    } 


    public static <T>void insertLast(Linkedlist<T> L, T n){

        Node<T> aux = new Node<>(n);

        if(L.head == null)
        L.head = aux;
        else{
            Node<T> temp = L.head;
            
            while(temp.next != null )
            temp = temp.next;

            temp.next = aux;
        }

    }

    public static <T>void insertFirst(Linkedlist<T> L, T n){
        
        Node<T> aux = new Node<>(n);

        if(L.head == null)
        L.head = aux;
        else{
            aux.next = L.head;
            L.head = aux;
        }
    }

    public static <T>void deleteElement(Linkedlist<T> L, T n){
        
            Node<T> temp = L.head;
            Node<T> prev = null;
            boolean b = false;

            while(temp != null && !b){
                if(temp.data == n)
                b = true;
            else { 
                    prev = temp;
                    temp = temp.next;
                }
            }

            if(L.head == null)
            System.out.println("The element is not found because your list is empty");
            else{
                 if(b){
                       if(prev == null)
                        L.head = L.head.next;
                        else prev.next = temp.next;
            }else System.out.println("The element is not found");   
        }
    
    }
   
   
    public static <T extends Comparable<T>>boolean searchElement(Linkedlist<T> L, T n){

        boolean b = false;
        Node<T> aux = L.head;

        while(aux != null && !b){
            if(aux.data.compareTo(n) == 0)
            b = true;
            else aux = aux.next;
        }

    return b;
        
    }

    /*
    

    public static Linkedlist insertSort(Linkedlist L){
        Linkedlist temp = null;

        return temp;
    } 

   */


   
   public static <T extends Comparable<T>>Linkedlist<T> merge(Linkedlist<T> Lone, Linkedlist<T> Ltwo){
        
        if(Lone.head == null)
        return Ltwo;

        if(Ltwo.head == null)
        return Lone;

        Linkedlist<T> result = new Linkedlist<>();
        Node<T> none = Lone.head;
        Node<T> ntwo = Ltwo.head;
        Node<T> aux = null;
        boolean b = false;

        while(none != null && ntwo != null){

            if((none.data).compareTo(ntwo.data)<=0){
                if(result.head == null){
                    result.head = none;
                    aux = result.head;
                }else{
                    aux.next = none;
                    aux = aux.next;
                }

                none = none.next;

            }else{
                    if(result.head == null){
                        result.head = ntwo;
                        aux = result.head;
                    }else{
                        aux.next = ntwo;
                        aux = aux.next;
                    }

                    ntwo = ntwo.next;
            }
           
        }
       
        if(none != null)
        aux.next = none;

        if(ntwo != null)
        aux.next = ntwo;
        
        return result;
    }



   public static <T extends Comparable<T>> Node<T> splitList(Node<T> ini, Node<T> fin){

    Node<T> auxf = ini;
    Node<T> auxb = ini;

    while(auxf != fin){
        
        auxf = auxf.next;
        if(auxf != fin)
        auxf = auxf.next;

        if(auxf != fin)
        auxb = auxb.next;
    }
    
    return auxb;

   }

   public static<T> Linkedlist<T> reverseList(Linkedlist<T> l){

    if(l.head == null || l.head.next == null)
    return l;
    else{
        Node<T> prev = null;
        Node<T> aux = l.head;
        Node<T> succ = l.head.next;

        while(succ != null){

            if(prev == null){
                prev = aux;
                aux = succ;
                succ = succ.next;

                prev.next = null;
                aux.next = prev;
            }else{
                prev = aux;
                aux = succ;
                succ = succ.next;

                aux.next = prev;
            }
        }

        l.head = aux;
    }

    return l;
   }


public static<T extends Comparable<T>> Linkedlist<T> mergeSortList(Node<T> ini, Node<T> fin){  

    if(ini == fin){
        Linkedlist<T> aux = new Linkedlist<>();
        aux.head = ini;
        return aux;
    }else{
        Node<T> split = splitList(ini,fin);
        Node<T> mid = split.next;
        split.next = null;
        return merge(mergeSortList(ini,split),mergeSortList(mid,fin));
    }

   }

    public static void main(String args[]){


        Scanner sc = new Scanner(System.in);

        int N1;
        //int N2;

        Linkedlist<Integer> mylist1 = new Linkedlist<>();
        //Linkedlist<Integer> mylist2 = new Linkedlist<>();

        System.out.println("Give me the size of your first list:");
        N1 = sc.nextInt();

      

        System.out.println("Give me the elements for your first list: \n");
        int i = 0;
        int e = 0;
        while(i < N1){
            e = sc.nextInt();
            insertLast(mylist1,e);
            i++;
        }

        System.out.println("Your list is:");
        printList(mylist1);
        System.out.println("");

        /*
        System.out.println("Give me the size of your second list:");
        N2 = sc.nextInt();

        System.out.println("Give me the elemenets for your second list: \n");
        i = 0;
        e = 0;
        while(i < N2){
            e = sc.nextInt();
            insertLast(mylist2,e);
            i++;
        }*/

        
        Node<Integer> t = splitList(mylist1.head,null);
        System.out.println("mid "+t.data);
        
     
       // System.out.println("Your reversed list is:");
        //Linkedlist<Integer> result = reverseList(mylist1);

        //Linkedlist<Integer> result = mergeSortList(mylist1.head,null); /* 4 2 0 1 5 0 19 11 1 9 [0,1,2,0,0,2,2,1]*/

        //printList(result);
        System.out.println("");
        

    }
}