#ifndef DOG_HPP
#define DOG_HPP
#include "AbsAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbsAnimal{
    private:
        Brain* brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        
        void makeSound() const;
        void setBrainIdea(std::string idea, int index);
        void showBrainIdea(int index);
};

#endif