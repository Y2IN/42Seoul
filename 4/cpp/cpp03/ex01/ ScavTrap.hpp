/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ScavTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:33:38 by yje               #+#    #+#             */
/*   Updated: 2023/02/23 17:50:43 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_


#include "ClapTrap.hpp"

class ScavTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& origin);
		ScavTrap& operator=(const ScavTrap& origin);
		~ScavTrap();
		void guardGate();
};

#endif
