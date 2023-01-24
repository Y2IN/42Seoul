/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:13:35 by yje               #+#    #+#             */
/*   Updated: 2023/01/24 20:23:11 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
	PhoneBook phonebook = PhoneBook();
	std::string cmd;

	std::cout << "My Awesome PhoneBook" << std::endl;
	std::cout << "command> ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
		{
			phonebook.Add();
			std::cout << "command> ";
		}
		else if (cmd == "SEARCH")
		{
			phonebook.Search();
			std::cout << "command> ";
		}
		else if(cmd == "EXIT")
		{
			std::cout << "exit" <<std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid input\n\n";
      		std::cout << "command> ";
		}
	}
	if (std::cin.eof()) {
    std::cout << "Enter EOF. Program Exit." << std::endl;
    return (0);
	}
	return (0);
}
