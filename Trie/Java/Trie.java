import java.io.*;
import java.util.Scanner;

class Trie{

    Trienode root;

    public Trie(){
        this.root = new Trienode();
    }

    public static Trienode initTrienode(Trienode r,int s){

        //System.out.println("test");
        r = new Trienode();
        r.tn = new THashtable(s);

        for(int i=0;i<s;i++)
        r.tn.slots[i] = new TNode(null);

        return r;
        
    }

    public static void resizeTrienode(Trienode r,int new_size){
        THashtable t = new THashtable(new_size);

        for(int i=0;i<new_size;i++){
            if(i < r.tn.size)
            t.slots[i] = r.tn.slots[i];
            else t.slots[i] = new TNode(null);
        }

        t.num_c = r.tn.num_c;
        r.tn = t;
    }

    public static void insertString(Trienode r,String w){

        TNode aux = null;

        for(int i=0;i<w.length();i++){
            int index = w.charAt(i) -'a';

            if(i == 0){
                if(index >= r.tn.size)
                resizeTrienode(r,index+1);

                if(r.tn.slots[index].key == null)
                r.tn.slots[index].key = w.charAt(i) + "";

                aux = r.tn.slots[index];
            }else{
                if(aux.child == null){
                    aux.child = initTrienode(aux.child,index+1);
                    aux.child.tn.slots[index].key = w.charAt(i)+"";

                    aux = aux.child.tn.slots[index];
                }else{
                    if(index >= aux.child.tn.size)
                    resizeTrienode(aux.child,index+1);

                    aux.child.tn.slots[index].key = w.charAt(i)+"";
                    aux = aux.child.tn.slots[index];    
                }

            }
        }
    }

    public static void printTrie(Trienode r,String k,int ct){

        if( r!= null){
            for(int i=0;i<r.tn.size;i++){

                if(r.tn.slots[i].key != null){
                    k = k + r.tn.slots[i].key;
                    System.out.print(k+" | ");
                    ct++;
                    printTrie(r.tn.slots[i].child,k,ct);
                    k = k.substring(0,k.length() - 1);
                    ct--;

                    if(ct == 0)
                    System.out.println("");


                }
                
            }
        }
    }

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        int init_size;
        Trie t = new Trie();

        System.out.println("Give me the initial size of your trie ");
        init_size = sc.nextInt();

        t.root = initTrienode(t.root,init_size);

        while(true){
            System.out.println("Give me a word ");
            String w = sc.next();
            insertString(t.root,w);
            System.out.println("");
            printTrie(t.root,"",0);
            System.out.println("");
        }
        

        

    }
}