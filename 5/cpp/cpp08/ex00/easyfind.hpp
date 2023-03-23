#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value){
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter ==  container.end())
        throw std::invalid_argument("value is not in this container");
    return iter;
};

#endif