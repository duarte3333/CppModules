#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype> //for std::isdigit()
#include <cstdlib> // std::stoi
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac == 2) {
        std::string filename = av[1];
        BitcoinExchange exchange;
        exchange.read_database();
        exchange.parser(filename);
    }
    else {
        std::cout << "Usage: ./a.out filename" << std::endl;
    }
    return 0;
}
