/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:55:40 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 17:27:39 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type){
}

Weapon::~Weapon(){
}

void Weapon::setType(const std::string &type){
	this->_type = type;
}

const std::string &Weapon::getType(void) const{
	return (this->_type);
}


