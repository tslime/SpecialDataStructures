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


    }

    public static void maxheapSort(Maxheap mh){
        
    }


    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        System.out.println("test");
    }   
}