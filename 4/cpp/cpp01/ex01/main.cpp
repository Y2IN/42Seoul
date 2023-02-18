/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:20:50 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 16:08:10 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {
	Zombie zombie = Zombie("Foo");
  	zombie.announce();

	int N = 5;
  	Zombie *zombies = zombieHorde(N, "Bar");
  	for (int i = 0; i < N; i++) {
    zombies[i].announce();
  	}

	delete [] zombies;
	// system("leaks Zombie");
  	return (0);
}
