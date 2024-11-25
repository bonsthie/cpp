#include "ScalarConverter.h"
#include "log.h"

ScalarConverter::ScalarConverter(void){LOG("constructor ScalarConverter empty")}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    LOG("constructor ScalarConverter copy")
    if (this != &src)
        *this = src;
}

ScalarConverter::~ScalarConverter(void){LOG("destructor ScalarConverter")}


void convert(const std::string &str)
{
	/* getType(); */

}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
    if (this == &src)
        return (*this);
    return (*this);
}
