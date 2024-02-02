#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src) {
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {
    if (this != &src) {
        _target = src._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::specificExecuteForm() const {
    std::cout << "Bzzzzzz Bzzzzzz Bzzzzzz" << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << _target << " robotomization failed" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &src) {
    os << src.getName() << " form with grade " << src.getGradeToSign() << " to sign and " << src.getGradeToExecute() << " to execute";
    return os;
}

