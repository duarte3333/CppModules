#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
    (void)src;
    return *this;
}

void is_nan_or_inf(std::string scalar)
{
    if (scalar == "nan" || scalar == "nanf")
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (scalar == "inf" || scalar == "inff")
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (scalar == "-inf" || scalar == "-inff")
    {
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

bool is_digit_or_dot(char a){
    char str[12] = "0123456789.";
    int i = 0;

    while (str[i]) {
        if (str[i] == a) {
            return true;
        }
        i++;
    }
    return false;
}


void ScalarConverter::convert(std::string scalar) {
    if (scalar.empty()) {
        std::cout << "Conversion impossible" << std::endl;
        return;
    }
    else if (scalar.length() == 1 && !isdigit(scalar[0])) {
        std::cout << "char" << std::endl;
        convert_char(scalar);
    } 
    else if (scalar == "nan" || scalar == "nanf" || scalar == "inf" || scalar == "inff" || scalar == "-inf" || scalar == "-inff") {
        is_nan_or_inf(scalar);
    }
    else {

        if (is_digit_or_dot(scalar[0])) {
            convert_float(scalar);
        } 
        else {
            convert_int(scalar);
        }
    }
}

void ScalarConverter::convert_int(std::string scalar) {
    int i = std::atoi(scalar.c_str());
    std::cout << "int: " << i << std::endl;
    std::cout << "char: ";
    if (i < 32 || i > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    }
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convert_float(std::string scalar) {
    float f = std::atof(scalar.c_str());
    std::cout << "int: ";
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(f) << std::endl;
    }
    std::cout << "char: ";
    if (f < 32 || f > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convert_double(const std::string &scalar) {
    double d = std::strtod(scalar.c_str(), 0);
    std::cout << "int: ";
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }
    std::cout << "char: ";
    if (d < 32 || d > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }
    std::cout << "float: ";
    if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<float>(d) << "f" << std::endl;
    }
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert_char(std::string scalar) {
    char c = scalar[0];
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
