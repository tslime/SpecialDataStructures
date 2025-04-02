import java.io.*;

class THashtable{

    int size;
    int num_c;
    TNode slots[];

    public THashtable(int s){
        this.size = s;
        this.num_c = 0;
        this.slots = new TNode[s];
    }
}