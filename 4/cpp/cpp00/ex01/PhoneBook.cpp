
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
#include <iomanip>
// #include<string.h>

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
    while (contactInfo[i].length() <= 0){
      std::cout << "Can't be empty" << std::endl;
      std::cout << coutList[i];
      std::getline(std::cin, contactInfo[i]);
    }
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
  std::cout << "└───────┴────────────┴────────────┴────────────┘" << std::endl;
  if (this->idx != 0)
    DisplayContact();
}

void PhoneBook::DisplaySearchList(std::string contactInfo){
  int contactSize = contactInfo.length();

  if (contactSize < 10) {
    for (int i = 0; i < 12 - contactSize - 1; i++)
      std::cout << " ";
    std::cout << std::setw(contactSize)<< contactInfo << " │";
  } 
  else if (contactSize == 10) {
    std::cout << " " << std::setw(10)<< contactInfo << " │";
  }
  else {
    std::cout<< " ";
    for (int i = 0; i < 9; i++) {
      std::cout << contactInfo[i];   
    }
    std::cout << ". │";
  }
}

void PhoneBook::DisplayContact() {
  std::string inputIndex;
  int index;

  std::cout << std::endl << "Input index> ";
  while (1) {
    std::getline(std::cin, inputIndex);
    if (std::cin.eof()) {
      std::cout << "Enter EOF. Program Exit." << std::endl;
      break;
    }
    try {
      ValidateInputIndex(inputIndex);
      index = std::atoi(inputIndex.c_str());
      std::cout << "first name : " << contact[index - 1].getFirstName() << std::endl;
      std::cout << "last name : " << contact[index - 1].getLastName() << std::endl;
      std::cout << "nickname : " << contact[index - 1].getNickName() << std::endl;
      std::cout << "phone number : " << contact[index - 1].getPhoneNumber() << std::endl;
      std::cout << "darkest secret : " << contact[index - 1].getDarkestSecret() << std::endl;
      break;
    } catch (const char* message) {
      std::cout << message;
      std::cout << std::endl << "Input index> ";
    }
  }
}

void PhoneBook::ValidateInputIndex(std::string inputIndex) {
  if (inputIndex.length() != 1) throw "Invalid input\n";
  if (isdigit(inputIndex[0]) == 0) throw "Invalid input - not number\n";
  if (!(std::atoi(inputIndex.c_str()) <= 8 && std::atoi(inputIndex.c_str()) >= 1)) throw "Invalid input - Out of range\n";
  if (idx < 8 && std::atoi(inputIndex.c_str()) >= idx + 1) throw "Invalid input - Out of range\n";
}
