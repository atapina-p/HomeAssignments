/*
* Polina Atapina
* st139859@student.spbu.ru
* My project number two(b)
*/

#include "polish_math.h"

int main(){
    std::cout << "Enter your reverse Polish entry." << std::endl;
    std::cout << "Please, before you finish entering the record, make sure that the recorded record is correct and it corresponds to the classic reverse Polish record, otherwise the program will not work correctly." << std::endl;
    std::string userInput;
    std::getline(std::cin, userInput); 
    PolishMathing(userInput);
}