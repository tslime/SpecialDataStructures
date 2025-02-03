import java.io.*;
import java.util.Scanner;


class Maxheap{

    int size;
    int num_entries;
    int slots[];

    public Maxheap(int size){
        this.size = size;
        this.num_entries = 0;
        this.slots = new int[size];
    }

    public static void printMaxheap(Maxheap mh){
        if(mh.num_entries == 0)
        System.out.println("The heap is empty");
        else{
            for(int i=0;i<mh.num_entries;i++)
            System.out.print(mh.slots[i]+" ");

            System.out.println("");
        }
    } 

    public static void insertMaxheap(Maxheap mh,int d){
        if(mh.num_entries >= mh.size)
        System.out.println("The heap is full");
        else{
            mh.slots[mh.num_entries] = d;
            mh.num_entries++;
            bubbleUp(mh,mh.num_entries-1);
        }
    }

    public static void bubbleUp(Maxheap mh,int pos){
        int parent = 0;
        boolean b = true;

        while(b){
            parent = (pos-1)/2;
            if(pos-1 <0)
            b = false;
            else{
                if(mh.slots[parent] < mh.slots[pos]){
                    int temp = mh.slots[parent];
                    mh.slots[parent] = mh.slots[pos];
                    mh.slots[pos] = temp;
                    pos = parent; 
                }else b = false;
            }
        }
    }

    public static void deleteMaxheap(Maxheap mh){
        int r;

        if(mh.num_entries == 0)
        System.out.println("The heap is empty");
        else{
            r = mh.slots[0];
            mh.slots[0] = mh.slots[mh.num_entries-1];
            mh.slots[mh.num_entries-1] = Integer.MAX_VALUE;
            mh.num_entries--;
            bubbleDown(mh,mh.num_entries-1);
        }
    }

    public static void bubbleDown(Maxheap mh,int pos){
        int l_c = 0;
        int r_c = 0;
        int parent = 0;
        boolean b = true;

        while(b){
            l_c = 2*parent + 1;
            r_c = 2*parent + 2;

            if(l_c > pos && r_c > pos)
            b = false;
            else{
                if(r_c <= pos){
                    
                    if(mh.slots[r_c] >= mh.slots[l_c] ){
                        if(mh.slots[parent] < mh.slots[r_c]){
                            int temp = mh.slots[parent];
                            mh.slots[parent] = mh.slots[r_c];
                            mh.slots[r_c] = temp;
                            parent = r_c;
                        }else b = false;

                    }else{
                        if(mh.slots[parent] < mh.slots[l_c]){
                            int temp = mh.slots[parent];
                            mh.slots[parent] = mh.slots[l_c];
                            mh.slots[l_c] = temp;
                            parent = l_c;
                        }else b = false;
                    }

                }else{

                    if(mh.slots[parent] < mh.slots[l_c]){
                    int temp = mh.slots[parent];
                    mh.slots[parent] = mh.slots[l_c];
                    mh.slots[l_c] = temp;
                    parent = l_c;
                    }else b = false;
                }
            }
        }

    }

    public static void maxheapSort(Maxheap mh){
        if(mh.num_entries > 1){
            int l = mh.num_entries - 1;
            boolean b = false;

            while(!b){
                int temp = mh.slots[0];
                mh.slots[0] = mh.slots[l];
                mh.slots[l] = temp;
                l--;

                if(l > 0)
                bubbleDown(mh,l);
                else b = true;
            }
        }
    }


    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        int N;

        System.out.println("Give me the size of your heap");
        N = sc.nextInt();
        Maxheap h = new Maxheap(N);

        int entries;
        System.out.println("Give me the number of entries you would like to insert");
        entries = sc.nextInt();

        System.out.println("Give me your entries");
        int i =0;
        while(i < entries){
            int e = sc.nextInt();
            insertMaxheap(h,e);
            System.out.println("");
            i++;
        }

        System.out.println("Your max heap is ");
        printMaxheap(h);
        System.out.println("");

        System.out.println("Your heap after deleting once ");
        deleteMaxheap(h);
        printMaxheap(h);
        System.out.println("");

        System.out.println("Your heap after deleting twice ");
        deleteMaxheap(h);
        printMaxheap(h);
        System.out.println("");

        System.out.println("Your heap after sorting");
        maxheapSort(h);
        printMaxheap(h);
        System.out.println("");
    }   
}