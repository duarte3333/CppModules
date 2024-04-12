#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Include for std::istringstream
#include <climits>

int operation(int nb1, int nb2, char op) {
    switch (op) {
        case '+': return (nb1 + nb2);
        case '-': return (nb1 - nb2);
        case '*': return (nb1 * nb2);
        case '/': return (nb1 / nb2); 
        default: return INT_MIN; // Use INT_MIN to indicate an error
    }
}

void print_tokens(const std::vector<std::string> &tokens) {
    for (const std::string &token : tokens) {
        std::cout << token << std::endl;
    }
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: " << av[0] << " \"operation\"" << std::endl;
        return 1;
    }

    std::string input = av[1]; // Use the input string directly
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;
    int op_result;

    // Split the input string by spaces
    while (iss >> token) {
        tokens.push_back(token);
    }

    // Now, tokens contains all parts of the operation
    if (tokens.size() < 3) { // Ensure there are enough parts for an operation
        std::cout << "Not enough input for an operation." << std::endl;
        return 1;
    }

    int sum = 0;
    int flag = 0;
    // Process each operation in the input
    int j = 3;
    for (size_t i = 0; i < tokens.size();) {
        std::cout << "size: " << tokens.size() << std::endl;

        //std::cout << "j: " << j << std::endl;
        int n1;
        int n2;
        char opp;
        std::cout << "i: " << i << std::endl;
        if (!flag) { //first iteration
            n1 = std::stoi(tokens[i]);
            std::cout << "n1: " << n1 << std::endl;
            n2 = std::stoi(tokens[i + 1]);
            std::cout << "n2: " << n2 << std::endl;
            opp = tokens[i + 2][0];
            std::cout << "opp: " << opp << std::endl;
            flag = 1;
            std::cout << "flag is 1" << std::endl;
            print_tokens(tokens);
        }
        else {
            n1 = op_result;
            std::cout << "sum: " << n1 << std::endl;
            n2 = std::stoi(tokens[i]);
            std::cout << "n2: " << n2 << std::endl;
            opp = tokens[i + 1][0];
            std::cout << "opp: " << opp << std::endl;
            flag = 2;
            std::cout << "flag is 2" << std::endl;
        }
        op_result = operation(n1, n2, opp);
        std::cout << "op_result: " << op_result << std::endl;
        if (op_result == INT_MIN) { // Check for operation error
            std::cout << "Error in operation." << std::endl;
            return 1;
        }
        //std::cout << "i final: " << i << std::endl;
        sum += op_result;
        std::cout << "NEW ITER" << std::endl;
        if (flag == 1)
            i += 3;
        if (flag == 2)
            i += 2;
    }

    std::cout << "SUM: " << op_result << std::endl;
    return 0;
}
