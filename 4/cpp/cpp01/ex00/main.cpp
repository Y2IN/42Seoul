/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:06:04 by yje               #+#    #+#             */
/*   Updated: 2023/02/14 17:47:15 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    // Create Zombie class
    Zombie zombie = Zombie("Foo");
    zombie.announce();

  // It creates a zombie, name it, and return it so you can use it outside of the function scope.
    Zombie *newZ = newZombie("new");
    newZ->announce();
    delete newZ;

      // It creates a zombie, name it, and the zombie announces itself.
    randomChump("random");
    // delete newZ;
    system("leaks Zombie");
    return (0);
}
