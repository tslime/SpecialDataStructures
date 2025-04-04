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
                t.slots[i] = None
        
        t.num_c = r.tn.num_c
        r.tn = t





"""Testing"""



t = Trie()

print("Give me the initial size of your trie \n")
s = int(input())
t.root = t.initTrienode(t.root,s)
t.root.tn.slots[0].key = "k"
print()
print("The size ",t.root.tn.size,end="\n")
print("The numc ",t.root.tn.num_c,end="\n")
print("A character: ",t.root.tn.slots[0].key,end="\n")
print()
t.resizeTrienode(t.root,6)
print("new size ",t.root.tn.size,end="\n")
print("check ",t.root.tn.slots[0].key)