import java.io.*;


class TNode<T>{
    T data;
    TNode<T> left;
    TNode<T> right;

    public TNode(T d){
        this.data = d;
        this.left = null;
        this.right = null;
    }

}