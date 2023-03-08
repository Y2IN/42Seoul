/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:33:38 by yje               #+#    #+#             */
/*   Updated: 2023/03/08 18:06:58 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include "ClapTrap.hpp"
//부모 클래스의 멤버 변수와 멤버 함수를 자식 클래스가 재사용하는 개념. 접근 제한자를 통해 상속의 범위 설정 가능
class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& origin);
		ScavTrap& operator=(const ScavTrap& origin);
		virtual ~ScavTrap();
	//  * virtual function
    //   ! 자식 클래스에서 재정의 해주기 위해 다시 선언
		void attack(const std::string& target);
		void guardGate();
};

#endif
