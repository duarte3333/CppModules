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

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: " << av[0] << " \"operation\"" << std::endl;
        return 1;
    }

    std::string input = av[1]; // Use the input string directly
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;

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
    for (size_t i = 0; i + 2 < tokens.size(); flag? i += 2 : i += 3) {
        int n1;
        int n2;
        char opp;
        if (!flag) {
            n1 = std::stoi(tokens[i]);
            n2 = std::stoi(tokens[i + 1]);
            opp = tokens[i + 2][0];
            flag = 1;
        }
        else {
            n1 = sum;
            n2 = std::stoi(tokens[i]);
            opp = tokens[i + 1][0];
        }
        int op_result = operation(n1, n2, opp);
        if (op_result == INT_MIN) { // Check for operation error
            std::cout << "Error in operation." << std::endl;
            return 1;
        }
        sum += op_result;
    }

    std::cout << "SUM: " << sum << std::endl;

    return 0;
}
