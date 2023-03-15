/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:06:29 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 20:52:59 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++)
		this->_amateria[i] = NULL;
	std::cout<<"MateriaSource constructor created" <<std::endl;
}

MateriaSource::MateriaSource(const MateriaSource & ref){
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		AMateria *AmateriaTmp = ref.getMateria(i);
		if (AmateriaTmp)
			this->_amateria[i] = AmateriaTmp->clone();
		else
			this->_amateria[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource&  ref) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != & ref) {
	for (int i = 0; i < 4; i++) {
			AMateria *tmp =  ref.getMateria(i);
			if (this->_amateria[i]) {
				delete this->_amateria[i];
			}
			if (tmp) {
				this->_amateria[i] = tmp->clone();
			}
			else {
				this->_amateria[i] = NULL;
			}
	}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_amateria[i])
			delete this->_amateria[i];
	}
}

AMateria	*MateriaSource::getMateria(int idx) const {
		return this->_amateria[idx];
}


void	MateriaSource::learnMateria(AMateria *amateria) {
	for (int i = 0; i < 4; i++) {
		if (this->_amateria[i] == NULL) {
			this->_amateria[i] = amateria;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_amateria[i] && this->_amateria[i]->getType() == type){
			std::cout << "MateriaSource createMateria " << type << " success" << std::endl;
			return this->_amateria[i]->clone();
		}
	}
	std::cout << "MateriaSource createMateria " << type << " fail" << std::endl;
	return NULL;
}
