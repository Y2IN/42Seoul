/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:06:25 by yje               #+#    #+#             */
/*   Updated: 2023/01/06 18:17:57 by yje              ###   ########.fr       */
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
		Contact contact[8];
		Contact CreateContact();


	public:
		void Add();
		void Search() const;
		PhoneBook();
		~PhoneBook();
};

#endif