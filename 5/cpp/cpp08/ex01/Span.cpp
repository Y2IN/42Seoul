# include "Span.hpp"

# include <algorithm>
# include <iostream>
# include <vector>

Span::Span() : _vector(0){
    this->_vector.reserve(0);
}

Span::Span(unsigned int n) : _vector(0){
    this->_vector.reserve(n);   
}
// _vector(0, 0) -> (초기크기, 정수)
Span::Span(const Span &origin) : _vector(0) {
    this->_vector.reserve(origin.getVector().capacity()); //reserve -> 크기 변경해주는 함수
    if (this->_vector.capacity() != 0)
        std::copy(origin.getVector().begin(), origin.getVector().end(), std::back_inserter(this->_vector));
}

Span &Span::operator=(const Span& origin) {
    if (this != &origin) {
        this->_vector.clear();
        this->_vector.reserve(origin.getVector().capacity());
        if (this->_vector.capacity() != 0)
            std::copy(origin.getVector().begin(), origin.getVector().end(), std::back_inserter(this->_vector));
    }
    return *this;
}

Span::~Span() {}

void    Span::addNumber(int num) {
    if (this->_vector.size() >= this->_vector.capacity()) {
        throw CanNotStoreNumber();
    }
    this->_vector.push_back(num);
}

std::size_t Span::longestSpan() {
  if (this->_vector.size() <= 1) 
    throw NotEnoughElement();
  return *std::max_element(this->_vector.begin(), this->_vector.end()) - *std::min_element(this->_vector.begin(), this->_vector.end());
}

size_t Span::shortestSpan() {
    if (this->_vector.size() <= 1) {
        throw NotEnoughElement();
    }
    std::vector<int> sortedVector = this->_vector;
    std::sort(sortedVector.begin(), sortedVector.end());
    int min = INT_MAX;
    for (std::vector<int>::iterator it = sortedVector.begin(); it != sortedVector.end() - 1; it++) 
    {
        min = std::min(min, *(it + 1) - *it);
    }
    return min;;
}

const char* Span::CanNotStoreNumber::what() const throw() {
  return "Span can't add number. Not enough capacity.";
}

const char* Span::NotEnoughElement::what() const throw() {
  return "Not enough element";
}

const std::vector<int>& Span::getVector() const {
  return this->_vector;
}
