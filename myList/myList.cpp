//
// Created by Bartek Kruszyński on 08.03.2024.
//

#include "myList.h"
#include <iostream>

myList::myList() {
    first = nullptr;
    last = nullptr;
}

myListNode *myList::getFirst() {
    return first;
}

myListNode *myList::getLast() {
    return last;
}

void myList::put(char *data) {
    if(first == nullptr){
        myListNode* temp = new myListNode(data);
        first = temp;
        last = temp;
    }
    else{
        myListNode* temp = new myListNode(data);
        last->setNext(temp);
        last = temp;
    }
}


void myList::printList(){
    myListNode* temp = first;
    myListNode* temp2 = first->getNext();
    while(temp != nullptr){
        std::cout << temp->getValue() << " ";
        temp = temp2;
        if(temp != nullptr)
            temp2 = temp->getNext();
    }
}

myList::~myList(){
    last = nullptr;
    myListNode* temp = first;
    myListNode* temp2 = first->getNext();
    while(temp != nullptr){
        delete temp;
        temp = temp2;
        if(temp != nullptr)
            temp2 = temp->getNext();
    }
}




