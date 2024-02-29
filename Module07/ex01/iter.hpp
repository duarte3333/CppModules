#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *array, unsigned int lenght, void (*f)(const T &t)) {
    for (unsigned int i = 0; i < lenght; i++)
        f(array[i]);
}

#endif