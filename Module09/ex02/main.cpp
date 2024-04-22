#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <sstream>

void print_array(const std::vector<int>& array) {
    for (std::vector<int>::size_type i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " <number> [...]" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;
    std::vector<int> array;
    for (int i = 1; i < ac; ++i) {
        std::stringstream iss(av[i]);
        int num;
        if (!(iss >> num) || num < 0) {
            std::cerr << "Error: Invalid input '" << av[i] << "'. Only positive integers are allowed." << std::endl;
            return 1;
        }
        array.push_back(num);
    }
    std::cout << "Before: ";
    print_array(array);
    pmergeMe.sort(array);
    std::cout << "After: ";
    print_array(array);
    return 0;
}
