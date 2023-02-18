/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:41:28 by yje               #+#    #+#             */
/*   Updated: 2023/02/18 19:50:43 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : fix_point_n(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	// b = a;
}

Fixed& Fixed:: operator=(const Fixed& fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->fix_point_n = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this -> fix_point_n);
}

void Fixed::setRawBits(int const raw){
	this->fix_point_n  = raw;
}
