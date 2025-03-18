//
// Created by Bartek Kruszyński on 08.03.2024.
//

#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"


#include <cstring>
#include <iostream>
#include <cstdlib>
#include "myStackNode.h"
#include "myList.h"
#include "myStack.h"

using namespace std;


//checks if the given token in char table is an operand
bool isOperand(const char* token){
    if(token[0] >= '0' && token[0] <= '9' ){
        return true;
    }
    //if a negative number
    else if(token[0] == '-'){
        if(token[1] >= '0' && token[1] <= '9' ){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

//returns priority of an operator
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

//function reads formula from stdin and creates postfix notation form formula (Reverse Polish Notation/RPN)
//WARNING - creates dynamically allocated myList object which should be deleted if not in use, using 'delete'
void RPNConversion(myList* RPNformula){
    myStack conversionStack;
    char token[MAX_SIZE];

    while(true) {
        cin >> token;
        //dot is the end of a formula
        if(token[0] == '.'){
            break;
        }

        if(isOperand(token)){
            RPNformula->put(token);
        }
        else if(token[0] == '('){
            conversionStack.push(token);
        }
        //putting all operators left from inside the brackets
        else if(token[0] == ')') {
            while(!conversionStack.isEmpty()){
                conversionStack.pop(token);
                if(token[0] == '(') break;
                else{
                    RPNformula->put(token);
                }
            }
        }
        //process IF contents then put 'IF' operator in RPNformula
        else if(strstr(token, "IF")){
            convIf(RPNformula);
            RPNformula->put(token);
        }
        //process MIN/MAX contents then put 'MINn'/'MAXn' operator in RPNformula
        else if(strstr(token, "MIN") || strstr(token, "MAX")){
            convMinMax(RPNformula, token);
            RPNformula->put(token);
        }
        //Negation is treated like normal operator but with higher priority
        else if(strstr(token, "N")) {
            conversionStack.push(token);
        }
        //new operator encountered
        else {
            int priority = getPriority(token);
            while(!conversionStack.isEmpty()){
                char tempToken[MAX_SIZE];
                conversionStack.pop(tempToken);

                // check if there are higher priority operator on stack, then put them in RPNformula
                // '(' means that we don't want to go out of inside of brackets
                if(tempToken[0] == '(' || getPriority(tempToken) < priority){
                    conversionStack.push(tempToken);
                    break;
                }
                RPNformula->put(tempToken);
            }
            //afterward push the new operator on the stack
            conversionStack.push(token);
        }
    }

    //if there's anything left on the stack, put it in the RPNformula
    while(!conversionStack.isEmpty()){
        conversionStack.pop(token);
        RPNformula->put(token);
    }
}

//function to process the inside of 'IF'
void convIf(myList* RPNformula){
    char token[MAX_SIZE];
    myStack localConversionStack;

    do {
        cin >> token;

        if(isOperand(token)){
            RPNformula->put(token);
        }
        else if(token[0] == '(') {
            localConversionStack.push(token);
        }
        else if(token[0] == ')') {
            while(!localConversionStack.isEmpty()){
                localConversionStack.pop(token);
                if(token[0] == '(') break;
                else{
                    RPNformula->put(token);
                }
            }
        }
        else if(strstr(token, "IF")){
            convIf(RPNformula);
            RPNformula->put(token);
        }
        else if(strstr(token, "MIN") || strstr(token, "MAX")){
            convMinMax(RPNformula, token);
            RPNformula->put(token);
        }
        else if(strstr(token, "N")){
            localConversionStack.push(token);
        }
        //if comma is encountered put all operator left on the stack until the opening bracket of 'IF'
        else if(token[0] == ','){
            while(!localConversionStack.isEmpty()){
                localConversionStack.pop(token);
                if(token[0] == '('){
                    localConversionStack.push(token);
                    break;
                }
                else{
                    RPNformula->put(token);
                }
            }
        }
        else {
            int priority = getPriority(token);
            while(!localConversionStack.isEmpty()){
                char tempToken[MAX_SIZE];
                localConversionStack.pop(tempToken);
                if(tempToken[0] == '(' || getPriority(tempToken) < priority){
                    localConversionStack.push(tempToken);
                    break;
                }
                RPNformula->put(tempToken);
            }
            localConversionStack.push(token);
        }

    //stop when stack is empty (when we encounter ')' of 'IF')
    } while(!localConversionStack.isEmpty());
}

//function to process the inside of 'MIN' or 'MAX'
void convMinMax(myList* RPNformula, char minMaxToken[MAX_SIZE]){
    char token[MAX_SIZE];
    int argCounter = 1;
    myStack localConversionStack;

    do {
        cin >> token;

        if(isOperand(token)){
            RPNformula->put(token);
        }
        else if(token[0] == '(') {
            localConversionStack.push(token);
        }
        else if(token[0] == ')') {
            while(!localConversionStack.isEmpty()){
                localConversionStack.pop(token);
                if(token[0] == '(') break;
                else{
                    RPNformula->put(token);
                }
            }
        }
        else if(strstr(token, "IF")){
            convIf(RPNformula);
            RPNformula->put(token);
        }
        else if(strstr(token, "MIN") || strstr(token, "MAX")){
            convMinMax(RPNformula, token);
            RPNformula->put(token);
        }
        else if(strstr(token, "N")){
            localConversionStack.push(token);
        }
        //if comma is encountered put all operator left on the stack until the opening bracket of 'IF' and increase number of arguments
        else if(token[0] == ','){
            argCounter++;
            while(!localConversionStack.isEmpty()){
                localConversionStack.pop(token);
                if(token[0] == '('){
                    localConversionStack.push(token);
                    break;
                }
                else{
                    RPNformula->put(token);
                }
            }
        }
        else {
            int priority = getPriority(token);
            while(!localConversionStack.isEmpty()){
                char tempToken[MAX_SIZE];
                localConversionStack.pop(tempToken);
                if(tempToken[0] == '(' || getPriority(tempToken) < priority){
                    localConversionStack.push(tempToken);
                    break;
                }
                RPNformula->put(tempToken);
            }
            localConversionStack.push(token);
        }

    //stop when stack is empty (when we encounter ')' of 'MIN'/'MAX')
    } while(!localConversionStack.isEmpty());


    //adding number of arguments on the end of 'MIN'/'MAX' token
    strcpy(token, minMaxToken);
    sprintf (minMaxToken, "%s%d", token, argCounter);
}


//process an RPN formula and save the result to the 'resultString' char table
void RPNCalc(myList* RPNFormula, char resultString[MAX_SIZE]){
    myStack calculationStack;
    char token[MAX_SIZE];

    while(!RPNFormula->isEmpty()){
        RPNFormula->getAndPopFirst(token);

        if(isOperand(token)){
            calculationStack.push(token);
        }
        else{
            //print current operator
            std::cout << token << " ";
            //print stack content
            calculationStack.printStack();

            //calculate and get result on stack
            doCalculation(token, &calculationStack);
            calculationStack.pop(token);

            //if error, end processing
            if(token[0] == 'E'){
                strcpy(resultString, token);
                return;
            }
            //if not put token back on stack
            else{
                calculationStack.push(token);
            }
        }
    }

    //get the result of the formula to the 'resultString' char table
    calculationStack.pop(resultString);
}


//do a single calculation
void doCalculation(char calcOperator[MAX_SIZE], myStack* calculationStack){
    int* numbers = nullptr;
    int result = INT_MIN;
    char token[MAX_SIZE];

    if(calcOperator[0] == '+'){
        numbers = new int[STANDARD_NUM_OF_ARGS];
        getArgumentsFromStack(numbers, STANDARD_NUM_OF_ARGS, calculationStack);

        result = numbers[OP1_INDEX] + numbers[OP2_INDEX];
    }
    else if(calcOperator[0] == '-'){
        numbers = new int[STANDARD_NUM_OF_ARGS];
        getArgumentsFromStack(numbers, STANDARD_NUM_OF_ARGS, calculationStack);

        result = numbers[OP1_INDEX] - numbers[OP2_INDEX];
    }
    else if(calcOperator[0] == '*'){
        numbers = new int[STANDARD_NUM_OF_ARGS];
        getArgumentsFromStack(numbers, STANDARD_NUM_OF_ARGS, calculationStack);

        result = numbers[OP1_INDEX] * numbers[OP2_INDEX];
    }
    else if(calcOperator[0] == '/'){
        numbers = new int[STANDARD_NUM_OF_ARGS];
        getArgumentsFromStack(numbers, STANDARD_NUM_OF_ARGS, calculationStack);

        //if divisor doesn't equal 0
        if(numbers[OP2_INDEX] != 0){
            result = numbers[OP1_INDEX] / numbers[OP2_INDEX];
        }
        //output 'ERROR' if division by zero
        else{
            sprintf(token, "ERROR");
            calculationStack->push(token);
            delete[] numbers;
            return;
        }
    }
    else if(calcOperator[0] == 'N'){
        numbers = new int[NEGATION_NUM_OF_ARGS];
        getArgumentsFromStack(numbers, NEGATION_NUM_OF_ARGS, calculationStack);

        result = -numbers[NEGATION_ARG_INDEX];
    }
    // IF ( a , b , c )
    else if(std::strstr(calcOperator, "IF")){
        numbers = new int[IF_NUM_OF_ARGS];
        getArgumentsFromStack(numbers, IF_NUM_OF_ARGS, calculationStack);

        if(numbers[IF_A_INDEX] > 0){
            result = numbers[IF_B_INDEX];
        }
        else{
            result = numbers[IF_C_INDEX];
        }
    }
    else if(std::strstr(calcOperator, "MIN")){
        //get number of arguments
        int numOfArgs;
        sscanf(calcOperator, "MIN%d", &numOfArgs);

        //create table for arguments
        numbers = new int[numOfArgs];
        //read arguments from stack
        getArgumentsFromStack(numbers, numOfArgs, calculationStack);

        //calculate result
        result = findMinimum(numbers, numOfArgs);
    }
    else if(std::strstr(calcOperator, "MAX")){
        //get number of arguments
        int numOfArgs;
        sscanf(calcOperator, "MAX%d", &numOfArgs);

        //create table for arguments
        numbers = new int[numOfArgs];
        //read arguments from stack
        getArgumentsFromStack(numbers, numOfArgs, calculationStack);

        //calculate result
        result = findMaximum(numbers, numOfArgs);
    }

    //save result to output char table
    sprintf(token, "%d", result);
    //delete arguments table
    delete[] numbers;
    //push the calculation result on the stack
    calculationStack->push(token);
}

//get n arguments from stack
void getArgumentsFromStack(int* arguments, int n, myStack* calculationStack){
    if(n > 0 && arguments != nullptr){
        char token[MAX_SIZE];
        for(int i=0; i < n; i++){
            calculationStack->pop(token);
            arguments[i] = atoi(token);
        }
    }
}

//find minimum value out of n values
int findMinimum(int* numbers, int n){
    if(n > 0 && numbers != nullptr){
        //finding minimum
        int minimum = numbers[0];
        for(int i = 1; i < n ; i++){
            if(numbers[i] < minimum){
                minimum = numbers[i];
            }
        }
        return minimum;
    }
    // ERROR - n must be greater than zero and numbers can't be null
    else{
        return INT_MAX;
    }
}

//find maximum value out of n values
int findMaximum(int* numbers, int n){
    if(n > 0 && numbers != nullptr){
        //finding maximum
        int maximum = numbers[0];
        for(int i = 1; i < n ; i++){
            if(numbers[i] > maximum){
                maximum = numbers[i];
            }
        }
        return maximum;
    }
    // ERROR - n must be greater than zero and numbers can't be null
    else{
        return INT_MIN;
    }
}