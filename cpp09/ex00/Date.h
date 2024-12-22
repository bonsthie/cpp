#pragma once

#include <stdint.h>
#include <string>

#define DATE_PATTERN(sep) "^([1-9][0-9]{3})"sep"([0-9]{2})"sep"([0-9]{2})$"
#define DEFAULT_DATE_PATTERN DATE_PATTERN("-")

#define INVALID_DATE_PATTERN(userInput)                                        \
    "DATE: Invalid date format: expected 'YYYY-MM-DD', but got '" + userInput + "'."

#define INVALID_CAPTURE_GROUPS "DATE: Invalid pattern capture Groups: The pattern should have 3 capture Groups"

class Date {
  public:
    Date();
    Date(const std::string &date);
	// the pattern is the regex use to pase the default is YYYY-MM-DD
    Date(const std::string &date, const std::string &pattern);

    bool operator>(const Date &) const;
    bool operator<(const Date &) const;
    bool operator>=(const Date &) const;
    bool operator<=(const Date &) const;
    bool operator==(const Date &) const;
    bool operator!=(const Date &) const;

  private:
    void _validDate(const std::string &date, const std::string &pattern);

    union {
        uint32_t raw;
        struct {
            uint16_t year;
            uint8_t  month;
            uint8_t  day;
        };
    } _date;
};
