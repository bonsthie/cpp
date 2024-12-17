#include "ScalarConverter.h"
#include "log.h"
#include <cerrno>
#include <cmath>
#include <cstdlib>

ScalarConverter::ScalarConverter(void){LOG("constructor ScalarConverter empty")}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    LOG("constructor ScalarConverter copy")
    if (this != &src)
        *this = src;
}

ScalarConverter::~ScalarConverter(void) { LOG("destructor ScalarConverter") }

int isNaN(const std::string &str) {
    return (str == "nan" || str == "nanf" || str == "-inf" || str == "-inff" ||
            str == "+inf" || str == "+inff" || str == "inf" || str == "inff");
}

ScalarType getStringType(const std::string &str) {

    char       *error;
    std::string test;

    if (isNaN(str))
        return (TYPE_NAN);

    if (str.length() == 1 && !isdigit(str[0]))
        return (TYPE_CHAR);

    (void)strtol(str.c_str(), &error, 10);
    if (*error == 0)
        return (error - str.c_str() < 11 ? TYPE_INT : TYPE_UNKNOW);
    double val = strtod(str.c_str(), &error);
    if (*error == 0)
        return (TYPE_DOUBLE);

    if ((*error == 'f' && *(error + 1) == 0) &&
        std::fabs(val) <= std::numeric_limits<float>::max())
        return (TYPE_FLOAT);
    return (TYPE_UNKNOW);
}

void __convert_unknow(const std::string &str) {
    std::cout << str << " does not convert to any type" << std::endl;
}

void __convert_nan(const std::string &str) {
    std::string input;

    if (str[0] == 'n')
        input = "nan";
    else if (str[0] == '-')
        input = "-inf";
    else
        input = "+inf";

    std::cout << "char: impossible!\n";
    std::cout << "int: impossible!\n";
    std::cout << "float: " << input << "f\n";
    std::cout << "double: " << input << std::endl;
}

void ScalarConverter::convert(const std::string &str) {

    void (*convertFunc[])(const std::string &) = {
        &__convert<char>,   &__convert<int>, &__convert<float>,
        &__convert<double>, &__convert_nan,  &__convert_unknow};

    ScalarType type = getStringType(str);
    convertFunc[type](str);
}

template <> char strToType<char>(const std::string &str) { return (str[0]); }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
    return (*this);
}
