#pragma once

#include <map>
#include <stdint.h>
#include <string>

union date {
    uint32_t raw;
    struct {
        uint32_t year : 23;
        uint32_t month : 4;
        uint32_t day : 5;
    };
};

typedef std::map<date, double> Market;

class BitcoinExchange {
  public:
    BitcoinExchange(std::string data_file);
  private:

	Market _market;
};
