/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:51:52 by yje               #+#    #+#             */
/*   Updated: 2023/03/20 01:13:20 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  : AForm("presidential", 25, 5), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
  : AForm("presidential", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin)
  : AForm(origin), _target(origin._target) {
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& origin) {
  if (this != &origin) {
    dynamic_cast<AForm&>(*this) = dynamic_cast<const AForm&>(origin);
    this->_target = origin._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    this->isExecutable(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}