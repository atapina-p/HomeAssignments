#include "Transformer.h"
#include "PrimaryWeapon.h"



int main(){
    PrimaryWeapon gun(50);
    Transformer Robot1("polina", 100, 1000, true, gun);
    std::cout << Robot1.getName() << std::endl; 
}