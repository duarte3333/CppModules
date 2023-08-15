#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string materiaType;
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(const AMateria &other); 
        AMateria(std::string const & type);
        AMateria& operator=(const AMateria &other);

        int equiped;
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#include "ICharacter.hpp"

#endif