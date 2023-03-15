/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:20:46 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 21:01:22 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	:_type("") {
		std::cout<< "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
	:_type(type){
	std::cout<< "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &ref)
	:_type(ref._type) {
	std::cout << "Amateria copy constructor called" <<std::endl;
}

AMateria&  AMateria::operator=(const AMateria& ref)
{
	std::cout << "AMateria operator called" <<std::endl;
	if(this!= &ref)
		this->_type = ref._type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return this->_type;
}
void AMateria::use(ICharacter& target){
	(void) target;
	std::cout << "This message will not print" << std::endl;
}

