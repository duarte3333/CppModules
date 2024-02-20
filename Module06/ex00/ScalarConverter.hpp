#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "string"
#include "iostream"
#include "cstdlib"
#include <sstream>
#include <cmath>
#include "limits"
#include "iomanip"

class ScalarConverter {
private:
    static void convert_int(std::string scalar);
    static void convert_float(std::string scalar);
    static void convert_double(const std::string& scalar);
    static void convert_char(std::string scalar);
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
public:
    ~ScalarConverter();
    static void convert(std::string);
};


#endif