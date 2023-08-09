#pragma once
#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point(); //Default constructor
        ~Point(); //Destructor
        Point (const Point &other); //Copy constructor
        Point& operator=(const Point &other); //Copy assignment operator overload
}

#endif