import os
import sys


from TNode import TNode
from THashtable import THashtable
from Trienode import Trienode

class Trie:

    def __init__(self):
        self.root = None

    def initTrienode(self,r:Trienode,init_size:int):
        r = Trienode()
        r.tn = THashtable(init_size)

        for i in range(init_size):
            r.tn.slots[i] = TNode(None)
        
        return r

    def resizeTrienode(self,r:Trienode,new_size:int):
        t = THashtable(new_size)
        t.size = new_size

        for i in range(new_size):
            if i < r.tn.size:
                t.slots[i] = r.tn.slots[i]
            else:
                t.slots[i] = TNode(None)
        
        t.num_c = r.tn.num_c
        r.tn = t
    
    def insertString(self,r:Trienode,w):
        aux = TNode(None)
        
        for i in range(len(w)):
            index = ord(w[i]) - ord('a')
        
            if i == 0:
                if r == None:
                    r = self.initTrienode(r,index+1)
                
                if index >= r.tn.size:
                    self.resizeTrienode(r,index+1)
                
                if r.tn.slots[index].key == None:
                    r.tn.slots[index].key = w[i]
                    r.tn.num_c = r.tn.num_c + 1
                   
                aux = r.tn.slots[index]   
            else:
                if aux.child == None:
                    aux.child = self.initTrienode(aux.child,index+1)
                
                if index >= aux.child.tn.size:
                    resizeTrienode(aux.child,index+1)

                if aux.child.tn.slots[index].key == None:
                    aux.child.tn.slots[index].key = w[i]
                    aux.child.tn.num_c = aux.child.tn.num_c + 1

                aux = aux.child.tn.slots[index]

        return r


    def printTrienode(self,r:Trienode,k,ct):
    
        if r != None:
            i = 0
            j = 0
            b = False
           
            while i < r.tn.size and not(b):
                if j >= r.tn.num_c:
                    b = True
                else:
                    if r.tn.slots[i].key != None:
                        j = j + 1
                        k = k + r.tn.slots[i].key
                        print(k,end=" | ")
                        ct = ct + 1
                        aux = r.tn.slots[i]
                        self.printTrienode(aux.child,k,ct)
                        k = k[:-1]
                        ct = ct - 1
                        
                        if ct == 0:
                            print("\n \n")
                
                i = i + 1
                        




"""Testing"""



t = Trie()


while True:
    print("Give me a word \n")
    wr = input()
    t.root = t.insertString(t.root,wr)
    t.printTrienode(t.root,"",0)