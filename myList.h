//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_MYLIST_H
#define PROJECT_1_MYLIST_H


#include "constants.h"
#include "myListNode.h"

class myList {
private:
    myListNode* first;
    myListNode* last;
public:
    myList();
    void put(char data[MAX_SIZE]);
    ~myList();

    void printList();

    bool isEmpty() const;

    void getAndPopFirst(char returnedValue[MAX_SIZE]);
};


#endif //PROJECT_1_MYLIST_H
