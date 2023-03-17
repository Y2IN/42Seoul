/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:16:15 by yje               #+#    #+#             */
/*   Updated: 2023/03/17 15:27:11 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// void bye() {
// 	system("leaks a.out");
// }

int main() {
	{
		// atexit(bye);
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;

		src->learnMateria(new Ice());
		std::cout << std::endl;
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		std::cout << std::endl;

		AMateria* tmp;
		tmp = src->createMateria("ice");
		std::cout << std::endl;
		me->equip(tmp);
		std::cout << std::endl;
		delete tmp;
		tmp = NULL;

		for (int i = 0; i < 10; i++) {
			tmp = src->createMateria("cure");
			std::cout << std::endl;
			me->equip(tmp);
			std::cout << std::endl;
			delete tmp;
			tmp = NULL;
		}

		ICharacter* bob = new Character("bob");
		std::cout << std::endl;
		me->use(0, *bob);
		std::cout << std::endl;
		me->use(1, *bob);
		std::cout << std::endl;

		for (int i = 0; i < 4; i++) {
			std::cout << i << "\n";
			me->unequip(i);
		}

		delete bob;

		delete me;

		delete src;
	}
//   system("leaks a.out");
  return 0;
}
