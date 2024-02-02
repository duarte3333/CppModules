#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();

        void specificExecuteForm() const;
};