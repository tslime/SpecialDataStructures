import os
import sys
from TNode import TNode
sys.setrecursionlimit(5000)

class BTree:
    def __init__(self):
        self.root = None
    
    def printBST(self,r: TNode):
        if r != None:
            self.printBST(r.left)
            print(r.data,end=" ")
            self.printBST(r.right)

    def insertBST(self,r: TNode,d):
        if r == None:
            e = TNode(d)
            return e
        else:
            if d <= r.data:
                r.left = self.insertBST(r.left,d)
            else:
                r.right = self.insertBST(r.right,d)
        
        return r

    def searchBST(self,r: TNode,d):
        if r != None:
            if r.data == d:
                return True
            else:
                if d < r.data:
                    return self.searchBST(r.left,d)
                else:
                    return self.searchBST(r.right,d)
        else:
            return False

    def deleteBST(self,r:TNode,d):
        if r != None:
            if r.data == d:
                if r.left == None:
                    r = r.right
                else:
                    if r.right == None:
                        r = r.left
                    else:
                        prev = None
                        aux = r.right

                        while aux.left != None:
                            prev = aux
                            aux = aux.left

                        r.data = aux.data

                        if prev == None:
                            r.right = aux.right
                        else:
                            if aux.right == None:
                                prev.left = aux.left
                            else:
                                prev.left = aux.right             
            else:
                if d < r.data:
                    r.left = self.deleteBST(r.left,d)
                else:
                    r.right = self.deleteBST(r.right,d)
        
        return r







"""Testing"""

r = BTree()


print("Give me the number of elements would you like to insert: \n")
N = int(input())

print("Give me your elements: \n")
for i in range(N):
    n = int(input())
    r.root = r.insertBST(r.root,n)

print()
print()

r.printBST(r.root)
print()
print()

while True:
    print("Give me the element you want to delete: \n")
    s = int(input())
    res = r.deleteBST(r.root,s)

    print()
    print("Your new tree is: \n")
    r.printBST(r.root)
    print()


print()
print()