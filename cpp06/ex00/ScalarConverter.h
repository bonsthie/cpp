#pragma once

#include <cctype>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>

enum ScalarType {
    ERR,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
};

class ScalarConverter {
  public:
    ScalarConverter(const ScalarConverter &ref);
    ScalarConverter(void);
    ~ScalarConverter(void);

    void convert(const std::string &str);

    ScalarConverter &operator=(ScalarConverter const &src);
};

template <typename T> void convertToChar(T value) {
    std::cout << "char : ";
    if (value > CHAR_MAX || value < CHAR_MIN)
        std::cout << "impossible!";
    else if (!isprint(value))
        std::cout << "Non displayable";
    else
        std::cout << static_cast<char>(value);
    std::cout << std::endl;
}

template <typename T> void convertToInt(T value) {
    std::cout << "int : ";
    if (value > INT_MAX || value < INT_MIN)
        std::cout << "impossible!";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

template <typename T> void convertToFloat(T value) {
    std::cout << "float : ";
    std::cout << std::fixed << static_cast<float>(value) << "f";
    std::cout << std::endl;
}

template <typename T> void convertToDouble(T value) {
    std::cout << "double : ";
    std::cout << std::fixed << static_cast<float>(value);
    std::cout << std::endl;
}

template <typename T>
T strToType(const std::string &str)
{
    std::stringstream ss(str);
    T result;
    ss >> result;
	return result;
}
