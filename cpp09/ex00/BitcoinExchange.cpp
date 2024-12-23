#include <BitcoinExchange.h>
#include <Convert.h>
#include <FTregex>
#include <fstream>
#include <stdexcept>

#define LINE_FORMAT "^([0-9]+-[0-9]{2}-[0-9]{2}),([0-9]+(\\.[0-9]+)?)\n?$"

BitcoinExchange::BitcoinExchange() {
    std::ifstream data(BTC_DATA);
    if (data.is_open() == false)
        throw std::runtime_error("BitcoinExchange : could not open the bitcoin data");

    FTregex     reg(LINE_FORMAT);
    std::string line;
    int         lineNumber = 2;
    std::getline(data, line);
    while (std::getline(data, line)) {
        try {

            FTregMatch match = reg.match(line);
            Date       date(match[1]);
            _market[date] = strToType<float>(match[2]);

        } catch (const std::exception &e) {

            std::ostringstream oss;
            oss << "BitcoinExchange: error on line " << lineNumber << " [" << e.what() << "]";
            throw std::runtime_error(oss.str());
        }
        lineNumber++;
    }
}

#include <iostream>
float BitcoinExchange::getBtcPrice(const Date &date) {
    Market::iterator it = _market.lower_bound(date);

    if (it != _market.begin() && (it == _market.end() || it->first > date)) {
        --it;
    }

    if (it == _market.end() || it->first > date) {
        return 0;
    }
    return it->second;
}
