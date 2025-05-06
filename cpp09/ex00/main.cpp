#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Error: could not open file." << std::endl;
	else
	{
		BitcoinExchange btc;
		std::string datacsv("data.csv");
	    std::map<std::string, float> bitcoinPrices = btc.readDataCsv(datacsv);
    	if (bitcoinPrices.empty()) {
        	std::cerr << "Error: could not load bitcoin price data." << std::endl;
        	return 1;
    	}
	    btc.readInputFile(av[1], bitcoinPrices);
	}
    return 0;
}

