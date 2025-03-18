//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_MYSTACKNODE_H
#define PROJECT_1_MYSTACKNODE_H


#include "constants.h"

class myStackNode {
private:
    myStackNode* next{};
    char value[MAX_SIZE]{};
public:
    myStackNode(char* new_value, myStackNode* next);
    myStackNode* getNext();
    char* getValue();
};


#endif //PROJECT_1_MYSTACKNODE_H
