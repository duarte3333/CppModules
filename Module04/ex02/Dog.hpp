#ifndef DOG_HPP
#define DOG_HPP
#include "AbsAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbsAnimal{
    public:
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        
        void makeSound() const;
};

#endif