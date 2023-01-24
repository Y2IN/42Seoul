/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:25:46 by yje               #+#    #+#             */
/*   Updated: 2023/01/24 17:59:17 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact
(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string darkestSecret
) : _firstName(firstName), _lastName(lastName), _nickName(nickName), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {
}

Contact::Contact() {
	*this = Contact("", "", "", "", "");
}

Contact::~Contact() {
}

std::string Contact::getFirstName(void)
{
	return(_firstName);
}
std::string Contact::getLastName(void)
{
	return(_lastName);
}
std::string Contact::getNickName(void)
{
	return(_nickName);
}
std::string Contact::getPhoneNumber(void)
{
	return(_phoneNumber);
}
std::string	Contact::getDarkestSecret(void) 
{
	return(_darkestSecret);
}