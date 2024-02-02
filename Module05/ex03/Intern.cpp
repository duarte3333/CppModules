#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &other) {
    *this = other;
}

Intern &Intern::operator=(Intern const &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

Intern::~Intern() {
}


AForm *Intern::makePresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}


AForm *Intern::makeForm(std::string form_type, std::string target) {
	std::string forms[3] = { 
		"presidential pardon",
		"robotomy request",
		"shrubbery creation" };

	AForm *(Intern::*functions[3])(std::string target) = { 
		&Intern::makePresidential,
		&Intern::makeRobotomy,
		&Intern::makeShrubbery };

	for (int i = 0; i < 3; i++) {
		if (form_type == forms[i]) {
			std::cout << "    ✅ " << "Intern creates " << form_type;
			return (this->*functions[i])(target);
		}
	}

	std::cout << "    ❌ \"" << form_type << "\" is not a valid form type";
	return NULL;
}