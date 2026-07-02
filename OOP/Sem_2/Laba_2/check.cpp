#include <iostream>

class mistake {
    protected:
        std::string des = "Mistaaaaaaaaaaake";
    
    public:
        mistake(std::string new_des) : des(new_des) {}
        
        virtual std::string what() {
            return des;
        }
        
        ~mistake() {}    
};

class errorPointer : mistake {
    public:
        errorPointer() : mistake("Ошибочный указатель") {}
}

errorWorkingList

invalidIndex

fullList