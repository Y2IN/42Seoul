/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:25:12 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 19:58:40 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H_
#define WRONGCAT_H_

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
    //  A default constructor
    WrongCat();
    // * A copy constructor
    WrongCat(const WrongCat& wrongCat);
    // * A assignment operator overload
    WrongCat&	operator=(const WrongCat& wrongCat);
    // * A destructor
    virtual ~WrongCat();

    void makeSound() const;
};

# endif
