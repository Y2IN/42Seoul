#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T>
void iter(T *array, size_t size, void (*fn)(T&)) {
	for (size_t i = 0; i < size; i++)
		fn(array[i]);
}

template <typename T>
void print(T& a) {
	std::cout << a << "\t";
}

// template <typename T>
// void mul(T& a) {
// 	a++;
// }

#endif
