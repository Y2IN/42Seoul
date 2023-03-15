/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:50:23 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 20:01:34 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& ref): AMateria(ref._type) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& ref) {
	std::cout << "Cure copy assignment operator called" <<std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
