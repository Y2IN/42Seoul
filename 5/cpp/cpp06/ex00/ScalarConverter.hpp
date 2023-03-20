#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>

class ScalarConverter {
    private:
      ScalarConverter();
    public:
      //A default constructor
      ScalarConverter(const std::string &);
      //A copy constructor
      ScalarConverter(const ScalarConverter &);
      // A assignment operator overload
      ScalarConverter&	operator=(const ScalarConverter &);
      // A destructor
      ~ScalarConverter();
      static void convert(const std::string& input);
};

#endif 