#include <iostream>
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array
{
    private:
        long len;
        T* values;
    public:
        Array() {
            values = new T[0];
            len = 0;
        }

        Array(unsigned int n)
        {
            values = new T[n];
            len = n;
        }
        Array &operator=(T const &src) {
            len = src.len;
            delete [] values;
            for (unsigned i = 0; i < len, i++)
                values[i] = src.values[i];
            return (*this);
        };
        Array(Array const &src) {
            values = new T[src.len];
            *this = src;
        }
        T &operator[] (int index) {
            if (index >= len) {
                throw std::out_of_range("Index bigger than array len");
            }
            return values[index];
        }
        Array() {delete [] values;}
        int size() {return len;}

}

#endif