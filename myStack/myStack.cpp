//
// Created by Bartek Kruszyński on 08.03.2024.
//

#include<cstring>
#include "myStack.h"

myStack::myStack() {
    this->top = nullptr;
}

void myStack::push(char new_value[MAX_SIZE]) {
    myStackNode* new_element = new myStackNode(new_value, top == nullptr ? nullptr : top);
    top = new_element;
}

//zawartość zwracana jest kopiowana do podanej tablicy charow
void myStack::pop(char textHolder[MAX_SIZE]) {
    if(top != nullptr){
        myStackNode* temp = this->top;
        this->top = this->top->getNext();
        strcpy(textHolder, temp->getValue());
        delete temp;
    }
    else{
        strcpy(textHolder, "");
    }
}

bool myStack::isEmpty() {
    if(top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

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




