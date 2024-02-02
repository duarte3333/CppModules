#ifndef FORM_HPP
#define FORM_HPP
#include "string"
#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private:
        std::string const name;
        bool is_signed;
        int const gradeToSign;
        int const gradeToExecute;
        AForm();

    public:
        AForm(std::string const &name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        virtual ~AForm();

        std::string const &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSignedGrade() const;
        void beSigned(Bureaucrat const &bureaucrat);
        
        void execute(Bureaucrat const & executor) const;
        virtual void specificExecuteForm() const = 0;   

        class NotSignedException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif