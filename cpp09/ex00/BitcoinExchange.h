#pragma once

#include "Date.h"
#include <map>
#include <stdint.h>

#define BTC_DATA "data.csv"

typedef std::map<Date, double> Market;

class BitcoinExchange {
  public:
    BitcoinExchange(void);

	float getBtcPrice(const Date &date);

	void addDataCsv(const char *csv);

  private:

	Market _market;
};
