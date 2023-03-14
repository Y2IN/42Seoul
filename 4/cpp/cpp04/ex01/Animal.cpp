/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:52:17 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 20:29:13 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() :
	_type("Animal")  {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal):
	_type(animal.getType()){
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &animal) {
    	this->_type = animal._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

