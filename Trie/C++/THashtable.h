#ifndef THASHTABLE_H
#define THASHTABLE_H



#include<vector>

using std::vector;

class TNode; 

class THashtable{

            public:
                  int size;
                  int num_c;
                  vector<TNode*> slots;

                  THashtable(int s):size(s),num_c(0),slots(s){}


};

#endif