import java.io.*;
import java.util.Scanner;

class Trie{

    Trienode root;

    public Trie(){
        this.root = null;
    }

    public static Trienode initTrienode(Trienode r,int s){

        //System.out.println("test");
        r = new Trienode();
        r.tn = new THashtable(s);

        for(int i=0;i<s;i++){
            //System.out.println("test");
            r.tn.slots[i] = new TNode(null);
        }
        

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

    public static Trienode insertString(Trienode r,String w){

        TNode aux = null;

        for(int i=0;i<w.length();i++){
            int index = w.charAt(i) -'a';

            if(i == 0){

                if(r == null)
                r = initTrienode(r,index+1);

                if(index >= r.tn.size)
                resizeTrienode(r,index+1);

                if(r.tn.slots[index].key == null){
                r.tn.slots[index].key = w.charAt(i) + "";
                r.tn.num_c++;
                }

                aux = r.tn.slots[index];
            }else{
                if(aux.child == null)
                    aux.child = initTrienode(aux.child,index+1);
                    
               
                if(index >= aux.child.tn.size)
                resizeTrienode(aux.child,index+1);
                
                if(aux.child.tn.slots[index].key == null){
                    aux.child.tn.slots[index].key = w.charAt(i)+"";
                    aux.child.tn.num_c++;
                }
                   
                aux = aux.child.tn.slots[index];    
             }

            }

        return r;
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

        Trie t = new Trie();

        while(true){
            System.out.println("Give me a word ");
            String w = sc.next();
            t.root = insertString(t.root,w);
            System.out.println(t.root.tn.size);
            printTrie(t.root,"",0);
            System.out.println("");
        }
        

        

    }
}