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
