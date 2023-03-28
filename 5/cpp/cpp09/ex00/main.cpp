#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange bitcoinex;
	// std::fstream fs;


	if(argc != 2){
		std::cout << "Error: invalid arguments" << std::endl;
		return 0;
	}
	bitcoinex.checkCsvFile();
	bitcoinex.checkInputFile(argv[1]);
	bitcoinex.Bitcoin(argv[1]);

}
