import sys
import os

class Vertex:
    
    def __init__(self,label,id,data):
        self.label = label
        self.id = id
        self.data = data
        self.edge_weight = 0
        self.next = None
    