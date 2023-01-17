/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:06:25 by yje               #+#    #+#             */
/*   Updated: 2023/01/17 10:30:15 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKHPP
# define PHONEBOOKHPP

#include "Contact.hpp"
#include <iostream>
#include <string>
class PhoneBook
{
	private:
		int idx;
		void    DisplaySearchList(std::string contactInfo);
		void    DisplayContact();
		Contact contact[8];
		Contact CreateContact();


	public:
		void Add();
		void Search();
		PhoneBook();
		~PhoneBook();
};

#endif