#include "ScalarConverter.hpp" 

// inf는 무한대값을 의미
// nan(Not A Number) 은 숫자가 아님 -> float value
// static_cast<바꾸려는 타입>(대상)
// 기본 자료형의 형변환 및 기본 클래스에서 파생클래스로의 포인터 변환 연산에 사용할 수 있음 -> 형 변환이 컴파일 시점

ScalarConverter::ScalarConverter(){}


ScalarConverter::ScalarConverter(const ScalarConverter& origin) {
  *this = origin;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& origin) {
  (void)origin;
  return *this;
}

ScalarConverter::~ScalarConverter(){}

int	ScalarConverter::type(const std::string& str) {

	char *end = NULL;
	std::strtod(str.c_str(), &end);

	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "nan" || str == "+inf" || str == "-inf")
		return (1); //nanf
	// if (end[0] == '\0' && str.find(".") == -1)
	// 	return (2); //int
	if (end[0] == '\0')
		return (3); //double
	else if (str.size() == 1 && std::isprint(str[0]))
		return (5);
	else if (std::string(end) == "f")
		return (4); //float
	return (0);
}



void ScalarConverter::convert(const std::string& input)
{
	double value;
	char *ptr = NULL;
	value = std::strtod(input.c_str(), &ptr);
  	if (type(input) == 0)
	{
    	std::cout << "convert fail" << std::endl;
		return ;
	}
	if (type(input) == 1)
	{
		std::string except[6] = {"-inff", "+inff", "nanf", "+inf", "-inf", "nan"};
		for (int i = 0; i < 6; i++) 
		{
			if (except[i] == input)
			{ 
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
	else if (type(input) == 5){
    	std::cout << "char: '" << input[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(input[0]) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(input[0]) << std::endl;
	}
	else
	{
		std::cout << "char: ";
    	std::isprint(static_cast<char>(value)) ? std::cout << "'" << static_cast<char>(value) << "'" << std::endl : std::cout << "Non displayable" << std::endl;
		//int
		std::cout << "int: ";
  		(value > 2147483647 || value < -2147483648)
    	? std::cout << "impossible" << std::endl : std::cout << static_cast<int>(value) << std::endl;
		//float
		(static_cast<float>(value) == static_cast<int>(static_cast<float>(value)))
			? std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl
			: std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(value) << "f" << std::endl;
		//double
		(static_cast<double>(value) == static_cast<int>(static_cast<double>(value)))
			? std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl
			: std::cout << "double: " << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<double>(value) << std::endl;
	}
}
