#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& origin){
	this->_data = origin._data;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& origin)
{
	if (this != &origin) {
		this->_data = origin._data;
	}
	return(*this);
}

BitcoinExchange:: ~BitcoinExchange(){}

void BitcoinExchange::checkCsvFile(){
	std::ifstream csv("data.csv");
	std::string read;
	float n;
	size_t date_size;

	if(!csv)
	{
		std::cout <<"Error: could not open database file"<< std::endl;
		return ;
	}
	if (std::getline(csv, read).eof())
	{
		std::cerr << "File empty or no data in." << std::endl;
		return ;
	}
	while(std::getline(csv, read))
 	{
		if (read != "date,exchange_rate")
		{
			date_size = read.find(',');
			std::istringstream(read.substr(date_size + 1, read.length())) >> n;
			_data[read.substr(0, date_size)] = n;
		}
	}
}

void BitcoinExchange::checkInputFile(char *file)
{
	std::fstream fs;
	std::string str;

	fs.open(file, std::ifstream::in);
	if(!fs.is_open())
	{
		std::cout << "Error: could not open input file." << std::endl;
		return;
	}
	if (std::getline(fs, str).eof())
	{
		std::cout << "Error : File empty or no data in." << std::endl;
		return ;
	}
	if(str.compare("date | value") != 0)
	{
		std::cout  << "Error : File format error." << std::endl;
		return ;
	}
	str.erase();
	fs.close();
	return ;
}

void BitcoinExchange::Bitcoin(char *file)
{
	std::ifstream configfile(file);
	std::string read;

	while(getline(configfile, read))
		checkInfo(read);
}

void	BitcoinExchange::checkInfo(std::string info)
{
	// istringstream -> string을 입력 받아 공백을 기준으로 파싱하여 변수 형식에 맞게 변환
	std::string date, str;
	std::istringstream formats(info);
	float	value;
	int idx = 0;

	while (std::getline(formats, str, ' '))
    {
        if (idx == 0)
		{
			if (!checkDate(str)) //date
				return ;
			date = str;
		}
		if (idx == 1 && str != "|")
		{
			std::cout << "Error: bad input  => " << info << std::endl;
			return ;
		}
		if (idx == 2)
		{
			if (!checkValue(str))
				return ;
			std::istringstream(str) >> value;
			if (value > 1000)
			{
				std::cout << "Error: too large a number." <<std::endl;
				return ;
			}
		}
		idx++;
	}
	if (idx != 3)
	{
			std::cout << "Error: bad input => " << info << std::endl;
			return ;
	}
	//print
	printBit(date, value);
}

int BitcoinExchange::checkDate(const std::string dates)
{
	if (dates.size() != 10)
	{
		std::cout << "Error: incorrect date formate" << std::endl;
		return 0;
	}
	// if (dates.find('-', dates.length() - 1) != std::string::npos)
	// {
	// 	std::cout << "Error: incorrect date formate" << std::endl;
	// 	return 0;
	// } //
	std::string date_split;
	std::istringstream ss(date_split);
	int	year, month, day;
	int idx =0;
	while (std::getline(ss, date_split, '-'))
	{
		if (idx == 0)
		{
			std::istringstream(date_split) >> year;
			if (year >= 2009 && year <= 2022)
			{
				std::cout << "Error: invalid year." <<std::endl;
				return 0;
			}
		}
		if (idx == 1)
		{
			std::istringstream(date_split) >> month;
			{
				std::cout << "Error: invalid month." << std::endl;
				return 0;
			}
		}
	}

}
