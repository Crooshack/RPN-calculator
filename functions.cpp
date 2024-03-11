//
// Created by Bartek Kruszyński on 08.03.2024.
//

#include "functions.h"


//
// Created by Bartek Kruszyński on 08.03.2024.
//

#include <cstring>
#include <iostream>
#include "myStack/myStackNode.h"
#include "myList/myList.h"
#include "myStack/myStack.h"

#ifndef PROJECT_1_FUNCTIONS_H
#define PROJECT_1_FUNCTIONS_H

#endif //PROJECT_1_FUNCTIONS_H

//#define PLUS '+'
//#define MINUS '-'
//#define TIMES '*'
//#define DIVIDE '/'
//#define IF "IF"
//#define N 'N'
//#define MIN 'MIN'
//#define MAX 'MAX'

using namespace std;



bool isOperand(const char* token){
    if(token[0] >= '0' && token[0] <= '9' ){
        return true;
    }
    else{
        return false;
    }
}

int getPriority(const char* token) {
    if (token[0] == '+' || token[0] == '-') {
        return 1;
    }
    else if (token[0] == '*' || token[0] == '/') {
        return 2;
    }
    else if (std::strstr(token, "IF") ||
             token[0] == 'N' ||
             std::strstr(token, "MIN") ||
             std::strstr(token, "MAX")
            ) {
        return 3;
    }
    return 0;
}


myList* RPNConversion(){
    myStack conversionStack;
    myList* RPNformula = new myList();
    char token[MAX_SIZE];

    while(true) {
        cin >> token;
        if(token[0] == '.'){
            break;
        }


        if(isOperand(token)){
            RPNformula->put(token);
        }
        else if(token[0] == '('){
            conversionStack.push(token);
        }
        else if(token[0] == ')') {
            while(!conversionStack.isEmpty()){
                conversionStack.pop(token);
                if(token[0] == '(') break;
                else{
                    RPNformula->put(token);
                }
            }
        }
        /*else if(strstr(token, "IF")){
            convIf(RPNformula, &conversionStack, token);
        }*/
        else {
            int priority = getPriority(token);
            while(!conversionStack.isEmpty()){
                char tempToken[MAX_SIZE];
                conversionStack.pop(tempToken);
                if(tempToken[0] == '(' || getPriority(tempToken) < priority){
                    conversionStack.push(tempToken);
                    break;
                }
                RPNformula->put(tempToken);
            }
            conversionStack.push(token);
        }
    }

    while(!conversionStack.isEmpty()){
        conversionStack.pop(token);
        RPNformula->put(token);
    }

    return RPNformula;
}


/*
void convIf(myList* RPNformula, myStack* conversionStack, char* ifToken){
    char token[MAX_SIZE];
    strcpy(token, ifToken);

    conversionStack->push(token);

    while(true){
        cin >> token;
        if(token[0] == ')'){
            break;
        }


        if(isOperand(token)){
            RPNformula->put(token);
        }
        else if(token[0] == '('){
            conversionStack->push(token);
        }
        else if(token[0] == ')') {
            while(!conversionStack->isEmpty()){
                conversionStack->pop(token);
                if(token[0] == '(') break;
                else{
                    RPNformula->put(token);
                }
            }
        }
        else if(strstr(token, "IF")){
            convIf(RPNformula, &conversionStack, token);
        }
        else {
            int priority = getPriority(token);
            while(!conversionStack.isEmpty()){
                char tempToken[MAX_SIZE];
                conversionStack.pop(tempToken);
                if(tempToken[0] == '(' || getPriority(tempToken) < priority){
                    conversionStack.push(tempToken);
                    break;
                }
                RPNformula->put(tempToken);
            }
            conversionStack.push(token);
        }
    }

    while(!conversionStack.isEmpty()){
        conversionStack.pop(token);
        RPNformula->put(token);
    }
}*/
