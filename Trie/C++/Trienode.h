#ifndef TRIENODE_H
#define TRIENODE_H


class THashtable;

class Trienode{

            public: 
                  bool iseofw;
                  THashtable *tn;

                  Trienode():iseofw(false),tn(nullptr){}
};

#endif