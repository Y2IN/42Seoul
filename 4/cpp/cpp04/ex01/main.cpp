/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:20:00 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 21:13:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void bye() {
	system("leaks a.out");
}

int main()
{
	atexit(bye);
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << std::endl;

		delete j;
		delete i;

		std::cout << std::endl;
	}


	const Animal *meta[10];

	std::cout << "--------allocate--------" << std::endl;
	for(int i = 0; i<10; i++) {
		if (i % 2)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		std::cout << std::endl;
	}
	// system("leaks a.out");

	std::cout << "--------type--------" << std::endl;
	for(int i = 0; i<10; i++) {
		std::cout << meta[i]->getType() << std::endl;
	}
	std::cout << "--------destruct--------" << std::endl;
	for(int i = 0; i<10; i++) {
		delete meta[i];
	}

	std::cout << "----------------" << std::endl;

	{
		Cat *cat = new Cat();
		cat->setBrain("aaaaaaaaaa");
		Cat cat2(*cat);
		delete cat;
		cat2.printBrain();
		cat2.setBrain("bbbbbbbbbb");
	}
	// system("leaks a.out");
	std::cout << "----------------" << std::endl;

	Brain *brain = new Brain("abc");
	Cat cat(*brain);
	delete brain;

	cat.printBrain();
	cat.setBrain("hi");
	cat.printBrain();

	// system("leaks a.out");
	return 0;
}
