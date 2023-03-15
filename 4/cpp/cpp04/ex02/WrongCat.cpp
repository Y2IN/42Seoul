/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:25:10 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 17:03:00 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal() {
	this->_type = "Wrong cat";
	std::cout << "Wrong Cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat){
	this->_type = wrongCat.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &wrongCat)
		this->_type = wrongCat.getType();
	return *this;
}

WrongCat::~WrongCat() {
	std::cout<< "Wrong Cat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "wrong cat meow" << std::endl;
}

