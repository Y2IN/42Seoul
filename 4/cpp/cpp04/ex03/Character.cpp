/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:03:14 by yje               #+#    #+#             */
/*   Updated: 2023/03/16 22:36:30 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
	: _name(""), _floorSize(0) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	
	for (int i = 0; i < 10; i++) {
		this->_floor[i] = NULL;
	}
  std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string const & name)
	: _name(name), _floorSize(0) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	
	for (int i = 0; i < 10; i++) {
		this->_floor[i] = NULL;
	}
  std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& ref) 
	: _name(ref._name), _floorSize(ref._floorSize) {
	for (int i = 0; i < 4; i++) {
    	if (this->_inventory[i])
      		delete this->_inventory[i];
    	this->_inventory[i] = NULL;
    	if (ref._inventory[i])
      	this->_inventory[i] = ref._inventory[i]->clone();
	}

  	for (int i = 0; i < 10; i++) {
    	this->_floor[i] = NULL;
    	if (ref._floor[i])
      	this->_floor[i] = ref._floor[i]->clone();
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& ref) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &ref) {
    /* insert */
    this->_name = ref._name;
    for (int i = 0; i < 4; i++) {
    	if (this->_inventory[i])
        	delete this->_inventory[i];
      	this->_inventory[i] = NULL;
      	if (ref._inventory[i])
        	this->_inventory[i] = ref._inventory[i]->clone();
    }
    this->_floorSize = ref._floorSize;
    for (int i = 0; i < 10; i++) {
    	this->_floor[i] = NULL;
      	if (ref._floor[i])
        	this->_floor[i] = ref._floor[i]->clone();
		}		
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) 
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	this->cleanFloor();
}

std::string const &Character::getName() const {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i<4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m->clone();
			std::cout<<"character "<< this->_inventory[i]->getType()<<"equip success!!"<< std::endl;
			return ;
		}
	}
	std::cout<<"character "<<"equip failed!!"<< std::endl;
}

void	Character::unequip(int idx) {
	if (0 <= idx && idx <= 3) {
		this->floor(idx);
		std::cout<<"character "<<this->_floor[idx]->getType()<<" unequip success!!"<< std::endl;
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

void Character::floor(int idx) {
  if (this->_inventory[idx]) {
    for (int i = 0; i < 10; i++) {
      if (this->_floor[i] == NULL) {
        this->_floor[i] = this->_inventory[idx];
        this->_inventory[idx] = NULL;
        ++this->_floorSize;
        break;
      }
    }
  }

  if (this->_floorSize == 10)
    this->cleanFloor();
}

void Character::cleanFloor() {
  for (int i = 0; i < 10; i++) {
    if (this->_floor[i]) {
      delete this->_floor[i];
      this->_floor[i] = NULL;
    }
  }
  this->_floorSize = 0;
}