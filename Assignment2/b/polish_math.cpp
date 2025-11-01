/*
* Polina Atapina
* st139859@student.spbu.ru
* My project number two(b)
*/
#include "polish_math.h"

#include <stack>
#include <sstream>

void PolishMathing(std::string expression){
    std::stack<double> num_stack; // create stack, where we will store the last results and numbers
    std::stringstream stream(expression); // create a pointer that will traverse the entered string(expression)
    std::string value;
    double el1, el2; // create two variables that will be used for calculations
    while(stream>>value){
        if (value=="+"){
            el1 = num_stack.top();
            num_stack.pop();
            el2 = num_stack.top()+el1;
            num_stack.pop();
            num_stack.push(el2);
        }
        else if (value=="-"){
            el1 = num_stack.top();
            num_stack.pop();
            el2 = num_stack.top()-el1;
            num_stack.pop();
            num_stack.push(el2);
        }
        else if (value=="*"){
            el1 = num_stack.top();
            num_stack.pop();
            el2 = num_stack.top()*el1;
            num_stack.pop();
            num_stack.push(el2);
        }
        else if (value=="/"){
            el1 = num_stack.top();
            num_stack.pop();
            el2 = num_stack.top()/el1;
            num_stack.pop();
            num_stack.push(el2);
        }
        else {
            num_stack.push(stod(value));
        }
    }
    std::cout << "result: " << num_stack.top() << std::endl;
}