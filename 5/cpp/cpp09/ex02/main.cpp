#include "PmergeMe.hpp"

bool validateInput(std::string s) {
	char *ptr = NULL;
	double value = std::strtod(s.c_str(), &ptr);
	if (value == 0.0 && !std::isdigit(s[0]))
		return false;
	if (*ptr && std::strcmp(ptr, "f"))
		return false;
	if (value < 0)
		return false;
	return (value == static_cast<int>(value));
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::vector<int> originalData;
	int i = 1;
	while (i < argc) {
		std::string stringTmp(argv[i]);
		std::istringstream ss(stringTmp);
		std::string stringBuffer;
		while (std::getline(ss, stringBuffer, ' ')) {
		if (validateInput(stringBuffer) == false) {
			std::cout << "[" << stringBuffer << "]" << std::endl;
			std::cerr << "Error" << std::endl;
			return 1;
		}
		std::cout << stringBuffer << std::endl;
		originalData.push_back(static_cast<int>(strtod(stringBuffer.c_str(), NULL)));
		}
		++i;
	}
	return 0;
}
