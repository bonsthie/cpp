#include <Convert.h>
#include <Date.h>
#include <FTregex>
#include <ctime>
#include <iomanip>
#include <locale>
#include <stdexcept>
#include <stdint.h>

const uint32_t Date::_daysInMonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const std::string Date::_months[13] = {"",        "January",  "February", "March",  "April",
                                       "May",     "June",     "July",     "August", "September",
                                       "October", "November", "December"};

Date::Date() : _sep(DEFAULT_SEP) { _date.raw = 0; }

Date::Date(const std::string &date) : _sep(DEFAULT_SEP) { _validDate(date, DEFAULT_DATE_PATTERN); }

Date::Date(const std::string &date, const std::string &sep) : _sep(sep) {
    _validDate(date, DATE_PATTERN(sep));
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << _date.year << _sep << std::setfill('0') << std::setw(2) << (uint32_t)_date.month << _sep
        << std::setfill('0') << std::setw(2) << (uint32_t)_date.day;
    return oss.str();
}

uint32_t Date::getRaw() const { return _date.raw; }

static bool isLeapYear(unsigned year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

void Date::_validDate(const std::string &date, const std::string &pattern) {
    try {
        FTregex reg(pattern);
        if (reg.captureGroupSize() != 3)
            throw std::invalid_argument(DATE_INVALID_CAPTURE_GROUPS);

        FTregMatch match = reg.match(date);

        uint32_t year = strToType<uint32_t>(match[1]);
        uint32_t month = strToType<uint32_t>(match[2]);
        uint32_t day = strToType<uint32_t>(match[3]);

        _date.year = year;
        _date.month = month;
        _date.day = day;

        if (month == 0 || month > 12)
            throw std::invalid_argument(DATE_INVALID_MONTH);
        if (day == 0 || day > _daysInMonth[month])
            throw std::invalid_argument(DATE_INVALID_DAY);
        if (month == 2 && !isLeapYear(year) && day > 28)
            throw std::invalid_argument(DATE_INVALID_DAY);

    } catch (FTregex::regex_err &) {
        throw std::invalid_argument(INVALID_DATE_PATTERN(date, _sep));
    }
}

std::string Date::_getLocalizedMonthName(unsigned month) {
    if (month < 1 || month > 12) {
        throw std::out_of_range("Month must be in the range 1 to 12");
    }

	try {
		const std::locale &loc = std::locale("");

		std::ostringstream oss;
		oss.imbue(loc); // Use the given locale
		std::tm timeStruct = {};
		timeStruct.tm_mon = month - 1;
		timeStruct.tm_mday = 1;
		std::use_facet<std::time_put<char> >(loc).put(oss, oss, ' ', &timeStruct, 'B');
		return oss.str();
	}
	catch (const std::runtime_error &e) {
		return _months[month];
	}
}

inline std::string Date::_day_error_msg() {
    unsigned maxDays = _daysInMonth[_date.month];
    bool     leap = false;
    if (_date.month == 2 && isLeapYear(_date.year)) {
        maxDays = 29;
        leap = true;
    }

    std::ostringstream oss;
    oss << "DATE: Invalid day: Days can only range from 1 to " << maxDays << " in "
        << _getLocalizedMonthName(_date.month)
		<< (leap ? " in a leap year." : ".");
    return oss.str();
}

bool Date::operator>(const Date &ref) const { return _date.raw > ref._date.raw; }
bool Date::operator<(const Date &ref) const { return _date.raw < ref._date.raw; }
bool Date::operator>=(const Date &ref) const { return _date.raw >= ref._date.raw; }
bool Date::operator<=(const Date &ref) const { return _date.raw <= ref._date.raw; }
bool Date::operator==(const Date &ref) const { return _date.raw == ref._date.raw; }
bool Date::operator!=(const Date &ref) const { return _date.raw != ref._date.raw; }

std::ostream &operator<<(std::ostream &os, const Date &d) {
    os << d.toString();
    return os;
}
