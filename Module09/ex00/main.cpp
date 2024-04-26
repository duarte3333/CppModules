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
        if (exchange.mini_parser_database() == 0) {
            std::cout << "Database parsing error" << std::endl;
            return 0;
        }
        exchange.read_database();
        exchange.parser(filename);
    }
    else {
        std::cout << "Usage: ./btc filename" << std::endl;
    }
    return 0;
}
