/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duarte33 <duarte33@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:24:09 by duarte33          #+#    #+#             */
/*   Updated: 2024/01/28 13:38:42 by duarte33         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("default"), is_signed(false), gradeToSign(1), gradeToExecute(1) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute): name(name), is_signed(false),
                                                                         gradeToSign(gradeToSign),
                                                                         gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();

}

Form &Form::operator=(const Form &other) {
    if (this != &other)
        this->is_signed = other.is_signed;
    return *this;
}

Form::Form(const Form &other): name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign),
                               gradeToExecute(other.gradeToExecute){
    *this = other;
}

Form::~Form() {}

std::string const &Form::getName() const {
    return this->name;
}

bool Form::getSignedGrade() const {
    return this->is_signed;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > getGradeToSign())
        throw Form::GradeTooLowException();
    else
        this->is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is ";
    if (!form.getGradeToSign())
        out << "not ";
    out << "is signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}
