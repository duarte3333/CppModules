#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime> // for timing
#include <iomanip> // for setw

void print_array(const std::vector<int>& array) {
    for (std::vector<int>::size_type i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void print_list(const std::list<int>& array) {
    for (std::list<int>::const_iterator it = array.begin(); it != array.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " <number> [...]" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;

    //fill vector array
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

    //fill list array
    std::list<int> list_array;
    for (int i = 1; i < ac; ++i) {
        std::stringstream iss(av[i]);
        int num;
        if (!(iss >> num) || num < 0) {
            std::cerr << "Error: Invalid input '" << av[i] << "'. Only positive integers are allowed." << std::endl;
            return 1;
        }
        list_array.push_back(num);
    }

    pmergeMe.sort_with_vector(array);

    std::cout << "Before: ";
    print_array(array);
    
    clock_t start_vector = clock();
    pmergeMe.sort_with_vector(array);
    clock_t end_vector = clock();

    std::cout << "After: ";
    print_array(array);
    std::cout << std::setw(40) << "Time taken to sort with vector: " << std::fixed << std::setprecision(10) << static_cast<double>(end_vector - start_vector) * 1000.0 / CLOCKS_PER_SEC << " milliseconds" << std::endl;

    std::cout << "Before: ";
    print_list(list_array);

    clock_t start_list = clock();
    pmergeMe.sort_with_list(list_array);
    clock_t end_list = clock();

    std::cout << "After: ";
    print_list(list_array);
    std::cout << std::setw(40) << "Time taken to sort with list: " << std::fixed << std::setprecision(10) << static_cast<double>(end_list - start_list) * 1000.0 / CLOCKS_PER_SEC << " milliseconds" << std::endl;

    return 0;
}
