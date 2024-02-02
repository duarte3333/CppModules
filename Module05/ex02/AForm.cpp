/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duarte33 <duarte33@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:24:09 by duarte33          #+#    #+#             */
/*   Updated: 2024/02/02 19:02:27 by duarte33         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("default"), is_signed(false), gradeToSign(1), gradeToExecute(1) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute): name(name), is_signed(false),
                                                                         gradeToSign(gradeToSign),
                                                                         gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();

}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->is_signed = other.is_signed;
    return *this;
}

AForm::AForm(const AForm &other): name(other.name), is_signed(other.is_signed), gradeToSign(other.gradeToSign),
                               gradeToExecute(other.gradeToExecute){
    *this = other;
}

AForm::~AForm() {}

std::string const &AForm::getName() const {
    return this->name;
}

bool AForm::getSignedGrade() const {
    return this->is_signed;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    //1 higher grade, 150 lower grade
    //burecrat grade < grade to sign -> sign
    if (bureaucrat.getGrade() > getGradeToSign())
        throw AForm::GradeTooLowException();
    else
        this->is_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::NotSignedException::what() const throw() {
    return "Form not signed";
}

void AForm::execute(const Bureaucrat &executor) const{
    if (!getSignedGrade())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        this->specificExecuteForm();
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << " is ";
    if (!form.getGradeToSign())
        out << "not ";
    out << "is_signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}
