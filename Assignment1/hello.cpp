/*
* Polina Atapina
* st139859@spbu.ru
* My project number one
*/

#include "hello.h"
#include <iostream>
#include <string>

using namespace std;

void myproject::sayHello () {
    cout << "Hello, world!" << endl;
    string line;
    while(true){
        getline(cin, line);
        cout << "Hello, " << line << "!" << endl;
    }
}