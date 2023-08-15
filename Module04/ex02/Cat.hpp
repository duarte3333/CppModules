#ifndef CAT_HPP
#define CAT_HPP
#include "AbsAnimal.hpp"
#include "Brain.hpp"

class Cat : virtual public AbsAnimal{
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);
        
        void makeSound() const;
};

#endif