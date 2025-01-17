import java.io.*;
import java.util.Scanner;

class Hashtable<T1,T2>{

    int size;
    HLinkedlist<T1,T2> slot[];
    
    @SuppressWarnings("unchecked")
    public Hashtable(int size){
        this.size = size;
        this.slot = (HLinkedlist<T1,T2>[])new HLinkedlist[size];

        for(int i = 0;i<size;i++){
            slot[i] = new HLinkedlist<>();
            slot[i].head = null;

        }
        

    }

    public static<T1> int hashCode(T1 k,int s){

        int code = 0;

        if(k instanceof Integer)
        code = ((Integer)k^((Integer)k >> 4))%s;
        else if(k instanceof String){
            int total = 0;
            for(int i=0;i < ((String)k).length();i++){
             total = total + (int)(((String)k).charAt(i));
            }
            code = total%s;
        }

        return code;
    }

    
    public static <T1,T2>void printHT(Hashtable<T1,T2> t){
        
        for(int i = 0; i<t.size;i++){
            HNode<T1, T2> aux = t.slot[i].head;

            if(aux == null)
            System.out.println("There are no elements in slot "+i);
            else{
                System.out.println("The elements of slot "+i+" are:");
                while(aux != null){
                System.out.print("Key: "+aux.key+ " ===> " +" value: "+aux.value+" || ");
                aux = aux.next;
                  }
                   System.out.println("");
            }System.out.println("");
        }

        System.out.println("");
        
    } 

    public static <T1,T2>void insertHT(Hashtable<T1,T2> t,T1 k, T2 v){
        int c = hashCode(k,t.size);
        HNode<T1,T2> n = new HNode<>(k,v); 

        if(t.slot[c].head == null )
        t.slot[c].head = n;
        else{
            HNode<T1,T2> aux = t.slot[c].head;
            while(aux.next != null )
            aux = aux.next;

            aux.next = n;
        }
    }

    public static<T1 extends Comparable<T1>,T2> HNode<T1,T2> searchHT(Hashtable<T1,T2> t, T1 k){

        int code = hashCode(k,t.size);
        HNode<T1,T2> res = null;
        HNode<T1,T2> aux = t.slot[code].head;

        boolean b = false; 
        while(aux != null && !b){
                if (k.compareTo(aux.key) == 0)
                {
                  res = aux;
                  b = true;  
                }else aux = aux.next;
        }
        
        return res;
    }

    public static<T1 extends Comparable<T1>,T2> void deleteHT(Hashtable<T1,T2> t,T1 k){

        int code = hashCode(k,t.size);

            HNode<T1,T2> aux = t.slot[code].head;
            HNode<T1,T2> prev = null;
            
            boolean b = false;
            while(aux != null && !b){
                if(k.compareTo(aux.key) == 0)
                b = true;
                else{
                    prev = aux;
                    aux = aux.next;
                }
            }

            if(b){
                if(prev == null)
                t.slot[code].head = t.slot[code].head.next;
                else prev.next = aux.next;
            }else System.out.println("The key does not exist");
        

    }

    public static void main(String args[]){
        
        Scanner sc = new Scanner(System.in);
        Hashtable<Integer,String> ht;
        int N;

        System.out.println("Give me the size of your hashtable");
        N = sc.nextInt();
        ht = new Hashtable<>(N);

        for(int i=0;i<N;i++){
            System.out.println("Give me your key "+i+ " and your value "+i+": ");
            int k = sc.nextInt();
            String v = sc.next();

            insertHT(ht,k,v);
        }

        System.out.println("");
        printHT(ht);

        System.out.println("");

        while(true){
            System.out.println("Give me the key you want to delete:");
            int ks = sc.nextInt();
            deleteHT(ht,ks);
            
            System.out.println("Your new table is:");
            System.out.println("");
            printHT(ht);

            System.out.println("");
        }
       
    }
}