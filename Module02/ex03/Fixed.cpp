#include "Fixed.hpp"

int Fixed::fractional = 8;

//Constructors
Fixed::Fixed() : fixed(0) {
}
Fixed::Fixed(int const raw) {
    this->setRawBits(raw << fractional);
}
Fixed::Fixed(float const raw) {
    this->setRawBits(roundf(raw * (1 << fractional)));
}
Fixed::~Fixed() {
}
Fixed::Fixed(const Fixed &other) {
    *this = other;
}
/* Copy Constructor.
Copia do other para o this, assegurando alocacoes de memoria independentes */
Fixed& Fixed::operator=(const Fixed &other)
{
   if (this != &other) // Verifica se a atribuicao e a dele mesmo
   {
        fixed = other.getRawBits();
        fractional = other.fractional;
   }
   return *this;
}

//Comparison operators
bool Fixed::operator<(const Fixed &other) const {
    return (fixed < other.fixed);
}
bool Fixed::operator>(const Fixed &other) const {
    return (fixed > other.fixed);
}
bool Fixed::operator<=(const Fixed &other) const {
    return (fixed <= other.fixed);
}
bool Fixed::operator>=(const Fixed &other) const {
    return (fixed >= other.fixed);
}
bool Fixed::operator==(const Fixed &other) const {
    return (fixed == other.fixed);
}
bool Fixed::operator!=(const Fixed &other) const {
    return (other.fixed != this->fixed);
}

//Arithmetic operators
Fixed   Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}
Fixed   Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}
Fixed   Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed   Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

//Increment's and decrement's
/* Pre-increment */
Fixed& Fixed::operator++() {
    //this->fixed++; nao se justifica pq ja tou no scope da classe
    fixed++;
    return (*this);
}
/* Pre-decrement */
Fixed& Fixed::operator--(){
    fixed--;
    return (*this); //serve para retornar uma referencia
}
/* Post-increment */
Fixed Fixed::operator++(int n){
    (void)n;
    Fixed temp(this->toFloat());
    fixed++;
    return temp;
}
/* Post-decrement */
Fixed Fixed::operator--(int n){
    (void)n;
    Fixed temp(this->toFloat());
    fixed--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

//Member functions
void Fixed::setRawBits(const int raw){
    this->fixed = raw;
}

int Fixed::getRawBits() const {
    return this->fixed;
}

/* Esta funcao serve para passar de fixed point value
para float */
float Fixed::toFloat(void) const {
    return ((float)this->getRawBits() / (1 << fractional));
}

/* O const serve para indicar que nao se altera
o estado da classe */
int Fixed::toInt(void) const {
    return (this->getRawBits() >> fractional);
}

Fixed Fixed::abs() const {
    if (*this < 0)
        return *this * -1;
    return *this;
}

//Isto e um polimorfismo de overload
std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}