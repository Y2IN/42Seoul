/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:51:07 by yje               #+#    #+#             */
/*   Updated: 2023/03/20 11:07:29 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>
#include"AForm.hpp"

class Intern {
    private :
        std::string form[3];
    public:
        Intern();
        Intern(Intern&);
        Intern&	operator=(const Intern& ref);
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
};

#endif