import java.io.*;
import java.util.Scanner;

class PQueue<T1,T2>{

    int size;
    int num_vd;
    Vertex<T1,T2> vd[];

    @SuppressWarnings("unchecked")
    public PQueue(int size){
        this.size = size;
        this.vd = (Vertex<T1,T2>[])new Vertex[size]; 
        this.num_vd = 0;

        for(int i=0;i<size;i++){
            vd[i] = new Vertex<>(-1,null,null);
            vd[i] = null;
        }

    }

    public static<T1,T2> void printQ(PQueue<T1,T2> q){
        
        System.out.println("Your stored edge weights are: ");

        for(int i=0;i<q.vd.length && q.vd[i] != null;i++)
        System.out.print(q.vd[i].edge_weight+" ");

        System.out.println("\n");
    }

    @SuppressWarnings("unchecked")
    public static<T1,T2> void dsizePQueue(PQueue<T1,T2> q){

        PQueue<T1,T2> temp = new PQueue<>(2*q.size);
        temp.num_vd = q.num_vd;

        for(int i=0;i<q.vd.length && q.vd[i]!=null;i++)
        temp.vd[i] = q.vd[i];
        
    
        q.vd = temp.vd;
        q.size = temp.size;
       
    }


    public static<T1,T2> Vertex<T1,T2> peek(PQueue<T1,T2> q){

        if(q.vd[0] == null){
             System.out.println("Your queue is empty");
             return null;
        }else return q.vd[0];
    } 


    public static<T1,T2> void insert(PQueue<T1,T2> q,Vertex<T1,T2> v){
        
        if(q.num_vd >= q.vd.length){
            dsizePQueue(q);
            q.vd[q.num_vd] = v;
            q.num_vd++;
        }
        else{
            q.vd[q.num_vd] = v;
            q.num_vd++;
        }

        bubbleUP(q,q.num_vd-1);
    }

    public static<T1,T2> void bubbleUP(PQueue<T1,T2> q,int last_element_index){

        if(last_element_index > 0){

            boolean b = false;
            int k = last_element_index;
            int parent_index = (k-1)/2;

            while(parent_index >= 0 && !b)
            {
            if(q.vd[parent_index].edge_weight > q.vd[k].edge_weight ){
                Vertex<T1,T2> temp = q.vd[k];
                q.vd[k] = q.vd[parent_index];
                q.vd[parent_index] = temp;
                k = parent_index;

                if(k-1 < 0)
                b = true;
                else parent_index = (k-1)/2;
            }else b = true;
          }
        }
    }

    public static<T1,T2> Vertex<T1,T2> pop(PQueue<T1,T2> q){
        
        Vertex<T1,T2> res = q.vd[0];
        
        if(q.num_vd > 0){
        if(q.vd[1] == null){
            q.vd[0] = null;
            q.num_vd--;
        }else {
              q.vd[0] = q.vd[q.num_vd-1];
              q.vd[q.num_vd-1] = null;
              q.num_vd--;
              bubbleDown(q);
        }
      }
        return res;
    }

    public static<T1,T2> void bubbleDown(PQueue<T1,T2> q){
        
        
        boolean b = false;
        int k = 0;

        while(!b){

                if(2*k+1 >= q.num_vd  && 2*k+2 >= q.num_vd)
                b = true;
                else{
                    if(2*k+2 < q.num_vd){
                        
                        if(q.vd[2*k+1].edge_weight <= q.vd[2*k+2].edge_weight){
                            
                            if(q.vd[k].edge_weight > q.vd[2*k+1].edge_weight){
                                Vertex<T1,T2> temp = q.vd[k];
                                q.vd[k] = q.vd[2*k+1];
                                q.vd[2*k+1] = temp;
                                k = 2*k+1;
                            }else b = true;
                        }else{
                            
                            if(q.vd[k].edge_weight > q.vd[2*k+2].edge_weight){
                                Vertex<T1,T2> temp = q.vd[k];
                                q.vd[k] = q.vd[2*k+2];
                                q.vd[2*k+2] = temp;
                                k = 2*k+2;
                            }else b = true;
                        }

                    }else{
                     
                            if(q.vd[k].edge_weight > q.vd[2*k+1].edge_weight){
                                Vertex<T1,T2> temp = q.vd[k];
                                q.vd[k] = q.vd[2*k+1];
                                q.vd[2*k+1] = temp;
                                k = 2*k+1;
                            }else b = true;
                    }
                }
        }
 
    }


public static void main(String args[]){

    Scanner sc = new Scanner(System.in);
    int s;
    int n;

    System.out.println("Give me the size of your queue");
    s = sc.nextInt();

    PQueue<String,String> qs = new PQueue<>(s);

    System.out.println("Enter the number of vertices would you like to insert");
    n = sc.nextInt();

    System.out.println("");

    int id = 0;
    while(n>0){
        System.out.println("Give me the label, the data, and the edge weight of your vertex "+id);

        if(sc.hasNextLine())
        sc.nextLine();

        String ltmp = sc.nextLine();
        String dtmp = sc.nextLine();
        int ew_tmp = sc.nextInt();
    

        Vertex<String,String> vtmp = new Vertex<>(id,ltmp,dtmp);
        vtmp.edge_weight = ew_tmp;

        insert(qs,vtmp);
        id++;
        n--;
    }

    System.out.println("\n");

    printQ(qs);

    System.out.println("After popping: \n");

    
    pop(qs);
    pop(qs);

    printQ(qs);

    System.out.println("\n");
    System.out.println("The number of vertices in you queue now is: \n"+qs.num_vd);
 
    
    }
  
}