//
// Created by Bartek Kruszyński on 08.03.2024.
//

#include <cstring>
#include "myListNode.h"


myListNode::myListNode(char *new_value) {
    strncpy(this->value, new_value, MAX_SIZE);
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
