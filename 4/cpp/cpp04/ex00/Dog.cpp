/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:59:07 by yje               #+#    #+#             */
/*   Updated: 2023/03/10 18:16:10 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout <<"Dog constructor called"<< std::endl;
}

Dog::Dog(const Dog& Dog) {
	this->_type = Dog.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& Dog) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &Dog)
		this->_type = Dog.getType();
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "meong meong" << std::endl;
}
