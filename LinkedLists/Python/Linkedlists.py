import os
import sys
from Node import Node

class Linkedlist:
    
    def __init__(self):
        self.head = None   
    
    def printList(self):
        if self.head == None:
            print("The list is empty \n")
        else:
            aux = self.head
            while aux != None:
                print(aux.data,end=" ")
                aux = aux.next
            
            print("\n")
 
    
    def insertLast(self,n):
        aux = Node(n)
        if self.head == None:
            self.head = aux
        else:
            temp= self.head
            while temp.next != None:
                temp = temp.next
        
            temp.next = aux

    def insertFirst(self,n):
        aux = Node(n)
        if self.head == None:
            self.head = aux
        else:
            aux.next = self.head
            self.head = aux

    def deleteElem(self,n):
        if self.head == None:
            print("The element is not found because the list is empty \n")
        else:
            aux = self.head
            prev = None
            b = False

            while aux != None and not(b):
                if aux.data == n:
                    b = True
                else:
                    prev = aux
                    aux = aux.next
            
            
            if b:
                if prev == None:
                    self.head = self.head.next
                else:
                    prev.next = aux.next                
            else:
                print("The element is not found")


""" 4 2 0 1 5 0 19 11 1 9 [0,1,2,0,0,2,2,1]*/"""
def mergeSortList(ini: Node, fin: Node):
    if ini == fin:
        aux = Linkedlist()
        aux.head = ini
        return aux
    else:
        split = splitList(ini,fin)
        return mergeLists(mergeSortList(ini,split),mergeSortList(split.next,fin))



def splitList(ini: Node, fin: Node):
    auxf = ini
    auxb = ini

    while auxf != None:
        
        auxf = auxf.next
        if auxf != None:
            auxf = auxf.next
        
        if auxf !=None:
            auxb = auxb.next
    
    return auxb


def mergeLists(Lone: Linkedlist, Ltwo:Linkedlist):
    result = Linkedlist()
    result.head = None
    none = Lone.head
    ntwo = Ltwo.head
    aux = none

    if Lone.head == None:
        return Ltwo
    
    if Ltwo.head == None:
        return Lone

    while none != None and ntwo != None:
        if none.data <= ntwo.data:
            if result.head == None:
                result.head = none
                aux = result.head
            else:
                aux.next = none
                aux = aux.next
        
            none = none.next
                
        else:
            if result.head == None:
                result.head = ntwo
                aux = result.head
            else:
                aux.next = ntwo
                aux = aux.next
        
            ntwo = ntwo.next
                

    
    if none != None:
        aux.next = none
    
    if ntwo != None:
        aux.next = ntwo

    return result

   

""" Testing """

L1 = Linkedlist()


print("size of your first list: \n")
N1 = int(input())




print("Give me your values for list 1: \n")
for i in range(N1):
    e = int(input())
    L1.insertLast(e)




print()
print("Your first list is: \n")
L1.printList()
print()

res = mergeSortList(L1.head,None)
print()
res.printList()
print()


"""
L2 = Linkedlist()

print("size of your second list: \n")
N2 = int(input())

print("Give me your values for list 2: \n")
for j in range(N2):
    e = int(input())
    L2.insertLast(e) 

print()
print("Your second list is: \n")
L2.printList()
print()
print()


res = mergeLists(L1,L2)

print("Your merged list is: \n")
res.printList()
print() """


"""Is there a way to use the new declare class as a parameter in a function within the same class in python"""
