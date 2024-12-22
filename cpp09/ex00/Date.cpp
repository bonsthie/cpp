#include <Date.h>
#include <FTregex>
#include <stdexcept>
#include <iostream>

Date::Date() { _date.raw = 0; }

Date::Date(const std::string &date) {
	_validDate(date, DEFAULT_DATE_PATTERN);
}

Date::Date(const std::string &date, const std::string &pattern) {
	_validDate(date, pattern);
}

void Date::_validDate(const std::string &date, const std::string &pattern) {
	try {
		FTregex reg(pattern);
		if (reg.captureGroupSize() != 3)
			throw std::invalid_argument(INVALID_DATE_PATTERN(date));

		FTregMatch match = reg.match(date);

		std::cout << match[0] << std::endl;
		std::cout << match[1] << std::endl;
		std::cout << match[2] << std::endl;
		std::cout << match[3] << std::endl;

	} catch (FTregex::regex_err &) {
		throw std::invalid_argument(INVALID_DATE_PATTERN(date));
	}

}

bool Date::operator>(const Date &ref) const {
    return _date.raw > ref._date.raw;
}
bool Date::operator<(const Date &ref) const {
    return _date.raw < ref._date.raw;
}
bool Date::operator>=(const Date &ref) const {
    return _date.raw >= ref._date.raw;
}
bool Date::operator<=(const Date &ref) const {
    return _date.raw <= ref._date.raw;
}
bool Date::operator==(const Date &ref) const {
    return _date.raw == ref._date.raw;
}
bool Date::operator!=(const Date &ref) const {
    return _date.raw != ref._date.raw;
}

