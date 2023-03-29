#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int>	_deq;
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);


	public:
		PmergeMe();
		~PmergeMe();
		void checkArgs(int argc, char **args);
		void sortSequence(std::vector<int> &);
		void sortSequence(std::deque<int> &);



};

#endif
