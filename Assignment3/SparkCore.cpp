#include "SparkCore.h"

SparkCore::SparkCore(std::string sparkStatus): _status(sparkStatus){};


void SparkCore::changeStatus(std::string newStatus){
    _status = newStatus;
}


std::string SparkCore::getStatus(){
    return _status;
}


