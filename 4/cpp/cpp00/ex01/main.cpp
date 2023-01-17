/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:13:35 by yje               #+#    #+#             */
/*   Updated: 2023/01/17 12:08:42 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main() {
	PhoneBook phonebook = PhoneBook();
	std::string cmd;

	std::cout << "My Awesome PhoneBook" << std::endl;
	std::cout << "command> ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
		{
			phonebook.AddContact();
			std::cout << "command> ";
		}
		else if (cmd == "SEARCH")
		{
			phonebook.search();
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
    std::cout << "EOF -> Program Exit" << std::endl;
    return (0);
	}
	return (0);
}