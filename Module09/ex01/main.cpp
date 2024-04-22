#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <climits>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " \"operation\"" << std::endl;
        return 1;
    }

    RPN calculator;
    int result = calculator.evaluate(av[1]);

    if (result != INT_MIN) {
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cerr << "Evaluation Error." << std::endl;
    }

    return 0;
}
