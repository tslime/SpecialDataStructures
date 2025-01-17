import java.io.*;
import java.util.Scanner;


class BTree<T>{
    TNode<T> root;

    public BTree(){
        this.root = null;
    }

    
    public static <T>void printBST(TNode<T> t){

        if(t!=null){
            printBST(t.left);
            System.out.print(t.data+" ");
            printBST(t.right);
        }
    }

    public static <T extends Comparable<T>>TNode<T> insertBST(TNode<T> t,T d){

        if(t == null){
            TNode<T> n = new TNode<>(d);
            return n;
        }else{
            if(d.compareTo(t.data) <= 0)
            t.left = insertBST(t.left,d);
            else t.right = insertBST(t.right,d);
        }

        return t;
    }

    public static <T extends Comparable<T>>boolean searchBST(TNode<T> r,T d){

         if(r != null){
            if(r.data.compareTo(d) == 0)
            return true;
            else{
                 if((r.data).compareTo(d) < 0)
                 return searchBST(r.right,d);
                 else return searchBST(r.left,d);
            }
         }else return false;  
    }

    public static <T extends Comparable<T>>TNode<T> deleteBST(TNode<T> r,T d){
        
        if(r != null){
            if(d.compareTo(r.data) == 0){
                if(r.left == null)
                r = r.right;
                else if(r.right == null)
                    r = r.left;
                    else{
                       TNode<T> prev = null;
                       TNode<T> aux = r.right;

                       while(aux.left != null){
                        prev = aux;
                        aux = aux.left;
                       }
                       
                       r.data = aux.data;

                       if(prev == null)
                       r.right = aux.right;
                       else{

                        if(aux.right == null)
                        prev.left = null;
                        else prev.left = aux.right;
                       
                       }
                    }
            }else{
                if(d.compareTo(r.data) < 0)
                r.left = deleteBST(r.left,d);
                else r.right = deleteBST(r.right,d);
            }
        }
    
     return r;
    }

    /*
    public static <T extends Comparable<T>>TNode<T> successorBST(TNode<T> n){
            
            if(n.left == null)
             return n;
            else return successorBST(n.left);
    }*/


    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int N;
        BTree<Integer> r = new BTree<>();
    

       System.out.println("Give me the number of elements you want to insert");
       N = sc.nextInt();

       System.out.println("Give me your elements:");
       int e;
       for(int i = 0;i<N;i++){
        e = sc.nextInt();
        r.root = insertBST(r.root,e);
       }

       System.out.println("");
       
       printBST(r.root);

       System.out.println(" ");
       int n;
       TNode<Integer> res;

        /*
       res = successorBST(r.root.right);
       System.out.println("The successor is:\n");
       System.out.println(res.data);
        */

       
       while(true){
       System.out.println("Give me the number you want to delete");
       n = sc.nextInt();
       res = deleteBST(r.root,n);
       System.out.println(" ");

       if(res == null)
       System.out.println("The tree is empty");
       else{
        System.out.print("Your new tree is: ");
        printBST(res);
       }

       System.out.println(" "); 
       System.out.println(" "); 
        
    
    }

    }
  
}
