/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:31 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 19:59:36 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& ref): AMateria(ref._type) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& ref) {
	std::cout << "Ice copy assignment operator called";
	if (this != &ref)
		this->_type = ref._type;
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
