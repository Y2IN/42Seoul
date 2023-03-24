#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Span {
	private :
		std::vector<int> _vector;
		Span();
	public:
	    Span(unsigned int n);
		Span(const Span &);
		Span& operator=(const Span &);
		~Span();

		size_t shortestSpan();
		size_t longestSpan();
		void addNumber(int num);

		template <typename T>
		void addManyNumbers(T& container) {
			if (std::distance(container.begin(), container.end()) > static_cast<int>(this->_vector.capacity() - this->_vector.size())) 
				throw CanNotStoreNumber();
			typename T::iterator iter = container.begin();
			while (iter != container.end()) {
				this->_vector.push_back(*iter);
				++iter;
		}
    }
		const std::vector<int>& getVector() const;
		class CanNotStoreNumber : public std::exception {
			public:
				const char* what() const throw();
		};

		class NotEnoughElement : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
