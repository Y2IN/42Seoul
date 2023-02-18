/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:56:55 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 17:43:35 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

class Weapon{
	private:
	std::string _type;

	public:
	Weapon(const std::string &type);
	~Weapon();
	void setType(const std::string &type);
	const std::string &getType(void) const;
};

# endif
