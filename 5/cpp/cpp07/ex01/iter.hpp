#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T>
void iter(const T *array, size_t len, void (*fn)(const T&)) {
	for (size_t i = 0; i < len; i++)
		fn(array[i]);
}

// template <typename T>
// void iter(T *array, size_t len, void (*fn)(T&)){
// 	for (size_t i = 0; i < len; i++)
// 		fn(array[i]);
// }

template <typename T>
void print(const T& a) {
	std::cout << a << "\t";
}
#endif
