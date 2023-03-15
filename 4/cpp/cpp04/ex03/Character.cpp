/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:03:14 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 21:22:09 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
  : _name(""){
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
  std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string const & _name) {
	std::cout << "Character constructor called" << std::endl;
	this->_name = _name;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character& ref) {
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = ref.getName();
	for (int i = 0; i < 4; i++) {
		const AMateria *Materia = ref.getMateriaByIdx(i);
		if (Materia) {
			this->_inventory[i] = Materia->clone();
		}
		else {
			this->_inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& ref) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &ref) {
		this->_name = ref.getName();
		for (int i = 0; i<4; i++) {
			const AMateria *tmp = ref.getMateriaByIdx(i);
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (tmp)
				this->_inventory[i] = tmp->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
}

std::string const &Character::getName() const {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i<4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (0 <= idx && idx <= 3) {
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (0 <= idx && idx <= 3) {
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
	}
}

AMateria const *Character::getMateriaByIdx(int idx) const {
	return _inventory[idx];
}
