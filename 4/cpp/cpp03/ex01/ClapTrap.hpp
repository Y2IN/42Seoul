/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:25:30 by yje               #+#    #+#             */
/*   Updated: 2023/02/20 19:44:18 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H_
#define CLAPTRAP_H_

#include <iostream>

class ClapTrap{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& origin);
		ClapTrap& operator=(const ClapTrap& origin);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);;
		void beRepaired(unsigned int amount);
}
#endif
