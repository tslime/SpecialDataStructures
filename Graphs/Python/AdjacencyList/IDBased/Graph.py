import sys
import os
from Vertex import Vertex
from Edge import Edge
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
            print("The graph is empty")
        else:
            for i in range(len(self.e)):
                if self.e[i].v != None:
                    print("Vertex: ",self.e[i].v.label,end='\n')
                    if self.e[i].v.next == None:
                        print("This vertex has no connections\n")
                    else:
                        aux = self.e[i].v.next
                        print("This vertex has the following connections: \n")
                        while aux != None:
                            print("========> ",aux.label,end="\n")
                            aux = aux.next
                print()

    def addVertex(self,v_id,v_l,v_d):
        ve = Vertex(v_id,v_l,v_d)

        if self.order >= len(self.e):
            print("There is no empty space to insert a vertex \n")
        else:
            self.e[self.order].v = ve
            self.order+=1
            

    def deleteVertex(self,v_id):
        if(v_id >= self.size or self.e[v_id].v == None):
            print("This vertex does not exist \n")
        else:
            i = 0
            while i < len(self.e):
                
                aux = self.e[i].v
                prev = None
                while aux != None and aux.id != v_id:
                    prev = aux
                    aux = aux.next
                
                if aux != None:
                    if prev == None:
                        self.e[i].v = None
                    else:
                        prev.next = aux.next
                
                i+=1
            
            self.order-=1


                    

    def addEdge(self,src,dst,weight):
        if src >= self.size or dst >= self.size or self.e[src].v == None or self.e[dst].v == None:
            print("Either the source or destination do not exist\n")
        else:
            tmp = Vertex(self.e[dst].v.id,self.e[dst].v.label,self.e[dst].v.data)
            tmp.edge_weight = weight
            aux = self.e[src].v
            b = (aux.id == dst)

            while aux.next !=None and not(b):
                aux = aux.next
                b = (aux.id == dst)
            
            if b:
                print("This connection already exist")
            else:
                aux.next = tmp
                self.degree+=1



    def deleteEdge(self,src,dst):
        if src >= self.size or self.e[src].v == None or dst >= self.size:
            print("Either the source or desitination vertex do not exist")
        else:
            aux = self.e[src].v.next
            prev = None
            b = False
            while aux != None and not(b):
                if aux.id == dst:
                    b = True
                else:
                    prev = aux
                    aux = aux.next
            
            if b:
                if prev == None:
                    self.e[src].v.next = self.e[src].v.next.next
                    self.degree-=1
                else:
                    prev.next = aux.next
                    self.degree -=1
            else:
                print("There is no connection between both Vertices")


    def dijsktraAlgo(self,src):
        INT_MAX = 2**31 - 1
        res = self.order*[None]
        pq = PQueue(self.order)

        for i in range(len(res)):
            temp = Vertex(self.e[i].v.id,self.e[i].v.label,self.e[i].v.data)
            if temp.id == src:
                temp.edge_weight = 0
                pq.insert(temp)
            else:
                temp.edge_weight = INT_MAX
            
            res[i] = temp

        totald = 0
        while pq.num_vd > 0:          
            tmp = pq.pop()
            aux = self.e[tmp.id].v.next
        
            while aux != None:
                totald = tmp.edge_weight + aux.edge_weight
                if totald < res[aux.id].edge_weight:
                    res[aux.id].edge_weight = totald
                    pq.insert(res[aux.id])
            
                aux = aux.next

        return res

"""Testing"""


print("Give me the size of your graph\n")
N = int(input())
g = Graph(N)
print()

print("How many vertices would you like to insert\n")
nv = int(input())

i=0
while i < nv:
    print("Give me the id,label, and data for vertex: ",i)
    vid = int(input())
    vl = input()
    vdata = input()
    g.addVertex(vid,vl,vdata)
    i+=1
    print()

print()

yv = 1

while(yv):
    print("Would you like to add an edge 1 for yes/0 for no \n")
    yv = int(input())
    if yv:
        print("Give me the ids fo your source and destination vertex and the edge weight\n")
        src_v = int(input())
        dst_v = int(input())
        w_v = int(input())
        g.addEdge(src_v,dst_v,w_v)
    
    print()
   
   

print()

g.printGraph()
print()

while True:
    print("Give me the source vertex for which you want to calculate the distance to other vertices \n")
    v_src = int(input())

    r= g.dijsktraAlgo(v_src)
    print("The distance from ",g.e[src_v].v.label," to other vertices is: \n")
    for i in range(len(r)):
        print("========> ",r[i].label," :",r[i].edge_weight)
        print()
    
    print()


"""
print()
k = 1
while k:
    print("Would you like to delete a verex 1 for yes / 0 for no \n")
    k = int(input())
    ord = g.order

    if k:
        print("Give me the id of the vertex: \n")
        dv = int(input())
        g.deleteVertex(dv)
    
    print()
    if g.order < ord:
        g.printGraph()
"""

