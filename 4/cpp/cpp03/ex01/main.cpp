/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:44:34 by yje               #+#    #+#             */
/*   Updated: 2023/02/23 17:51:35 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
int main()
{
	ScavTrap a("a");
	ScavTrap b(a);
	ScavTrap c;
	c = b;

	a.attack("b");
	a.beRepaired(200);
	a.guardGate();
	a.takeDamage(99);
	a.attack("b");

}
