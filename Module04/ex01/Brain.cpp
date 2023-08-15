#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other){
    *this = other;
}

Brain& Brain::operator=(const Brain& other){
    if (this != &other)
    {
        for (int i = 0 ; i < 100; i++){
            ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}

void    Brain::setIdea(std::string idea, int index){
    ideas[index] = idea;
}

void	Brain::showIdea(int index){
    std::cout <<  ideas[index] << std::endl;
}
