//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_MYLISTNODE_H
#define PROJECT_1_MYLISTNODE_H


#include "constants.h"

class myListNode {
private:
    myListNode* next;
    char value[MAX_SIZE];
public:
    myListNode(char *newValue);
    myListNode* getNext();
    void setNext(myListNode* next);
    char* getValue();
};


#endif //PROJECT_1_MYLISTNODE_H
