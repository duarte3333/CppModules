#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <climits>

RPN::RPN() {}
RPN::~RPN() {}

int decide_flag(std::vector<std::string> tokens, int start) { //flag == 0, it's triple; flag == 1, it's double
    int counter = 0;
    for (size_t i = start; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            std::cout << "counter: " << counter << std::endl;
            return counter;
        }
        counter++;
    }
    return counter;
}

void print_stack(std::vector<int> stack) {
    for (size_t i = 0; i < stack.size(); i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

int RPN::evaluate(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    std::vector<int> stack;
    int op_result = 0;
    int n1, n2;

    for (size_t i = 0; i < tokens.size(); i++) {
        const std::string& token = tokens[i];
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                std::cerr << "Error: insufficient operands for operation " << token << std::endl;
                return INT_MIN;
            }
            n2 = stack.back(); stack.pop_back(); // get and pop last element of the stack
            n1 = stack.back(); stack.pop_back();
            op_result = operation(n1, n2, token[0]);
            if (op_result == INT_MIN) {
                return INT_MIN;
            }
            stack.push_back(op_result);
            //print_stack(stack);

        } 
        else {
            int number;
            if (!safe_stoi(token, number)) {
                std::cerr << "Error: invalid number " << token << std::endl;
                return INT_MIN;
            }
            stack.push_back(number);
            //print_stack(stack);

        }
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
