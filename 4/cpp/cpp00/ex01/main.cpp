/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:13:35 by yje               #+#    #+#             */
/*   Updated: 2022/12/30 15:17:56 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	cmd;

	while (true)
	{
		std::cout << "please enter your command : (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			
		}
		else if (cmd == "SEARCH")
		{
			
		}
		else if (cmd == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "sorry, command not found" << std::endl;
		}
	}
	return (0);
}