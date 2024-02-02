#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form; 

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        //Constructor and Destructors
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();

        //Getters
        std::string const &getName() const;
        int getGrade() const;
        //Member functions
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);

        //Dynamic Exceptions
        class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw(); 
            //the what() does not throw any exceptions itself
            //virtual made possible to override the method
            //const means that is not going to change the object
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif