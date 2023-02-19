/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:02:39 by yje               #+#    #+#             */
/*   Updated: 2023/02/19 20:29:31 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H_
#define POINT_H_

#include "Fixed.hpp"

class Point{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);
		Point& operator = (const Point& point);
		~Point();
		float getX() const;
		float getY() const;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& ofs, const Point& point);


#endif
