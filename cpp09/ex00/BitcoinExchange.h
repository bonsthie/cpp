#pragma once

#include "Date.h"
#include <map>
#include <stdint.h>
#include <string>

typedef std::map<Date, double> Market;

class BitcoinExchange {
  public:
    BitcoinExchange(std::string data_file);

  private:

	Market _market;
};
