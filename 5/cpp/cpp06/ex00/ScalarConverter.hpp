#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class ScalarConverter {
    private:
      //A default constructor
      ScalarConverter();
    public:
      //A copy constructor
      ScalarConverter(const ScalarConverter &);
      // A assignment operator overload
      ScalarConverter&	operator=(const ScalarConverter &);
      // A destructor
      ~ScalarConverter();
      static void convert(const std::string& input);
      static int	type(const std::string& str);
};

#endif 