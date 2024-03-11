//
// Created by Bartek Kruszyński on 08.03.2024.
//

#include <cstring>
#include "myStackNode.h"
#include "../constants.h"


myStackNode::myStackNode(char *new_value, myStackNode *next) {
    strncpy(this->value, new_value, MAX_SIZE);
    this->next = next;
}


myStackNode* myStackNode::getNext(){
    return next;
}

char *myStackNode::getValue() {
    return value;
}
