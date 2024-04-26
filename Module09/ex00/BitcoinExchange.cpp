
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
#include <climits>

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

int year_checker(const std::string& date){
    if (date[4] != '-' || date[7] != '-') return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 1000 || year > 9999) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false; 
    return true;
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

double BitcoinExchange::search_market(const std::string date, double value) {
    std::string new_date;
    for (std::string::const_iterator it = date.begin(); it != date.end(); ++it) {
        if (*it != ' ')
            new_date.push_back(*it);
    }
    // Search for the closest lower or equal date in the market values
    std::map<std::string, double>::iterator it = this->market_values.lower_bound(new_date);

    // Handle the case when the date is beyond any existing date in the database
    if (it == this->market_values.end()) {
        if (!this->market_values.empty()) {
            --it; 
            return value * it->second;
        } else {
            return INT_MIN; // Database has no entries
        }
    }
    if (it->first != new_date && it != this->market_values.begin()) {
        --it;
    }
    return value * it->second;
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
                        std::cout << "Error: Invalid date" << std::endl;
                        continue;
                    }
                    else if (!value_cleaner){
                        continue;
                    }
                    market = search_market(tokens[0], value_cleaner);
                    if (market != INT_MIN)
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

bool is_valid_number(const std::string& number) {
    for (size_t i = 0; i < number.length(); ++i) {
        if (!isdigit(number[i]) && number[i] != '.') return false;
    }
    return true;
}

int BitcoinExchange::mini_parser_database(){
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 0;
    }
    std::string line;
    while (std::getline(file, line)){
        if (line != "date,exchange_rate"){
            size_t commaPos = line.find(',');
            if (commaPos == std::string::npos) return false;

            std::string datePart = line.substr(0, commaPos);
            std::string numberPart = line.substr(commaPos + 1);
            if (datePart.empty() || numberPart.empty()) return false;
            if (datePart.length() != 10) return false;
            if (!year_checker(datePart))
            {
                return 0;
            }
            
            if(!is_valid_number(numberPart)) {
                return 0;
            }
        }
    }
    file.close();
    return 1;
}



#endif
   