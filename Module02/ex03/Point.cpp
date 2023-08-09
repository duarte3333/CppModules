#include "Point.hpp"

Point::Point() : x(0) , y(0){
}

Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const float delta) : x(delta), y(delta) {}

Point::~Point(){
}

Point::Point(const Point &other) {
    *this = other;
}
/* Copy Constructor.
Copia do other para o this, assegurando alocacoes de memoria independentes */
Point& Point::operator=(const Point &other)
{
    const_cast<Fixed&>(this->x) = other.getX();
    const_cast<Fixed&>(this->y) = other.getY();
    return *this;
}

const Fixed &Point::getX() const {
    return x;
}

const Fixed &Point::getY() const {
    return y;
}