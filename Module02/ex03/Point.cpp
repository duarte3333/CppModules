#include "Point.hpp"

Point::Point() : x(0) , y(0){
}

Point::~Point(){
}

Point::Point(const Point &other) {
    *this = other;
}
/* Copy Constructor.
Copia do other para o this, assegurando alocacoes de memoria independentes */
Point& Point::operator=(const Point &other)
{
   if (this != &other) // Verifica se a atribuicao e a dele mesmo
   {
        x = other->x;
        y = other->y;
   }
   return *this;
}