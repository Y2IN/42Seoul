/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:34 by yje               #+#    #+#             */
/*   Updated: 2023/03/08 16:27:45 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::string s1 = "yein";
	std::string s2 = "yje";
	std::string s3 = "je";
	ScavTrap a(s1);
	ScavTrap b(s2);
	ClapTrap c(s3);


	std::cout << std::endl;
	a.attack(s3);
	c.takeDamage(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	a.attack(s2);
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	a.attack(s3);
	b.takeDamage(a.getAttackDamage());
	a.attack(s3);
	b.takeDamage(a.getAttackDamage());
	a.attack(s3);
	b.takeDamage(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	b.guardGate();
	std::cout << std::endl;
	return 0;


}
