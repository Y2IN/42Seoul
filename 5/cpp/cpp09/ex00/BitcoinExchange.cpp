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
		std::cout << "File empty or no data in." << std::endl;
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
		std::cout << "Error : could not open file." << std::endl;
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
	getline(configfile, read);
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
			if (checkDate(str) == 0)
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
			if (checkValue(str) == 0)
				return ;
			value = std::strtod(str.c_str(), NULL);
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
	printBit(date, value);
}

int BitcoinExchange::checkDate(const std::string &dates)
{
	std::string date_split;
	std::istringstream ss(dates);

	int	year, month, day;
	int idx = 0;


	if (dates.find('-', dates.length() - 1) != std::string::npos)
	{
		std::cout << "Error: incorrect date formate => " << dates << std::endl;
		return 0;
	}
	while (std::getline(ss, date_split, '-'))
	{
		if (idx == 0)
		{
			std::istringstream(date_split) >> year;
			if (year < 2009 || year > 2022)
			{
				std::cout << "Error: invalid year => " << dates <<std::endl;
				return 0;
			}
		}
		if (idx == 1)
		{
			std::istringstream(date_split) >> month;
			if (month < 1 || month > 12)
			{
				std::cout << "Error: invalid month => " << dates << std::endl;
				return 0;
			}
		}
		if (idx == 2)
		{
			std::istringstream(date_split) >> day;
			if (day < 1 || day > 31)
			{
				std::cout << "Error: bad input => " << dates << std::endl;
				return 0;
			}
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
			{
				std::cout << "Error: incorrect days => " << dates << std::endl;
				return 0;
			}
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			{
				if (day > 29 && month == 2)
				{
					std::cout << "Error: incorrect days => " << dates << std::endl;
					return 0;
				}
			}
			else if (day > 28 && month == 2)
			{
				std::cout << "Error: incorrect days => " << dates << std::endl;
				return 0;
			}
		}
		idx++;
	}
	if (idx != 3)
	{
		std::cout<<"Error : Wrong format => " << dates <<std::endl;
		return 0;
	}
	return 1;
}

int BitcoinExchange::checkValue(const std::string& str)
{
  	char *ptr = NULL;
	double value = std::strtod(str.c_str(), &ptr);
	if (str.find('.', 0) == 0 || str.find('.', str.length() - 1) != std::string::npos)
	{
		std::cout << "Error: not a Number" << std::endl;
		return 0;
	}
	if (value == 0.0 && !std::isdigit(str[0]))
	{
		std::cout << "Error: not a Number" << std::endl;
		return 0;
	}
	if (*ptr && std::strcmp(ptr, "f"))
	{
		std::cout << "Error: not a Number" << std::endl;
		return 0;
	}
  	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}
	if (str.length() > 10 || (str.length() == 10 && value > 2147483647))
	{
		std::cout << "Error: too large a number."<< std::endl;
		return 0;
	}
  	return 1;
}

void	BitcoinExchange::printBit(std::string date, float n)
{
	std::map<std::string, float>::const_iterator iter;
	float res;

	res = 0;
	iter = _data.find(date);
	if (iter != _data.end())
		res = (iter->second) * n;
	else
	{
		iter = _data.lower_bound(date);
		if(iter == _data.begin())
		{
			std::cout << "Error : invalid date" << std::endl;
			return;
		}
		--iter;
		res = (iter->second) * n;
	}
	(n == static_cast<int>(n)) ?
		std::cout << date << " => " << static_cast<int>(n) << " = " << res << std::endl :
		std::cout << date << " => " << n << " = " << res << std::endl;
}

