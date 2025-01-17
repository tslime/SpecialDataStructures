import os
import sys
from Node import Node

class Stack:

    def __init__(self):
        self.Top = None

    def printStack(self):
        if self.Top == None:
            print("The stack is empty \n")
        else:
            aux = self.Top
            while aux != None:
                print(aux.data,end=" ")
                aux = aux.next
            
            print()
    
    def pushS(self,d):
        e = Node(d)
        
        if  self.Top == None:
            self.Top = e
        else:
            e.next = self.Top
            self.Top = e
    
    def popS(self):
        if(self.Top != None):
            self.Top = self.Top.next

    def isEmpty(self):
        if(self.Top == None):
            return True
        else:
            return False
    
    def peekS(self):
        if self.Top !=None:
            print("The top element in the stack is \n", self.Top.data)



"""Testing"""
S = Stack()

print("Give me the number of elements you want to push in the stack: \n")
N = int(input())

print("Give me your elements \n")
for i in range(N):
    e = int(input())
    S.pushS(e)


print()
print("The elements in the stack are: \n")
S.printStack()

print()

S.popS()

if S.isEmpty():
    print("The stack is empty \n")
else:
    print("the stack is not empty \n")

print("Your stack after popping \n")
S.printStack()

S.peekS()

S.popS()
S.popS()


if S.isEmpty():
    print("The stack is empty \n")
else:
    print("the stack is not empty \n")

print("Your stack after popping again\n")
S.printStack()