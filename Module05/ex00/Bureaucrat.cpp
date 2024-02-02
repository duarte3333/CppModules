#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(1) {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

//Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

//Copy assign operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this == &other)
        return *this;
    this->grade = other.grade;
    return *this;
}

//Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    *this = other;
}

//Destructor
Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

//1 is the higher , 150 is the lower
void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}
