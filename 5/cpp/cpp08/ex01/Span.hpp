#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Span {
	private :
        unsigned int _max_size;
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

		size_t getMaxsize();


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
