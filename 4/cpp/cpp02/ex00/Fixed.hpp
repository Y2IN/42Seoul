/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:18:04 by yje               #+#    #+#             */
/*   Updated: 2023/02/20 18:40:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_H_
# define FIXED_H_

#include <iostream>

class Fixed {
	private:
		int fix_point_n;
		static const int fractional_bits = 8;

	public:
		/*
		기본 생성자 -> 0으로 초기화, 기본 소멸자, 복사생성자, 할당 연산자 오버로딩
		*/
		Fixed(); //기본생성자
		/*
		별도로 생성자를 구현하지 않을 시 사용되는 생성자. 매개 변수 없음.
		멤버 변수가 0, NULL 등으로 초기화 됨.
		*/
		Fixed(const Fixed& fixed); //복사 생성자
		/*
		다른 참조자를 인수로 받아 그 참조를 이용하여 자기를 초기회(깊은 복사)
    	(깊은 복사 : '실제 값'을 새로운 메모리 공간에 복사) - 독립적
    	(얕은 복사 : '주소 값'을 복사)
		*/
		Fixed& operator=(const Fixed& fixed); //할당 연산자 오버로딩
		/*
		할당 연산자는 a=b의 형태의 동작에서 b를 인자로 받아 a에 대한 참조를 반환하도록 만든다.
		*/
		~Fixed(); // 소멸자
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif
