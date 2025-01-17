import os
import sys
from Node import Node

class Queue:
    def __init__(self):
        self.first = None

    def printQ(self):
        if self.first == None:
            print("The queue is empty \n")
        else:
            aux = self.first
            while(aux != None):
                print(aux.data,end=" ")
                aux = aux.next

            print()

    def enQueue(self,d):
        e = Node(d)
        if(self.first == None):
            self.first = e
        else:
            aux = self.first
            while(aux.next != None):
                aux = aux.next

            aux.next = e

    def deQueue(self):
        if(self.first == None):
            print("Cant dequeue an empty queue")
        else:
            self.first = self.first.next
    
    def isEmpty(self):
        if self.first == None:
            return True
        else:
            return False

    def peekQ(self):
        if(self.first != None):
            return self.first
        else:
            return None

""" Testing """

Q = Queue()

print("Give me the size of your queue: \n")
N = int(input())

print("Give me our elements \n")
for i in range(N):
    e = int(input())
    Q.enQueue(e)

Q.deQueue()
Q.deQueue()
Q.deQueue()
Q.deQueue()

print()

Q.printQ()

n = Q.peekQ()
if(n!= None):
    print("Your first element is: \n", n.data)
else:
    print("Your queue is empty \n")

if(Q.isEmpty()):
    print("Your queue is empty \n")
else:
    print("Your queue is not empty \n")
