#ifndef FORM_HPP
#define FORM_HPP
#include "string"
#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    private:
        std::string const name;
        bool is_signed;
        int const gradeToSign;
        int const gradeToExecute;
        Form();

    public:
        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();

        std::string const &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSignedGrade() const;
        void beSigned(Bureaucrat const &bureaucrat);

        class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif