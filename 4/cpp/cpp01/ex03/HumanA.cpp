/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:23 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 17:47:49 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon *type) : _name(name), _type(*type) {
}

HumanA::~HumanA() {
}

void HumanA::attack(void) const {
  std::cout << this->_name << " attacks with his "
            << this->_type.getType() << std::endl;
}
