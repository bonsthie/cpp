#include "ScalarConverter.h"
#include "log.h"

ScalarConverter::ScalarConverter(void){LOG("constructor ScalarConverter empty")}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
  LOG("constructor ScalarConverter copy")
  if (this != &src)
    *this = src;
}

ScalarConverter::~ScalarConverter(void){LOG("destructor ScalarConverter")}

ScalarType getStringType(const std::string &str) {
  (void)str;
  return (TYPE_INT);
}

void ScalarConverter::convert(const std::string &str) {

  void (*convertFunc[])(const std::string &) = {
      &__convert<char>,
      &__convert<int>,
      &__convert<float>,
      &__convert<double>
  };

  ScalarType type = getStringType(str);

  if (type == TYPE_UNKNOW) 
    std::cout << "err need to manage" << std::endl;
  else
	  convertFunc[type](str);
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}
