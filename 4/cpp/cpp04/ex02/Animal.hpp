/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:52:11 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 18:04:03 by yje              ###   ########.fr       */
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
		// 추상클래스 = 순수 가상 함수가 한 개 이상 포함된 클래스
		// 인스턴스화 할 수 없음
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif
