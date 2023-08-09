#include "Fixed.hpp"

int Fixed::fractional = 8;

Fixed::Fixed() : fixed(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw){
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(raw << fractional);
}

Fixed::Fixed(float const raw){
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(raw * (1 << fractional)));
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
Fixed& Fixed::operator=(const Fixed &other)
{
   std::cout << "Copy assignment operator called" << std::endl;
   if (this != &other) {// Verifica se a atribuicao e a dele mesmo {
        fixed = other.getRawBits();
   }
   return *this;
}

int Fixed::getRawBits() const{
    return fixed;
}

void Fixed::setRawBits(const int raw){
    this->fixed = raw;
}

/* Esta funcao serve para passar de fixed point value
para float */
float Fixed::toFloat(void) const
{
    return ((float)this->getRawBits() / (1 << fractional));
}

/* O const serve para indicar que nao se altera
o estado da classe */
int Fixed::toInt(void) const
{
    return (this->getRawBits() >> fractional);
}

//Isto e um polimorfismo de overload
std::ostream& operator<<(std::ostream &os, const Fixed &fixed){
    os << fixed.toFloat();
    return (os);
}