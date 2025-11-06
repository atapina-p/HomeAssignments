/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#include "SparkCore.h"

SparkCore::SparkCore(std::string sparkStatus): _status(sparkStatus){};


void SparkCore::changeStatus(std::string newStatus){
    _status = newStatus;
}


std::string SparkCore::getStatus(){
    return _status;
}


