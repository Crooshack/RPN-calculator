//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_MYLIST_H
#define PROJECT_1_MYLIST_H


#include "../constants.h"
#include "myListNode.h"

class myList {
private:
    myListNode* first;
    myListNode* last;
public:
    myList();
    myListNode* getFirst();
    myListNode* getLast();
    void put(char data[MAX_SIZE]);
    ~myList();

    void printList();
};


#endif //PROJECT_1_MYLIST_H
