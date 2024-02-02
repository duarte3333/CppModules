#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


void	test(std::string test_type, std::string name, int grade, std::string form) {
	if (test_type == "b_range")
		std::cout << "Creating " << name << " with a grade of " << grade << ":\t";
	else if (test_type == "increment")
		std::cout << "Incrementing " << name << " (prev_grade = " << grade << "):\t";
	else if (test_type == "decrement")
		std::cout << "Decrementing " << name << " (prev_grade = " << grade << "):\t";
	else if (test_type == "signing")
		std::cout << "\n  Signing " << form << ", needs " << grade << " to sign:\n";
	else if (test_type == "executing")
		std::cout << "\n  Executing " << form << ", needs " << grade << " to execute:\n"; 
}

int	main() {
	std::string name;
	std::string target;
	int			grade;

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "           TESTING GRADE RANGES             " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Bill";
			grade = 10;
			test("b_range", name, grade, "(nil)");
			Bureaucrat bill(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Alex";
			grade = 150;
			test("b_range", name, grade, "(nil)");
			Bureaucrat alex(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;;
		}

		try {
			name = "John";
			grade = -10;
			test("b_range", name, grade, "(nil)");
			Bureaucrat john(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Carl";
			grade = 151;
			test("b_range", name, grade, "(nil)");
			Bureaucrat carl(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "          TESTING INCREMENTATION            " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Kate";
			grade = 10;
			test("increment", name, grade, "(nil)");
			Bureaucrat bill(name, grade);
			bill.incrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Jack";
			grade = 1;
			test("increment", name, grade, "(nil)");
			Bureaucrat jack(name, grade);
			jack.incrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "          TESTING DECREMENTATION            " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Anna";
			grade = 10;
			test("decrement", name, grade, "(nil)");
			Bureaucrat bill(name, grade);
			bill.decrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Buck";
			grade = 150;
			test("decrement", name, grade, "(nil)");
			Bureaucrat jack(name, grade);
			jack.decrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "       TESTING PRESIDENTIAL PARDON        " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Liam";
			grade = 10;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getSignedGrade(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }

		try {
			name = "Noah";
			grade = 2;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }

		try {
			name = "Anna";
			grade = 30;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }

		try {
			name = "Joce";
			grade = 6;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "          TESTING ROBOTOMY FORM           " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Doug";
			grade = 6;
			target = "Rudy";
			Bureaucrat burr(name, grade);
			RobotomyRequestForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Robotomy Request");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Robotomy Request");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }

		try {
			name = "Ryan";
			grade = 50;
			target = "Jack";
			Bureaucrat burr(name, grade);
			RobotomyRequestForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Robotomy Request");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Robotomy Request");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }

		try {
			name = "Luke";
			grade = 80;
			target = "Robo";
			Bureaucrat burr(name, grade);
			RobotomyRequestForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Robotomy Request");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Robotomy Request");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "          TESTING SHRUBBERY FORM          " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Ralf";
			grade = 140;
			target = "home";
			Bureaucrat burr(name, grade);
			ShrubberyCreationForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Shrubbery Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Shrubbery Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }

		try {
			name = "Adam";
			grade = 150;
			target = "irrelevant";
			Bureaucrat burr(name, grade);
			ShrubberyCreationForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Shrubbery Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Shrubbery Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }

		try {
			name = "Jade";
			grade = 80;
			target = "Robo";
			Bureaucrat burr(name, grade);
			ShrubberyCreationForm form(target);
			std::cout << "\033[0;34m" << burr << "\033[0m";
			test("signing", name, form.getGradeToSign(), "Shrubbery Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Shrubbery Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	}

	return 0;
}