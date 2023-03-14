/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:56:09 by yje               #+#    #+#             */
/*   Updated: 2023/03/10 18:16:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout <<"Cat constructor called"<< std::endl;
}

Cat::Cat(const Cat& cat) {
	this->_type = cat.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &cat)
		this->_type = cat.getType();
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow meow meow" << std::endl;
}


