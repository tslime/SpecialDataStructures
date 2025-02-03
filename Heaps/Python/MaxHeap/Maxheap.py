import sys
import os


class Maxheap:

    def __init__(self,size):
        self.size = size
        self.num_entries = 0
        self.slots = size*[None]

    def printMaxheap(self):
        if self.num_entries == 0:
            print("The heap is empty \n")
        else:
            for i in range(self.num_entries):
                print(self.slots[i],end=" ")
            
            print()
    
    def insertMaxheap(self,d: int):
        if self.num_entries >= self.size:
            print("The heap is full \n")
        else:
            self.slots[self.num_entries] = d
            self.num_entries+=1
            self.bubbleUp(self.num_entries-1)
    
    def bubbleUp(self,pos: int):
        parent = 0
        b = True
        while b:
            parent = (pos-1)//2
            if pos-1 < 0:
                b = False
            else:
                if self.slots[parent] < self.slots[pos]:
                    temp = self.slots[parent]
                    self.slots[parent] = self.slots[pos]
                    self.slots[pos] = temp
                    pos = parent
                else:
                    b = False

    
    def deleteMaxheap(self):
        if self.num_entries == 0:
            print("The heap is empty")
        else:
            r = self.slots[0]
            self.slots[0] = self.slots[self.num_entries-1]
            self.slots[self.num_entries-1] = sys.maxsize
            self.num_entries-=1
            self.bubbleDown(self.num_entries-1)
    
    def bubbleDown(self,pos: int):
        l_c = 0
        r_c = 0
        parent = 0
        b = True

        while b:
            l_c = 2*parent + 1
            r_c = 2*parent + 2
            if l_c > pos and r_c > pos:
                b = False
            else:
                if r_c <= pos:
                    if(self.slots[l_c] <= self.slots[r_c]):
                        if(self.slots[parent] < self.slots[r_c]):
                            temp = self.slots[parent] 
                            self.slots[parent] = self.slots[r_c]
                            self.slots[r_c] = temp
                            parent = r_c
                        else:
                            b = False
                    else:
                        if(self.slots[parent] < self.slots[l_c]):
                            temp = self.slots[parent] 
                            self.slots[parent] = self.slots[l_c]
                            self.slots[l_c] = temp
                            parent = l_c
                        else:
                            b = False
                else:
                    if self.slots[parent] <= self.slots[l_c]:
                        temp = self.slots[parent] 
                        self.slots[parent] = self.slots[l_c]
                        self.slots[l_c] = temp
                        parent = l_c
                    else:
                        b = False




    def maxheapSort(self):
        if self.num_entries > 1:
            l = self.num_entries-1
            b = False

            while not(b):
                temp = self.slots[0]
                self.slots[0] = self.slots[l]
                self.slots[l] = temp
                l-=1

                if l > 0:
                    self.bubbleDown(l)
                else:
                    b = True


"""Testing"""


print("Give me the size of your heap \n")
N = int(input())
h = Maxheap(N)
print("Give me the number of entries you would like to insert \n")
entries = int(input())
print("Give me your entries \n")
i = 0
while i < entries:
    e = int(input())
    h.insertMaxheap(e)
    i+=1
    print()

print("Your max heap is: \n")
h.printMaxheap()
print()

print("Your heap after deleting once is \n")
h.deleteMaxheap()
h.printMaxheap()
print()

print("Your heap after deleting twice is \n")
h.deleteMaxheap()
h.printMaxheap()
print()

print("Your heap after sorting is \n")
h.maxheapSort()
h.printMaxheap()
print()