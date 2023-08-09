#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP
#include "iostream"
#include "iomanip"
#include "string"
#include "cmath"


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
        
        //Comparison operators
	    Fixed& operator=(const Fixed& other); //Copy Assignment Operator
        bool operator<(const Fixed &other) const;
        bool operator>(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        //Arithmetic operators
        Fixed   operator+(const Fixed &fixed) const;
        Fixed   operator-(const Fixed &fixed) const;
        Fixed   operator*(const Fixed &fixed) const;
        Fixed   operator/(const Fixed &fixed) const;

        //Increment's and decrement's
        Fixed   &operator++(); //pre-increment
        Fixed   &operator--(); //pre-decrement
        Fixed   operator++(int); //post-increment
        Fixed   operator--(int); //post-decrement

        static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

        //Member functions        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif