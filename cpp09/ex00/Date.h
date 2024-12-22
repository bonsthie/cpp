#pragma once

#include <stdint.h>
#include <string>

#define DATE_PATTERN(sep)                                                      \
    "^([0-9]+)" + sep + "([0-9]{2})" + sep + "([0-9]{2})$"
#define DEFAULT_DATE_PATTERN DATE_PATTERN(std::string("-"))

#define INVALID_DATE_PATTERN(userInput, sep)                                   \
    "DATE: Invalid date format: expected 'YYYY" + sep + "MM" + sep +           \
        "DD', but got '" + userInput + "'."

#define DATE_INVALID_CAPTURE_GROUPS                                            \
    "DATE: Invalid pattern capture Groups: The pattern should have 3 capture " \
    "Groups."

#define DATE_INVALID_MONTH                                                     \
    "DATE: Invalid month : Months can only range from 1 to 12."

#define DATE_INVALID_DAY _day_error_msg()

class Date {
  public:
    Date();
    Date(const std::string &date);
    // the pattern is the regex use to pase the default is YYYY-MM-DD
    Date(const std::string &date, const std::string &sep);

    bool operator>(const Date &) const;
    bool operator<(const Date &) const;
    bool operator>=(const Date &) const;
    bool operator<=(const Date &) const;
    bool operator==(const Date &) const;
    bool operator!=(const Date &) const;

  private:
    void _validDate(const std::string &date, const std::string &pattern);
    inline std::string _day_error_msg();

    union {
        uint32_t raw;
        struct {
            uint16_t year;
            uint8_t  month;
            uint8_t  day;
        };
    } _date;
    const std::string _sep;

    static const int         _daysInMonth[13];
    static const std::string _months[13];
};
