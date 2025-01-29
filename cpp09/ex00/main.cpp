#include "BitcoinExchange.h"
#include <Convert.h>
#include <Date.h>
#include <FTregex.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#define WALLET_FORMAT "^([^|]*) \\| ([-+]?[0-9]+(\\.[0-9]+)?)\n?$"

static void compute_line(const std::string &line, BitcoinExchange &market,
                         const FTregex &reg) {
    try {
        FTregMatch matches = reg.match(line);
        Date       date(matches[1]);
        float      price = market.getBtcPrice(date);

        float btc = strToType<float>(matches[2]);
        if (btc < 0)
            throw std::runtime_error("not a positive number.");
        if (btc > 1000)
            throw std::runtime_error("too large a number.");
        std::cerr << date << " => " << btc << " = " << btc * price << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << " [" << line << "]" << std::endl;
    }
}

int main(int ac, char **av) {
    if (ac != 2)
	{
		std::cerr << "Wrong arg" << std::endl; 
		return (1);
	}

    try {
        BitcoinExchange market;

        std::ifstream data(av[1]);
        if (data.is_open() == false)
            throw std::runtime_error("User data : could not open the user wallet file");

        FTregex     reg(WALLET_FORMAT);
        std::string line;
        while (std::getline(data, line)) {
            compute_line(line, market, reg);
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
