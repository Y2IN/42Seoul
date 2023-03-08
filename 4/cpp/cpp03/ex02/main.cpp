/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:34 by yje               #+#    #+#             */
/*   Updated: 2023/03/08 17:26:36 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::string s1 = "yein";
	std::string s2 = "yje";
	std::string s3 = "je";
	FragTrap a(s1);
	FragTrap b(s2);
	ClapTrap c(s3);


	std::cout << std::endl;
	a.attack(s3);
	c.takeDamage(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	a.attack(s2);
	a.attack(s2);
	b.takeDamage(a.getAttackDamage());
	b.takeDamage(a.getAttackDamage());
	b.takeDamage(a.getAttackDamage());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	std::cout << std::endl;

	// std::cout << std::endl;
	// a.attack(s3);
	// b.takeDamage(a.getAttackDamage());
	// a.attack(s3);
	// b.takeDamage(a.getAttackDamage());
	// a.attack(s3);
	// b.takeDamage(a.getAttackDamage());
	// std::cout << std::endl;

	std::cout << std::endl;
	a.highFivesGuys();
	std::cout << std::endl;
	return 0;


}
