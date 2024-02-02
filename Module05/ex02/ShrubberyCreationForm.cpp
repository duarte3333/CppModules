#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::specificExecuteForm() const {
    std::ofstream file((this->_target + "_shrubbery").c_str());
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      | |      " << std::endl;
    file << "      | |      " << std::endl;
    file << "      | |      " << std::endl;
    file << "      | |      " << std::endl;
    file << "      | |      " << std::endl;
    file << "      | |      " << std::endl;
    file << "      | |      " << std::endl;
    file << "      | |      " << std::endl;
    file.close();
}