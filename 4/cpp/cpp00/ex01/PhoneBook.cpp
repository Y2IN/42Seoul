
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:03:53 by yje               #+#    #+#             */
/*   Updated: 2023/01/17 09:59:34 by yje              ###   ########.fr       */
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

void PhoneBook::Add() {
  contact [idx % 8] = CreateContact();
  idx++;
  (idx > 16) ? idx -= 8 : idx;
}

void PhoneBook::Search(){
  std::cout << "┌───────┬────────────┬────────────┬────────────┐" << std::endl;
  std::cout << "│ index │ first name │  last name │   nickname │" << std::endl;
  std::cout << "├───────┼────────────┼────────────┼────────────┤" << std::endl;

for (int i = 0; i < 8; i++) {
  if (idx < 8 && idx == i)
    break;
  std::cout << "│   " << i % 8 + 1 << "   │";
  DisplaySearchList(contact[i].getFirstName());
  DisplaySearchList(contact[i].getLastName());
  DisplaySearchList(contact[i].getNickName());
  std::cout << "\n";
  }
}

void PhoneBook::DisplaySearchList(std::string contactInfo)
{
  int contactSize = contactInfo.length();

  if (contactSize < 10) {
    for (int i = 0; i < 12 - contactSize - 1; i++)
      std::cout << " ";
    std::cout << contactInfo << " |";
  }
  else if (contactSize == 10) {
    std::cout << " " << contactInfo << " |";
  }
  else {
    for (int i = 0; i < 0; i++){
      std::cout << contactInfo[i];   
    }
    std::cout << ". |";
  }
}


