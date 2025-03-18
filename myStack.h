//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_MYSTACK_H
#define PROJECT_1_MYSTACK_H


#include "myStackNode.h"

class myStack {
private:
    myStackNode* top{};
public:
    myStack();
    void push(char new_value[MAX_SIZE]);
    void pop(char textHolder[MAX_SIZE]);
    bool isEmpty() const;
    void printStack() const;
    ~myStack();
};


#endif //PROJECT_1_MYSTACK_H
