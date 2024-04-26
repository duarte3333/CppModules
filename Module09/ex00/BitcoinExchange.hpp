#include <string>
#include <iostream>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &src);
    void parser(std::string &file);
    void read_database();
    double search_market(std::string date, double value);
    int mini_parser_database();

private:
    float _rate;
    std::map<std::string, double> market_values;
};