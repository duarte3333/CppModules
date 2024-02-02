#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();

        void specificExecuteForm() const;
};