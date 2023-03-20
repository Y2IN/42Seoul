/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:51:15 by yje               #+#    #+#             */
/*   Updated: 2023/03/20 01:18:29 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
  : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
  : AForm(origin), _target(origin._target) {
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& origin) {
  if (this != &origin) {
    dynamic_cast<AForm&>(*this) = dynamic_cast<const AForm&>(origin);
    this->_target = origin._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    this->isExecutable(executor);
    std::cout << "drill....drill...." << std::endl;
    srand(time(NULL));
    int random = rand() % 2;
//   std::time_t currentTime = std::time(nullptr);
    (random)
    ? std::cout << this->_target << " has been robotomized successful." << std::endl
    : std::cout << this->_target << " has failed to robotomize." << std::endl;
}

