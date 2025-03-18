//
// Created by Bartek Kruszyński on 08.03.2024.
//

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "myListNode.h"

//value from char table provided in args is copied to the 'value' myListNode variable
myListNode::myListNode(char *newValue) {
    strncpy(this->value, newValue, MAX_SIZE);
    this->next = nullptr;
}


myListNode* myListNode::getNext(){
    return next;
}

char *myListNode::getValue() {
    return value;
}

void myListNode::setNext(myListNode *next) {
    this->next = next;
}
