import sys
import os
from Vertex import Vertex


class PQueue:

    def __init__(self,size):
        self.size = size
        self.num_vd = 0
        self.vd = size*[None]

        for i in range(size):
            self.vd[i] = Vertex(None,None,None)

    def printPQ(self):
        if self.num_vd == 0:
            print("The queue is empty")
        else:
            print("The vertices in queue are: ")
            i=0
            while i < self.num_vd and self.v[i] != None:
                print(self.vd[i].label,end=" ")
                i+=1
            
            print()

    def printWPQ(self):
        if self.num_vd == 0:
            print("The queue is empty")
        else:
            print("The edge weights are: ")
            i=0
            while i < self.num_vd and self.vd[i] != None:
                print(self.vd[i].edge_weight,end=" ")
                i+=1
                
            print()

    def dsizePQ(self):
        temp = PQueue(2*self.size)

        for i in range(len(self.vd)):
            temp.vd[i] = self.vd[i]
        
        self.vd = temp.vd
        self.size = temp.size 
        

    def insert(self,ve:Vertex):
        if self.num_vd >= len(self.vd):
            self.dsizePQ()
            self.vd[self.num_vd] = ve
            self.num_vd+=1
            self.bubbleUp()
        else:
            self.vd[self.num_vd] = ve
            self.num_vd+=1
            self.bubbleUp()
        

    def bubbleUp(self):
        b = False
        c_index = self.num_vd-1
        while not(b):
            p_index = (c_index-1)//2
            if c_index <= 0 or self.vd[c_index].edge_weight >= self.vd[p_index].edge_weight:
                b = True
            else:
                temp = self.vd[p_index]
                self.vd[p_index] = self.vd[c_index]
                self.vd[c_index] = temp
                c_index = p_index
                     
    def peek(self):
        if self.num_vd == 0:
            print("The queue is empty")
        else:
            return self.vd[0]

    def pop(self):
        if self.num_vd <= 1:
            temp = self.vd[0]
            self.vd[0] = None
            self.num_vd-=1
            return temp
        else:
            temp = self.vd[0]
            self.vd[0] = self.vd[self.num_vd-1]
            self.vd[self.num_vd-1] = None
            self.num_vd-=1
            self.bubbleDown()
            return temp

    def bubbleDown(self):
        b = False
        k = 0
        while not(b):
            lc_v = 2*k + 1
            rc_v =  2*k + 2

            if lc_v >= self.num_vd and rc_v >= self.num_vd:
                b = True
            else:
                if rc_v < self.num_vd:
                    if self.vd[lc_v].edge_weight <= self.vd[rc_v].edge_weight:
                        if self.vd[k].edge_weight > self.vd[lc_v].edge_weight:
                            temp = self.vd[k]
                            self.vd[k] = self.vd[lc_v]
                            self.vd[lc_v] = temp
                            k = lc_v
                        else:
                            b = True
                    else:
                        if self.vd[k].edge_weight > self.vd[rc_v].edge_weight:
                            temp = self.vd[k]
                            self.vd[k] = self.vd[rc_v]
                            self.vd[rc_v] = temp
                            k = rc_v
                        else:
                            b = True
                else:
                    if self.vd[k].edge_weight > self.vd[lc_v].edge_weight:
                        temp = self.vd[k]
                        self.vd[k] = self.vd[lc_v]
                        self.vd[lc_v] = temp
                        k = lc_v
                    else:
                        b = True
    
  


        

"""Testing"""

"""
print("Give me the size of your queue \n")
N = int(input())

pq = PQueue(N)

print("Give me the number of your vertices that you would like to insert \n")
nv = int(input())

for i in range(nv):
    print("Give me the id,label, data and the edge weight of vertex ",i,"\n")
    v_id = int(input())
    v_label = input()
    v_data = input()
    v_weight = int(input())
    v_e = Vertex(v_id,v_label,v_data)
    v_e.edge_weight = v_weight
    pq.insert(v_e)

print()
pq.printWPQ()
print()

pq.pop()
pq.pop()
print("After popping twice \n")
pq.printWPQ()
"""