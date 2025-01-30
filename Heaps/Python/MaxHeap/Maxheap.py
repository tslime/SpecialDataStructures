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
            for i in range(self.size):
                print(self.slots[i],end=" ")
            
            print()
    
    def insertMaxheap(self,d):
        if self.num_entries >= self.size:
            print("The heap is full \n")
        else:
            self.slots[self.num_entries] = d
            self.num_entries+=1
            self.bubbleUp(num_entries-1)
    
    def bubbleUp(self,pos):
        return None
    
    def deleteMaxheap(self):
        if self.num_entries == 0:
            print("The heap is empty")
        else:
            r = self.slots[0]
            self.slots[0] = self.slots[self.num_entries-1]
            self.slots[self.num_entries-1] = sys.maxsize
            self.num_entries-=1
            self.bubbleDown()
    
    def bubbleDown(self,pos):
        return None

    def maxheapSort(self):
        return None


"""Testing"""