"""from __future__ import annotations"""
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
            for i in range(self.size):
                print(self.slots[i]," ")
            
            print("")    

    def insertMinheap(self,d: int):
        if(self.num_entries >= self.size):
            print("The heap is full")
        else:
            self.slots[self.num_entries] = d
            self.num_entries+=1
            self.bubbleUp(self.num_entries-1)
    
    def bubbleUp(self,pos: int):
        return None

    def deleteMinheap(self):
        r = None
        if self.num_entries == 0:
            print("The heap is empty \n")
        else:
            r = self.num_entries[0]
            self.slots[0] = self.slots[self.num_entries-1]
            self.slots[self.num_entries] = sys.maxsize
            self.num_entries-=1
            self.bubbleDown()
    
    def bubbleDown(self):
        return None
    
    def minheapSort(self):
        return None




"""Testing"""

print("test \n")