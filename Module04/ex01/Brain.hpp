#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain(); //Constructor
        ~Brain(); //Destructor
        Brain(const Brain &other); //Copy constructor
        Brain& operator=(const Brain &other); //Copy assign operator
};

#endif