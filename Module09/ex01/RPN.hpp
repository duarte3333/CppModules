#ifndef RPN_HPP
#define RPN_HPP

#include <vector>
#include <string>

class RPN {
public:
    RPN(); // Constructor
    ~RPN(); // Destructor
    int evaluate(const std::string& input);

private:
    int operation(int nb1, int nb2, char op);
    bool safe_stoi(const std::string& str, int& out);
    static void print_tokens(const std::vector<std::string>& tokens);
};

#endif
