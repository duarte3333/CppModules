#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include "iostream"
#include "iomanip"
#include "string"

class Fixed
{
    private:
        int         fixed;
        static int  fractional;
    public:
        Fixed(); //Default constructor
        Fixed(int const raw); //New constructor
        Fixed(float const raw); //New constructor
        Fixed(const Fixed &other); //Copy constructor
	    ~Fixed(void); //Destructor
	    Fixed& operator=(const Fixed& other); //Copy Assignment Operator
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

#endif