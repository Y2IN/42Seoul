/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:52:19 by yje               #+#    #+#             */
/*   Updated: 2023/02/18 21:02:05 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed{
	private:
		int fix_point_n;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed (const float num);
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed); //할당 연산자 오버로딩
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
std::ostream &operator<<(std::ostream &out, const Fixed &fix);

#endif
