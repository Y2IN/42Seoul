/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:20:00 by yje               #+#    #+#             */
/*   Updated: 2023/03/17 15:26:15 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void bye(){
	system("leaks a.out");
}

int main()
{
	atexit(bye);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n-------------------------\n" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongAnimal = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();


	std::cout << std::endl;
	std::cout << wrongMeta->getType() << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << std::endl;

	wrongMeta->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;
	delete wrongMeta;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
