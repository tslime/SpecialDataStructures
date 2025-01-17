import os
import sys
from Vertex import Vertex
from Edge import Edge
from HashTable import HashTable
from PQueue import PQueue

class Graph:
    
    def __init__(self,size):
        self.size = size
        self.order = 0
        self.degree = 0
        self.e = size*[None] 

        for i in range(size):
            self.e[i] = Edge()
            self.e[i].v = None
    
    def printGraph(self):
        if self.order == 0:
            print("The graph is empty \n")
        else:
            for i in range(self.size):
                if self.e[i].v != None:
                    print("This is vertex: ",self.e[i].v.label)
                    aux = self.e[i].v.next
                    if aux == None:
                        print("\n This vertex has no connections \n")
                    else:
                        print(" and it has the following connections: \n")
                        while aux!= None:
                            print("=========>",aux.label) 
                            aux = aux.next

                        print("\n \n")
    
    def addVertex(self,e:Vertex,t:HashTable):
        if(self.order >= self.size):
            printf("There is no space where to add a vertex")
        else:
            self.e[self.order].v = e
            t.insertHT(e.label,self.order)
            self.order +=1
    
    def addEdge(self,src,dst,e_w,t:HashTable):
        src_id = t.searchHT(src)
        dst_id = t.searchHT(dst)

        if src_id == None or dst_id == None:
            print("Either the source or destination vertex does not exist")
        else:
            temp = Vertex(self.e[dst_id.value].v.label,self.e[dst_id.value].v.id,self.e[dst_id.value].v.data)
            temp.edge_weight = e_w
            aux = self.e[src_id.value].v
            while aux.next != None:
                aux = aux.next
            
            aux.next = temp
            self.degree+=1

    def deleteVertex(self,src,t:HashTable):
        src_v = t.searchHT(src)

        if src_v == None:
            print("This vertex does not exist \n")
        else:
            for i in range(self.size):
                aux = self.e[i].v
                prev = None
                b = False

                while aux != None and not(b):
                    if aux.label == src:
                        b = True
                    else:
                        prev = aux
                        aux = aux.next
                
                if b:
                    if prev == None:
                        self.e[i].v = None
                    else:
                        prev.next = aux.next

            self.order-=1
            t.deleteHT(src)

    
    def deleteEdge(self,src,dst,t:HashTable):
        src_id = t.searchHT(src)
        dst_id = t.searchHT(dst)

        if src_id == None or dst_id == None:
            print("either the source or destination vertex does not exist \n")
        else:
            aux = self.e[src_id.value].v.next
            prev = None
            b = False

            while aux != None and not(b):
                if aux.label == dst:
                    b = True
                else:
                    prev = aux
                    aux = aux.next
            
            if b:
                self.degree-=1
                if prev == None:
                    self.e[src_id.value].v.next = self.e[src_id.value].v.next.next
                else:
                    prev.next = aux.next
            else:
                print("There is no connection between ",src," and ",dst)
                print()

    def dijkstraAlgo(self,src,t:HashTable):
        v_src = t.searchHT(src)

        if v_src == None:
            print("This vertex does not exist \n")
        else:
            INFINITY = 10**18
            res = self.size*[None]
            q = PQueue(self.size)
            
            for i in range(self.size):
                temp = Vertex(self.e[i].v.label,self.e[i].v.id,self.e[i].v.data)
                if src != self.e[i].v.label:
                    temp.edge_weight = INFINITY
                    res[i] = temp
                else:
                    temp.edge_weight = 0
                    res[i] = temp
                    q.insert(temp)
            
            while q.num_vd > 0:
                temp = q.pop()
                temp_id = t.searchHT(temp.label)
                aux = self.e[temp_id.value].v.next
                
                while aux != None:
                    total_w = temp.edge_weight + aux.edge_weight
                    aux_id = t.searchHT(aux.label)

                    if total_w < res[aux_id.value].edge_weight:
                        res[aux_id.value].edge_weight = total_w
                        q.insert(res[aux_id.value]) 

                    aux = aux.next
        
            return res









"""Testing"""

print("Give me the size of your graph: \n")
N = int(input())
g = Graph(N)
t = HashTable(N)

i = 0
while i < N:
    print("Give me the label, id and data of vertex: ",i,"\n")
    e_l = input()
    e_id = int(input())
    e_d = input()

    temp = Vertex(e_l,e_id,e_d)
    g.addVertex(temp,t)
    i+=1
    print()

print()

b = 1
while b:
    print("Would you like to add edges 1 for yes\0 for no \n")
    b = int(input())

    if b:
        print("Give me the source and destination vertices as well as the edge weight: \n")
        v_src = input()
        v_dst = input()
        v_w = int(input())
        g.addEdge(v_src,v_dst,v_w,t)

print()

g.printGraph()

while True:
    print("Give me the source vertex for which you would to calculate the short distance to all other vertices:")
    src = input()
    r = g.dijkstraAlgo(src,t)
    print()
    
    if r != None:
        print("The shortest distance from ",src," to each vertex is: \n")
        print()
        for x in range(len(r)):
            print("==========> ",r[x].label,": ",r[x].edge_weight," \n")
    
    print()
    

