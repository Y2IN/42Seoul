/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:31:15 by yje               #+#    #+#             */
/*   Updated: 2023/02/18 15:26:25 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;

	if(argc!=2)
	{
		std::cout << "Error : input error" << std::endl;;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}
