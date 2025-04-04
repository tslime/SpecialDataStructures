class THashtable:

    def __init__(self,s:int):
        self.size = s
        self.num_c = 0
        self.slots : list[TNode] = s*[None]