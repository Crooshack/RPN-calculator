//
// Created by Bartek Kruszyński on 08.03.2024.
//

#define _CRT_SECURE_NO_WARNINGS

#include "myList.h"
#include <iostream>
#include <cstring>

//initialization of an empty list
myList::myList() {
    first = nullptr;
    last = nullptr;
}

//value is returned to char table provided in args
void myList::getAndPopFirst(char returnedValue[MAX_SIZE]) {
    if(!this->isEmpty()){
        myListNode* temp = this->first;
        this->first = this->first->getNext();
        if(this->first == nullptr){
            last = nullptr;
        }
        strcpy(returnedValue, temp->getValue());
        delete temp;
    }
    //if list is empty, return empty string
    else{
        strcpy(returnedValue, "");
    }
}

//value from char table provided in args is put in the list
void myList::put(char data[MAX_SIZE]) {
    if(this->isEmpty()){
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

//checks if list is empty
bool myList::isEmpty() const {
    if(first == nullptr){
        return true;
    }
    else{
        return false;
    }
}

//prints all list elements separated with spaces
void myList::printList(){
    myListNode* temp = first;
    myListNode* temp2 = first->getNext();
    while(temp != nullptr){
        std::cout << temp->getValue() << " ";
        temp = temp2;
        if(temp != nullptr)
            temp2 = temp->getNext();
    }
    std::cout<<std::endl;
}

//if list is not empty, delete all the elements left
myList::~myList(){
    if(!this->isEmpty()){
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
}




