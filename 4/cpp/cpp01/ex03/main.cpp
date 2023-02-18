/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:54:10 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 19:41:20 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
  std::cout << "Create HumanA class" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", &club);
  }

  std::cout << std::endl << "Create HumanB class" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(&club);
    // jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}
