#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"

class Animal {
    protected:
        std::string type;
        Brain* brain;
    public:
        Animal(); //Constructor
        virtual ~Animal(); //Destructor, sendo virtual passa a ser o filho a destruir o animal
        Animal(const Animal &other); //Copy constructor
        Animal& operator=(const Animal &other); //Copy assign operator
        
        void setType(std::string inputType);
        std::string getType(void) const;
        virtual void makeSound() const;
};

#endif