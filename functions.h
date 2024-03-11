#include "constants.h"
#include "myList/myList.h"
#include "myStack/myStack.h"


int getTypeOfToken(char token[MAX_SIZE]);
bool isOperand(const char* token);
int getPriority(const char* token);
myList* RPNConversion();
void convIf(myList* RPNformula, myStack* conversionStack, char* token);