#include "ScalarConverter.hpp" 

// inf는 무한대값을 의미
// nan(Not A Number) 은 숫자가 아님 -> float value

ScalarConverter::ScalarConverter(){}


ScalarConverter::ScalarConverter(const ScalarConverter& origin) {
  *this = origin;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& origin) {
  (void)origin;
  return *this;
}

ScalarConverter::~ScalarConverter(){}

int	type(const std::string& str) {

	char *end = NULL;
	std::strtod(str.c_str(), &end);

	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "nan" || str == "+inf" || str == "-inf")
		return (1); //nanf
	if (end[0] == '\0' && str.find(".") == -1)
		return (2); //int
	else if (end[0] == '\0')
		return (3); //double
	else if (std::string(end) == "f")
		return (4); //float
	else if (str.size() == 1 && std::isprint(str[0]))
		return (5);
	return (0);
}



void ScalarConverter::convert(const std::string& input)
{
  	if (type(input) == 0)
	{
    	std::cout << "convert fail" << std::endl;
		return ;
	}
	if (type(input) == 1)
	{
		std::string except[6] = {"-inff", "+inff", "nanf", "+inf", "-inf", "nan"};
		for (int i = 0; i < 6; i++) {
			if (except[i] == input){ 
				if (i == 0 || i == 4)
				{
					std::cout << "char: impossible" << std::endl;
	    			std::cout << "int: impossible" << std::endl;
	    			std::cout << "float: -inff" << std::endl;
	    			std::cout << "double: -inf" << std::endl;
				}
				else if (i == 1 || i == 3)
				{
					std::cout << "char: impossible" << std::endl;
	    			std::cout << "int: impossible" << std::endl;
	    			std::cout << "float: +inff" << std::endl;
	    			std::cout << "double: +inf" << std::endl;
				}
				else if (i==2 || i == 5)
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					std::cout << "float: nanf" << std::endl;
					std::cout << "double: nan" << std::endl;
				}

			}

		}

	}
	else 
		std::cout<<type(input)<<std::endl;
	
}


int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Invaild number of argument. Check it!" << std::endl;
    return (1);
  }
  ScalarConverter::convert(av[1]);
  return (0);
}