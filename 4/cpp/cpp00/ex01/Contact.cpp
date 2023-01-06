/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:25:46 by yje               #+#    #+#             */
/*   Updated: 2023/01/06 18:30:54 by yje              ###   ########.fr       */
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
) : _firstName(firstName), _lastName(lastName), _nickName(nickName), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) 
{	
}

std::string Contact::getFirstName(void) const
{
	return(_firstName);
}
std::string Contact::getLastName(void) const
{
	return(_lastName);
}
std::string Contact::getNickName(void) const
{
	return(_nickName);
}
std::string Contact::getPhoneNumber(void) const
{
	return(_phoneNumber);
}
std::string Contact::getDarkestSecret(void) const
{
	return(_darkestSecret);
}