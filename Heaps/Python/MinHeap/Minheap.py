import os
import sys


class Minheap:

    def __init__(self,size):
        self.size = size
        self.num_entries = 0
        self.slots = size*[None]

        
    def printMinheap(self):
        if self.num_entries == 0:
            print("The heap is empty \n")
        else:
            for i in range(self.num_entries):
                print(self.slots[i],end=" ")
            
            print("")
    
    def heapify(self):
        if self.num_entries > 1:
            nleaf = self.num_entries//2 -1
            while nleaf >= 0:
                self.bubbleDown(nleaf,self.num_entries-1)
                nleaf-=1
    

    def insertMinheap(self,d: int):
        if(self.num_entries >= self.size):
            print("The heap is full")
        else:
            self.slots[self.num_entries] = d
            self.num_entries+=1
            self.bubbleUp(self.num_entries-1)
    
    def bubbleUp(self,pos: int):
        parent = 0
        b = True

        while b:
            parent  = (pos-1)//2
            if pos-1 < 0:
                b = False
            else:
                if self.slots[parent] > self.slots[pos]:
                    temp = self.slots[parent]
                    self.slots[parent] = self.slots[pos]
                    self.slots[pos] = temp
                    pos = parent
                else:
                    b = False

    def deleteMinheap(self):
        r = None
        if self.num_entries == 0:
            print("The heap is empty \n")
        else:
            r = self.slots[0]
            self.slots[0] = self.slots[self.num_entries-1]
            self.slots[self.num_entries-1] = sys.maxsize
            self.num_entries-=1
            self.bubbleDown(0,self.num_entries-1)


    
    def bubbleDown(self,nleaf:int,pos: int):
        l_c = 0
        r_c = 0
        parent = nleaf
        b = True

        while b:
            l_c = 2*parent + 1
            r_c = 2*parent + 2

            if l_c > pos and r_c > pos:
                b = False
            else:
                if r_c <= pos:
                    if self.slots[r_c] >= self.slots[l_c]:
                        if self.slots[parent] > self.slots[l_c]:
                            temp = self.slots[parent]
                            self.slots[parent] = self.slots[l_c]
                            self.slots[l_c] = temp
                            parent = l_c
                        else:
                            b = False
                    else:
                        if self.slots[parent] > self.slots[r_c]:
                            temp = self.slots[parent]
                            self.slots[parent] = self.slots[r_c]
                            self.slots[r_c] = temp
                            parent = r_c
                        else:
                            b = False
                 
                else:
                    if self.slots[parent] > self.slots[l_c]:
                        temp = self.slots[parent]
                        self.slots[parent] = self.slots[l_c]
                        self.slots[l_c] = temp
                        parent = l_c
                    else:
                        b = False




    
    def minheapSort(self):
        if(self.num_entries > 1):
            l = self.num_entries -1
            b = False

            while not(b):
                temp = self.slots[0]
                self.slots[0] = self.slots[l]
                self.slots[l] = temp
                l-=1
                if l > 0:
                    self.bubbleDown(0,l)
                else:
                    b = True




"""Testing"""

print("Give me the size of your heap \n")
N = int(input())
h = Minheap(N)
print()

print("Give me the number of entries you would like to insert \n")
e = int(input())
i = 0
print("Give me your entries \n")
while i < e:
    d = int(input())
    h.slots[i] = d
    h.num_entries+=1
    """*h.insertMinheap(d)"""
    i+=1
    print()

print("Your array is \n")
h.printMinheap()
print()

print("Your array after heapifying is \n")
h.heapify()
h.printMinheap()
print()

"""
print("Your heap before deletion once \n")
h.deleteMinheap()
h.printMinheap()

print()
print("Your heap before deleting twice \n")
h.deleteMinheap()
h.printMinheap()

print()
print("Your heap after sorting \n")
h.minheapSort()
h.printMinheap()
"""
print()
