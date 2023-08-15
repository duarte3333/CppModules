#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
    protected:
        std::string materiaType;
    public:
        Ice();
        Ice(const Ice &other); 
        Ice& operator=(const Ice &other);
        ~Ice();
        Ice(std::string const & type);

        Ice* clone() const;
        void use(ICharacter& target);
};

#endif
