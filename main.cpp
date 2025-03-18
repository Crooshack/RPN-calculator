#include <iostream>
#include "myStack.h"
#include "functions.h"
#include "myList.h"

using namespace std;

int main(){
    int numberOfFormulas;
    char result[MAX_SIZE];

    //reading number of formulas to process
    cin>>numberOfFormulas;
    for(int i=0; i<numberOfFormulas; i++) {
        //create RPNformula myList variable
        myList* RPNformula = new myList();
        //function reads a formula from stdin and creates the postfix notation form
        RPNConversion(RPNformula);
        RPNformula->printList();
        //obliczenie wyniku z postaci postfixowej, ktory zostaje zapisany w zmiennej result
        //calculate the result from postfix notation form and save it to the 'result' char table
        RPNCalc(RPNformula, result);
        cout<< result << endl << endl;
        //delete RPNformula
        delete RPNformula;
    }

    return 0;
}