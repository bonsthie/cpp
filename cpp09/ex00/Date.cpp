#include <Convert.h>
#include <Date.h>
#include <FTregex>
#include <stdexcept>

const int Date::_daysInMonth[13] = {0,  31, 29, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};

const std::string Date::_months[13] = {
    "",         
    "January",  
    "February", 
    "March",    
    "April",    
    "May",      
    "June",     
    "July",     
    "August",   
    "September",
    "October",  
    "November", 
    "December"  
};

Date::Date() { _date.raw = 0; }

Date::Date(const std::string &date) : _sep("-") {
    _validDate(date, DEFAULT_DATE_PATTERN);
}

Date::Date(const std::string &date, const std::string &sep) : _sep(sep) {
    _validDate(date, DATE_PATTERN(sep));
}

static bool isLeapYear(unsigned year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

void Date::_validDate(const std::string &date, const std::string &pattern) {
    try {
        FTregex reg(pattern);
        if (reg.captureGroupSize() != 3)
            throw std::invalid_argument(DATE_INVALID_CAPTURE_GROUPS);

        FTregMatch match = reg.match(date);

        _date.year = strToType<uint16_t>(match[1]);
        _date.month = strToType<uint8_t>(match[2]);
        _date.day = strToType<uint8_t>(match[3]);

        if (_date.month == 0 || _date.month > 12)
            throw std::invalid_argument(DATE_INVALID_MONTH);
		if (_date.day == 0 || _date.day > _daysInMonth[_date.month])
            throw std::invalid_argument(DATE_INVALID_DAY);
        if (_date.month == 2 && !isLeapYear(_date.year) && _date.day > 28)
            throw std::invalid_argument(DATE_INVALID_DAY);

    } catch (FTregex::regex_err &) {
        throw std::invalid_argument(INVALID_DATE_PATTERN(date, _sep));
    }
}

inline std::string Date::_day_error_msg() {
    unsigned maxDays = _daysInMonth[_date.month];
	bool leap = false;
    if (_date.month == 2 && isLeapYear(_date.year)) {
        maxDays = 29;
		leap = true;
    }

    std::ostringstream oss;
    oss << "DATE: Invalid day: Days can only range from 1 to " 
        << maxDays << " in " << _months[_date.month];
	if (leap == true)
		oss << " in leap year";
	oss << ".";
    return oss.str();
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
