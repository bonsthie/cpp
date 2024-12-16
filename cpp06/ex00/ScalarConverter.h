#pragma once

#include <cctype>
#include <iostream>
#include <limits.h>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
public:
  ScalarConverter(void);
  ~ScalarConverter(void);

  static void convert(const std::string &str);

  ScalarConverter &operator=(ScalarConverter const &src);
private:
  ScalarConverter(const ScalarConverter &ref);
};

enum ScalarType {
  TYPE_CHAR,
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_NAN,
  TYPE_UNKNOW,
};

template <typename T> void convertToChar(T value) {
  std::cout << "char : ";
  if (value > CHAR_MAX || value < CHAR_MIN)
    std::cout << "impossible!";
  else if (!isprint(value))
    std::cout << "Non displayable";
  else
    std::cout << '\'' << static_cast<char>(value) << '\'';
  std::cout << std::endl;
}

template <typename T> void convertToInt(T value) {
  std::cout << "int : ";
  if (value > std::numeric_limits<int>::max() ||
      value < std::numeric_limits<int>::min())
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

template <typename T> T strToType(const std::string &str) {
  std::stringstream ss(str);
  T result;
  ss >> result;
  return result;
}

template <>
char strToType<char>(const std::string &str);

template <typename T> void __convert(const std::string &str) {
  T value = strToType<T>(str);
  convertToChar(value);
  convertToInt(value);
  convertToFloat(value);
  convertToDouble(value);
}
