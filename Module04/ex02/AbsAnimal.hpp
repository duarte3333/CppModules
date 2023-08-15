#ifndef ABSANIMAL_HPP
#define ABSANIMAL_HPP
#include <iostream>

class AbsAnimal {
    protected:
        std::string type;
    public:
        AbsAnimal(); //Constructor
        virtual ~AbsAnimal(); //Destructor, sendo virtual passa a ser o filho a destruir o AbsAnimal
        AbsAnimal(const AbsAnimal &other); //Copy constructor
        AbsAnimal& operator=(const AbsAnimal &other); //Copy assign operator
        
        void setType(std::string inputType);
        std::string getType(void) const;
        virtual void makeSound() const = 0;
};

#endif