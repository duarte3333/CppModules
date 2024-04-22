#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <climits>

RPN::RPN() {}
RPN::~RPN() {}

int RPN::evaluate(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    if (tokens.size() < 3) {
        std::cerr << "Not enough input for an operation." << std::endl;
        return INT_MIN;
    }

    int op_result = 0;
    int flag = 0;
    std::istringstream converter;

    for (size_t i = 0; i < tokens.size();) {
        int n1, n2;
        char opp;

        if (!flag) {
            if (!safe_stoi(tokens[i], n1) || !safe_stoi(tokens[i + 1], n2)) return INT_MIN;
            opp = tokens[i + 2][0];
            flag = 1;
        } else {
            n1 = op_result;
            if (!safe_stoi(tokens[i], n2)) return INT_MIN;
            opp = tokens[i + 1][0];
            flag = 2;
        }

        op_result = operation(n1, n2, opp);
        if (op_result == INT_MIN) {
            return INT_MIN;
        }

        if (flag == 1) i += 3;
        if (flag == 2) i += 2;
    }

    return op_result;
}

int RPN::operation(int nb1, int nb2, char op) {
    switch (op) {
        case '+': return nb1 + nb2;
        case '-': return nb1 - nb2;
        case '*': return nb1 * nb2;
        case '/':
            if (nb2 == 0) {
                std::cerr << "Error: Division by zero." << std::endl;
                return INT_MIN;
            }
            return nb1 / nb2;
        default:
            std::cerr << "Error: Unknown operation." << std::endl;
            return INT_MIN;
    }
}

bool RPN::safe_stoi(const std::string& str, int& out) {
    std::istringstream iss(str);
    return !(iss >> out).fail();
}

void RPN::print_tokens(const std::vector<std::string>& tokens) {
    for (std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
