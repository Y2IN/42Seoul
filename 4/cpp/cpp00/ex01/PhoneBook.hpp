/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:06:25 by yje               #+#    #+#             */
/*   Updated: 2023/01/24 17:10:17 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
  private:
    Contact CreateContact();
    Contact contact[8];
    int     idx;
    void    DisplaySearchList(std::string contactInfo);
    void    DisplayContact();
    void    ValidateInputIndex(std::string inputIndex);

  public:
    PhoneBook();
    ~PhoneBook();
    void  Add();
    void  Search();
};

#endif