import os
import sys
from HNode import HNode
from HLinkedlist import HLinkedlist

class HashTable:

    def __init__(self,s):
        self.size = s
        self.slot = s*[None]

        for i in range(s):
            self.slot[i] = HLinkedlist()
            self.slot[i].head = None

    def hashCode(self,k):
        if isinstance(k,int):
            code = (k^(k >> 4))%self.size
        else:
            total = 0
            if isinstance(k,str):
                for i in range(len(k)):
                    total = total + ord(k[i])
                
                code = total%self.size
        
        return code
            

    def printHT(self):
        if self.size == 0:
            print("The table is empty \n")
        else:
            for i in range(self.size):
                aux = self.slot[i].head
                if aux == None:
                    print("Slot ",i," is empty")
                    print()
                else:
                    print("slot ",i,"\n")
                    while aux != None:
                        print("key ",aux.key, "===> value ", aux.value, " || ",end='')
                        aux = aux.next
                    
                    print("\n")


    def insertHT(self,k,v):
        code = self.hashCode(k)
        n = HNode(k,v)

        if self.slot[code].head == None:
            self.slot[code].head = n
        else:
            aux = self.slot[code].head
            while aux.next != None:
                aux = aux.next
            
            aux.next = n

    def searchHT(self,k):
        code = self.hashCode(k)
        res = None

        aux = self.slot[code].head
        b = False
        while aux != None and not(b):
            if k == aux.key:
                b = True
                res = aux
            else:
                aux = aux.next
        
        return res
    
    def deleteHT(self,k):
        code = self.hashCode(k)

        aux = self.slot[code].head
        prev = None
        b = False

        while aux != None and not(b):
            if aux.key == k:
                b = True
            else:
                prev = aux
                aux = aux.next

        if b:
            if prev == None:
                self.slot[code].head = self.slot[code].head.next
            else:
                prev.next = aux.next    
        else:
            print("The entry does not exist \n") 





"""Testing"""


print("Give me the size of your hashtable: \n")
N = int(input())
h = HashTable(N)

print()

for i in range(N):
    print("Give me you key ",i, " and your value ",i,"\n")
    a = int(input())
    b = input()
    h.insertHT(a,b)

print()

print("The entries of your table are: \n")
h.printHT()

print()
while True:
    print("Give me the entry you want to delete: \n")
    ks = int(input())
    h.deleteHT(ks)
    print()
    h.printHT()
    print()