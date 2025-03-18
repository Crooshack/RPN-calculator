//
// Created by Bartek Kruszyński on 08.03.2024.
//

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "myStackNode.h"
#include "constants.h"


//content of the provided char table is copied to a new local char table
myStackNode::myStackNode(char* new_value, myStackNode* next) {
    strncpy(this->value, new_value, MAX_SIZE);
    this->next = next;
}


myStackNode* myStackNode::getNext(){
    return next;
}

char* myStackNode::getValue() {
    return value;
}
