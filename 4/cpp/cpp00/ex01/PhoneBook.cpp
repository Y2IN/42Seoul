/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:03:53 by yje               #+#    #+#             */
/*   Updated: 2023/01/06 18:36:55 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
  : idx(0) {
}

PhoneBook::~PhoneBook()
{	
}

Contact PhoneBook::CreateContact() {
  std::string contactInfo[5];
  std::string coutList[5];
  coutList[0] = "first name> ";
  coutList[1] = "last name> ";
  coutList[2] = "nick name> ";
  coutList[3] = "phone number> ";
  coutList[4] = "darkest secret> ";

  for (int i = 0; i < 5; i++) {
    std::cout << coutList[i];
    std::getline(std::cin, contactInfo[i]);
    if (std::cin.eof()) {
      std::cout << "Enter EOF. Program Exit." << std::endl;
    }
  }
  return Contact(contactInfo[0], contactInfo[1], contactInfo[2], contactInfo[3], contactInfo[4]);
}
