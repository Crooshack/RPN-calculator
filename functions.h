//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_FUNCTIONS_H
#define PROJECT_1_FUNCTIONS_H

#include "constants.h"
#include "myList.h"
#include "myStack.h"


bool isOperand(const char* token);
int getPriority(const char* token);
void RPNConversion(myList* RPNformula);
void convIf(myList* RPNformula);
void convMinMax(myList* RPNformula, char minMaxToken[MAX_SIZE]);
void RPNCalc(myList* RPNFormula, char resultString[MAX_SIZE]);
void doCalculation(char calcOperator[MAX_SIZE], myStack* calculationStack);
void getArgumentsFromStack(int* arguments, int n, myStack* calculationStack);
int findMinimum(int* numbers, int n);
int findMaximum(int* numbers, int n);

#endif //PROJECT_1_FUNCTIONS_H