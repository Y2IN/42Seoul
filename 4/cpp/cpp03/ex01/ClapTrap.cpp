
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:35:59 by yje               #+#    #+#             */
/*   Updated: 2023/02/20 19:35:59 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout<<"Default constructor called" << std::endl;
}

ClapTrap(std::string name)_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout<<name <<"is created" <<std::endl;
}
ClapTrap(const ClapTrap& origin):_name(origin.getName()),\
	_hitPoints(origin.getHitPoints()),
	_energyPoints(origin.getEnergyPoints()),\
	_attackDamage(origin.getAttackDamage()){
		std::cout << "copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << this->_name <<"is Destructed" << std::endl;
}

std::string ClapTrap::getName(void) const{
	return(_name);
}

unsigned int ClapTrap::getAttackDamage(void) const{
	return(_attackDamage)
}

unsigned int ClapTrap::getEnergyPoints(void) const{
	return(_energyPoints)
}

unsigned int ClapTrap::getHitPoints(void) const{
	return(_hitPoints)
}
