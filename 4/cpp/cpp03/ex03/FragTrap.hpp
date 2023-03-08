/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:31:39 by yje               #+#    #+#             */
/*   Updated: 2023/03/08 19:56:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H_
#define FRAGTRAP_H_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& origin);
		FragTrap& operator=(const FragTrap& origin);
		virtual ~FragTrap();
		void	highFivesGuys(void);
		// void attack(const std::string& target);
};

#endif
