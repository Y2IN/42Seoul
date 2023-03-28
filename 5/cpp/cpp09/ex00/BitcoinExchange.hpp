#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>


#define Max 2147483647
class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
	public:
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange &operator=(BitcoinExchange const &);
		BitcoinExchange();
		~BitcoinExchange();
		void	checkCsvFile();
		void	checkInputFile(char *file);
		void	Bitcoin(char *file);
		void	checkInfo(std::string);
		int		checkDate(const std::string);
};

#endif
