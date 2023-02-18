/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:31:27 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 17:36:02 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _type(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::attack(void) const {
  std::cout << this->_name << " attacks with his "
            << this->_type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon *type) {
  this->_type = type;
}
