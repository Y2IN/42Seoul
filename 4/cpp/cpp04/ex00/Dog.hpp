/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:46 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 14:21:38 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H_
#define DOG_H_

#include "Animal.hpp"

class Dog : public Animal {
	public :
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();
		void	makeSound() const;
};
#endif
