/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:51:54 by yje               #+#    #+#             */
/*   Updated: 2023/02/19 20:32:51 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
	Point a(0.0, 0.0);
	Point b(0.0, 4.0);
	Point c(5.0, 0.0);
	Point hit1(2.9, 1.0);
	Point hit2(10.0, 10.0);

	// if (bsp(a, b, c, hit1))
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
  	std::cout << "Hit Point1 is " << (bsp(a, b, c, hit1) ? "inside " : "outside ") << std::endl;
  	std::cout << "Hit Point2 is " << (bsp(a, b, c, hit2) ? "inside " : "outside ") << std::endl;
  return 0;
}

