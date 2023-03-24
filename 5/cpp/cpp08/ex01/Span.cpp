# include "Span.hpp"

# include <algorithm>
# include <iostream>
# include <vector>

Span::Span() {
    this->_max_size = 0;
}

Span::Span(unsigned int n) {
    this->_max_size = n;
}

Span::Span(const Span &origin) {
    this->_max_size = origin._max_size;
}

Span &Span::operator=(const Span& origin) {
    if (this != &origin) {
        this->_vector.clear();
        std::vector<const int>::iterator iter;
        for (iter = this->_vector.begin(); iter != origin._vector.end(); iter++) {
            this->_vector.push_back(*iter);
        }
        this->_max_size = origin._max_size;
    }
    return *this;
}

Span::~Span() {}

void    Span::addNumber(int num) {
    if (this->_vector.size() >= this->_max_size) {
        throw CanNotStoreNumber();
    }
    this->_vector.push_back(num);
}
