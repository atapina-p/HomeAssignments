/*
* Polina Atapina
* st139859@student.spbu.ru
* My project 3
*/

#ifndef SPARKCORE
#define SPARKCORE
#include <string>

class SparkCore {
    public:
        SparkCore(std::string sparkStatus);
        // Getters
        std::string getStatus();
        // Setters
        void changeStatus(std::string newStatus);
        
    private:
        std::string _status;
};
#endif
