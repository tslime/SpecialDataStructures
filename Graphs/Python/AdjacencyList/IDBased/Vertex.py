import sys
import os

class Vertex:

    def __init__(self,id,label,data):
        self.id = id
        self.label = label
        self.data = data
        self.edge_weight = 0
        self.next =None