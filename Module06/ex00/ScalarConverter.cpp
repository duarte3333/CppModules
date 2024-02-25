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
    while (i < 12) {
        if (str[i] == a) {
            return true;
        }
        i++;
    }
    return false;
}


void ScalarConverter::convert(std::string s) {
    if (s.empty())
        return;
    if (s.length() == 1 && !isdigit(s[0])) {
        convert_char(s);
        return;
    }
    std::string s2 = (s[0] == '-' || s[0] == '+') ? s.substr(1) : s;
    if (s2 == "nan" || s2 == "nanf" || s2 == "inf" || s2 == "inff" || s2 == "-inf" || s2 == "-inff") {
        is_nan_or_inf(s2);
        return;
    }

    //Int
    bool isInteger = true;
    for (size_t i = 0; i < s2.length(); ++i) {
        if (!isdigit(s2[i])) {
            isInteger = false;
            break;
        }
    }
    if (isInteger) {
        convert_int(s2);
        return;
    }

    //Double
    bool isDouble = true;
    bool hasDecimal = false;
    for (size_t i = 0; i < s2.length(); ++i) {
        if (!isdigit(s2[i])) {
            if (s2[i] == '.') {
                if (hasDecimal) {
                    isDouble = false; // More than one decimal point
                    break;
                }
                hasDecimal = true;
            } else {
                isDouble = false;
                break;
            }
        }
    }
    if (isDouble) {
        convert_double(s2);
        return;
    }

    //Float
    bool isFloat = true;
    bool hasF = false;
    hasDecimal = false;
    for (size_t i = 0; i < s2.length(); ++i) {
        if (!isdigit(s2[i])) {
            if (s2[i] == '.') {
                if (hasDecimal) {
                    isFloat = false; // More than one decimal point
                    break;
                }
                hasDecimal = true;
            } else if (s2[i] == 'f') {
                if (hasF || i != s2.length() - 1) {
                    isFloat = false; // More than one 'f' or 'f' is not the last character
                    break;
                }
                hasF = true;
            } else {
                isFloat = false;
                break;
            }
        }
    }
    if (isFloat) {
        convert_float(s2);
        return;
    }
    std::cout << "impossible" << std::endl;
}


void ScalarConverter::convert_int(std::string scalar) {
    int i = std::atoi(scalar.c_str());

    if (i < 32 || i > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convert_float(std::string scalar) {
    float f = static_cast<float>(std::atof(scalar.c_str()));
    float temp;
    float fractionalPart = modff(f, &temp);
    int nb_precision = scalar.find('.') == std::string::npos ? 0 : scalar.length() - scalar.find('.') - 2;
    std::string decimal = fractionalPart == 0 ? ".0" : "";

    if (scalar == "nanf" || scalar == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << scalar << std::endl;
        std::cout << "double: " << scalar.substr(0, scalar.length() - 1) << std::endl;
        return;
    }
    if (f < 32 || f > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(f) << std::endl;
    }
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout <<  std::fixed << std::setprecision(nb_precision) << "float: " << f << decimal << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << decimal << std::endl;
}

void ScalarConverter::convert_double(const std::string& scalar) {
    double d = std::strtod(scalar.c_str(), 0);
    double temp;
    double fractionalPart = modf(d, &temp);
    int precision = scalar.find('.') == std::string::npos ? 0 : scalar.length() - scalar.find('.') - 1;
    std::string decimal = fractionalPart == 0 ? ".0" : "";

    if (scalar == "nan" || scalar == "inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << scalar << "f" << std::endl;
        std::cout << "double: " << scalar << std::endl;
        return;
    }
    if (d < 32 || d > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(d) << std::endl;
    }
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "float: " << static_cast<float>(d) << decimal << "f" << std::endl;
    std::cout << "double: " << d << decimal << std::endl;
}

void ScalarConverter::convert_char(std::string scalar) {
    char c = scalar[0];
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
