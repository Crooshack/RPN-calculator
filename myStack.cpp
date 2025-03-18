//
// Created by Bartek Kruszyński on 08.03.2024.
//

#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include <iostream>
#include "myStack.h"

myStack::myStack() {
    this->top = nullptr;
}

//push element on stack
//content of the provided char table is copied to a new local char table
void myStack::push(char new_value[MAX_SIZE]) {
    myStackNode* new_element = new myStackNode(new_value, top == nullptr ? nullptr : top);
    top = new_element;
}

//the return value is copied to the provided char table
void myStack::pop(char textHolder[MAX_SIZE]) {
    if(!this->isEmpty()){
        myStackNode* temp = this->top;
        this->top = this->top->getNext();
        strcpy(textHolder, temp->getValue());
        delete temp;
    }
    //if stack is empty return empty string
    else{
        strcpy(textHolder, "");
    }
}

// print all stack elements separated with spaces
void myStack::printStack() const {
    myStackNode* temp = top;
    while (temp != nullptr) {
        std::cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

//check if empty
bool myStack::isEmpty() const {
    if(top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

//if stack not empty, delete all elements left
myStack::~myStack(){
    if(!this->isEmpty()){
        myStackNode* temp = top;
        myStackNode* temp2 = top->getNext();
        while(temp != nullptr){
            delete temp;
            temp = temp2;
            if(temp != nullptr)
                temp2 = temp->getNext();
        }
    }
}




