import sys
import os

class HNode:

    def __init__(self,k,v):
        self.key = k
        self.value = v
        self.next = None