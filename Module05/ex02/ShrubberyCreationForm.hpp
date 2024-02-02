#ifndef CPP05_EX02_SHRUBBERYCREATIONFORM_HPP
#define CPP05_EX02_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string const &_target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        void specificExecuteForm() const;
};


#endif 