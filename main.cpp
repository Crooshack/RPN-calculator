#include <iostream>
#include "myStack/myStack.h"
#include "functions.h"
#include "myList/myList.h"

using namespace std;

int main(){
    int numberOfFormulas;
    myList* RPNformula;

    //char token[MAX_SIZE];

    cin>>numberOfFormulas;

    for(int i=0; i<numberOfFormulas; i++) {
        RPNformula = RPNConversion();
        RPNformula->printList();
        delete RPNformula;
    }



    //delete RPNformula;

    //calculating result


    return 0;
}