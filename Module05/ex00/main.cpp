#include "Bureaucrat.hpp"

void	test(std::string test_type, std::string name, int grade) {
	if (test_type == "range")
		std::cout << "Creating " << name << " with a grade of " << grade << ":\t";
	else if (test_type == "increment")
		std::cout << "Incrementing " << name << " (prev_grade = " << grade << "):\t";
	else if (test_type == "decrement")
		std::cout << "Decrementing " << name << " (prev_grade = " << grade << "):\t";
}

int	main() {
	std::string name;
	int			grade;

	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "           TESTING GRADE RANGES             " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	{
		try {
			name = "Bill";
			grade = 10;
			test("range", name, grade);
			Bureaucrat bill(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Alex";
			grade = 150;
			test("range", name, grade);
			Bureaucrat alex(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;;
		}

		try {
			name = "John";
			grade = -10;
			test("range", name, grade);
			Bureaucrat john(name, grade);
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Carl";
			grade = 151;
			test("range", name, grade);
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
			test("increment", name, grade);
			Bureaucrat bill(name, grade);
			bill.incrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Jack";
			grade = 1;
			test("increment", name, grade);
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
			test("decrement", name, grade);
			Bureaucrat bill(name, grade);
			bill.decrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}

		try {
			name = "Buck";
			grade = 150;
			test("decrement", name, grade);
			Bureaucrat jack(name, grade);
			jack.decrementGrade();
			std::cout << "✅" << std::endl;
		} catch (std::exception &e) {
			std::cout << "❌  --->  (" << e.what() << ")" << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}