#include <BitcoinExchange.h>
#include <Convert.h>
#include <FTregex.h>
#include <fstream>
#include <stdexcept>

// date | number
#define LINE_FORMAT "^([^|]*),([0-9]+(\\.[0-9]+)?)\n?$"

BitcoinExchange::BitcoinExchange() {
	addDataCsv(BTC_DATA);
}

void BitcoinExchange::addDataCsv(const char *csv) {
    std::ifstream data(csv);
    if (data.is_open() == false)
        throw std::runtime_error("BitcoinExchange : could not open the bitcoin data");

    FTregex     reg(LINE_FORMAT);
    std::string line;
    int         lineNumber = 2;

	// header parsing 
    std::getline(data, line);
	if (line.empty() || line.compare("date,exchange_rate"))
        throw std::runtime_error("BitcoinExchange : invalid data");

	// data parsing
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

	if (_market.empty())
        throw std::runtime_error("BitcoinExchange : no data Found");

}

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
