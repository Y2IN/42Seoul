/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:33:07 by yje               #+#    #+#             */
/*   Updated: 2023/02/23 17:45:14 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string s1 = "who";
	std::string s2 = "who2";
	ClapTrap c1(s1);
	ClapTrap c2(s2);

	std::cout << std::endl;
	c1.beRepaired(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.attack(s2);
	c2.takeDamage(10);
	std::cout << std::endl;

	// std::cout << std::endl;
	// c2.beRepaired(3);
	// c2.beRepaired(2);
	// std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(s1);
	c1.takeDamage(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.beRepaired(10);
	c1.attack(s2);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(s1);
	c1.takeDamage(5);
	std::cout << std::endl;
	return 0;
}

