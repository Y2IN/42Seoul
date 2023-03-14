/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:52:11 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 14:21:29 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>
class Animal {
	protected :
		std::string _type;
	public:
		Animal();// A constructor
		Animal(const Animal&);//A copy constructor
		Animal& operator=(const Animal&);//A copy assignment operator
		virtual ~Animal();//A destructor
		virtual void makeSound() const;
		std::string getType() const;

};

#endif
