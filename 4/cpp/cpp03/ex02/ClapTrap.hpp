/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:25:30 by yje               #+#    #+#             */
/*   Updated: 2023/03/08 16:53:18 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H_
#define CLAPTRAP_H_

// #include <iostream>
#include <iostream>
#include <string>
class ClapTrap {
	//상속 받은 클래스 내에서 접근이 가능해야 함 -> protected
	// 자식 클래스에서 변경을 해주려는 함수들은 가상 함수로 변경
	// 가상함수란 자식 클래스에서 재정의할 것으로 기대하는 함수들을 부모 클래스에서 정의한 함수
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& origin);
		ClapTrap& operator=(const ClapTrap& origin);
		//virtual 키워드를 붙여준다. 부모 클래스에서 선언되어 자식 클래스에 의해 재정의
		virtual ~ClapTrap();
		std::string getName( void ) const ;
    	unsigned int getHitPoints( void ) const ;
    	unsigned int getEnergyPoints( void ) const ;
    	unsigned int getAttackDamage( void ) const ;
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif
