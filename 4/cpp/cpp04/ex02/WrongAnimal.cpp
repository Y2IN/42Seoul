/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:51:23 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 17:33:40 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) {
	this->_type = wrongAnimal.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal){
	std::cout << "Wrong Animal assignment operator called" << std::endl;
	if(this != &wrongAnimal)
		this->_type = wrongAnimal.getType();
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "wrong animal" <<std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_type;
}

std::ostream& operator<<(std::ostream& ofs, const WrongAnimal& wrongAnimal) {
  return ofs << wrongAnimal.getType();
}

