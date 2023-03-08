/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:31:35 by yje               #+#    #+#             */
/*   Updated: 2023/03/08 19:56:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	:ClapTrap("FragTrap") {
	std::cout << "FragTrap FragTrap is created." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name) {
	std::cout << "FragTrap" << name << " is created." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& origin){
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->_name = origin._name;
	this->_hitPoints = origin._hitPoints;
	this->_energyPoints = origin._energyPoints;
	this->_attackDamage = origin._attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& origin){
	std::cout << "FragTrap copy assignment operator called"<<std::endl;
	this->_name = _name;
	this->_hitPoints = origin._hitPoints;
	this->_energyPoints = origin._energyPoints;
	this->_attackDamage = origin._attackDamage;
	return(*this);
}

FragTrap:: ~FragTrap(){
	std::cout<<"FragTrap"<< this->_name<< " destructor called"<< std::endl;
}

void	FragTrap::highFivesGuys() {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " Hit point is 0" << std::endl;
	}
	else if (this->_energyPoints == 0) {
		std::cout << this->_name << " Energy is not enough" << std::endl;
	}
	std::cout << "FragTrap " << this->_name<< " highFives" << std::endl;
	this->_energyPoints--;
}
