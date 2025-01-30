import java.io.*;
import java.util.Scanner;

class Minheap{

        
        int size;
        int num_entries;
        int slots[];

        public Minheap(int size){
          this.size =size;
          this.num_entries = 0;
          slots = new int[size];
        }

        public static void printMinheap(Minheap mh){
            if(mh.num_entries == 0)
            System.out.println("The heap is empty");
            else{
                for(int i=0;i<mh.num_entries;i++)
                System.out.print(mh.slots[i]+" ");

                System.out.println("");
            }
        }

        public static void insertMinheap(Minheap mh,int d){
            if(mh.num_entries >= mh.size)
            System.out.println("The heap is full");
            else{
                mh.slots[mh.num_entries] = d;
                mh.num_entries++;
                bubbleUp(mh,mh.num_entries-1);
            }
        }

        public static void bubbleUp(Minheap mh,int pos){

        }

        public static void deleteMinheap(Minheap mh){
            int r;

            if(mh.num_entries == 0)
            System.out.println("The heap is empty");
            else{
                r = mh.slots[0];
                mh.slots[0] = mh.slots[mh.num_entries-1];
                mh.slots[mh.num_entries-1] = Integer.MAX_VALUE;
                mh.num_entries--;
                bubbleDown(mh);
            }
        }

        public static void bubbleDown(Minheap mh){

        }

        public static void minheapSort(Minheap mh){

        }

        public static void main(String args[]){

            Scanner sc = new Scanner(System.in);

            System.out.println("test");
        }
}