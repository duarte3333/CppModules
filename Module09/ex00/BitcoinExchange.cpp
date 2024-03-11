
#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype> //for std::isdigit()
#include <cstdlib> // std::stoi
#include <map>
#include <iomanip>
#include <iterator>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src)
    {
        _rate = src._rate;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int year_checker(const std::string& s){
    int i = 0;
    unsigned char current_char;
    while (i < static_cast<int>(s.size()) - 1)
    {
        current_char = static_cast<unsigned char>(s[i]);
        if ((i <= 3 && !std::isdigit(current_char)) \
            || ((i == 4 || i == 7) && s[i] != '-') \
            || ((i >= 5 && i <= 6) && !std::isdigit(current_char)) \
            || ((i >= 8 && i <= 9) && !std::isdigit(current_char)) \
            || (i == 10 && current_char == ' '))
        {
            std::cout << "Date not valid" << std::endl;
            return 0;
        }
        i++;
    }
    return 1;
}

double value_checker(const std::string& s){
    if (s.empty()) {
        std::cout << "Value not valid: string is empty" << std::endl;
        return 0;
    }

    std::string str_only_digits;
    int counter = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '.')
            counter++;
        if (s[i] == ' ')
            continue;
        else if (!std::isdigit(static_cast<unsigned char>(s[i])) && s[i] != '.' && s[i] != '+' && s[i] != '-') {
            std::cout << "Value not valid: contains non-digit characters" << std::endl;
            return 0;
        }
        else if (counter == 2){
            std::cout << "Value not valid: multiple dots" << std::endl;
            return 0;
        }
        else{
            str_only_digits.push_back(s[i]);
        }
    }
    double s_int = std::atof(str_only_digits.c_str());
    if (!(s_int >= 0 && s_int <= 1000))
    {
        std::cout << "Value not valid: out of range" << std::endl;
        return 0;
    }
    return s_int;
}

double BitcoinExchange::search_market(std::string date, double value){
    
    std::string new_date;
    for (size_t i = 0; i < date.size(); ++i){
        if (date[i] == ' ')
            continue;
        else {
            new_date.push_back(date[i]);
        }
    }
    std::map<std::string, double>::iterator it = this->market_values.lower_bound(new_date);
    // if (it == this->market_values.begin()){
    //     std::cout << "No lower date found" << std::endl;
    // }
    // if (it == this->market_values.end()){
    //     std::cout << "Anotha" << std::endl;
    // }
    //std::cout << "value: " << value << std::endl;
    //std::cout << "closer: "<< it->first << "," << it->second << std::endl;
    return (value)*(it->second);
}

void BitcoinExchange::parser(std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return ;
    }
    std::string line;
    char delimiter = '|';
    double value_cleaner;
    double market;
    while (std::getline(file, line)) {
        if (this->market_values.empty()){
                std::cout << "Error: Read the database first" << std::endl;
                break;
        }
        else {
            std::vector<std::string> tokens = split(line, delimiter);
            if (line != "date | value"){
                if (tokens.size() == 2) {
                    value_cleaner = value_checker(tokens[1]);
                    if (!year_checker(tokens[0])){
                        continue;
                    }
                    else if (!value_cleaner){
                        continue;
                    }
                    market = search_market(tokens[0], value_cleaner);
                    std::cout << tokens[0] << "=>" << tokens[1] << " == " << market << std::endl;
                }
                else {
                    std::cerr << "Unexpected format" << std::endl;
                }

            }

        }
    }
    file.close();
}

void BitcoinExchange::read_database(){
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(file, line)){
        if (line != "date,exchange_rate"){
            std::vector<std::string> tokens = split(line, ',');
            std::istringstream iss(tokens[1].c_str());
            double num;
            if (!(iss >> num)){
                std::cout << "Conversion failed" << std::endl;
            }
            else{
                this->market_values.insert(std::make_pair(tokens[0], num));
            }
            //std::cout << std::fixed << std::setprecision(10) << market_values[tokens[0]] << std::endl;
        }
    }
}



#endif
   