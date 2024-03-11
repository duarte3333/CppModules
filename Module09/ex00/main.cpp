#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype> //for std::isdigit()
#include <cstdlib> // std::stoi

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

int value_checker(const std::string& s){
    if (s.empty()) {
        std::cout << "Value not valid: string is empty" << std::endl;
        return 0;
    }

    std::string str_only_digits;
    int counter = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '.')
            counter++;
        else if (s[i] == ' ')
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
    int s_int = std::atoi(str_only_digits.c_str());
    if (!(s_int >= 0 && s_int <= 1000))
    {
        std::cout << "Value not valid: out of range" << std::endl;
        return 0;
    }
    return 1;
}

int main() {
    
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    char delimiter = '|';
    while (std::getline(file, line)) {
        std::vector<std::string> tokens = split(line, delimiter);
        if (tokens.size() < 2)
        {
            std::cerr << "Unexpected format" << std::endl;
            continue;
        }
        else if (!year_checker(tokens[0]))
            continue;
        else if (!value_checker(tokens[1]))
            continue;
        //std::cout << tokens[1] << std::endl;
        market_value = search_value(tokens[0]);
        std::cout << tokens[0] << "=>" << tokens[1] "=" << market_value << std::endl;
    }
    file.close();
    return 0;
}
