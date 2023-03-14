/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:51:27 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 17:10:31 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H_
#define WRONGANIMAL_H_

#include <iostream>

class WrongAnimal {
	protected :
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wrongAnimal);
		WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
		virtual ~WrongAnimal();

		void makeSound() const;
		std::string getType() const;
};

std::ostream& operator<<(std::ostream& ofs, const WrongAnimal& wrongAnimal);
#endif
