#include "Fixed.hpp"

int Fixed::fractional = 8;

Fixed::Fixed() : fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* Copy Constructor.
Copia do other para o this, assegurando alocacoes de memoria independentes */
Fixed& Fixed::operator=(const Fixed& other)
{
   std::cout << "Copy assignment operator called" << std::endl;
   if (this != &other) // Verifica se a atribuicao e a dele mesmo
   {
        fixed = other.getRawBits();
        fractional = other.fractional;
   }
   return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed;
}

void Fixed::setRawBits(const int raw)
{
    this->fixed = raw;
}