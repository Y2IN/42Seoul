#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>


#define Max 2147483647
class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange & operator=(BitcoinExchange const &);
	public:
		~BitcoinExchange();
		void	init_csv();
};

#endif
