/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:10:08 by yje               #+#    #+#             */
/*   Updated: 2023/02/19 20:22:03 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
ay*bz - az*by, az*bx - ax*bz, ax*by - ay*bx
* 2차원 평면에서 벡터의 외적 구하는 공식 : ax*by - ay*bx
*/

float	is_area(Point const s1, Point const s2, Point const s3) {
	float area = (s1.getX() * s2.getY() + s2.getX() * s3.getY() \
				+ s3.getX() * s1.getY()) - (s1.getX() * s3.getY() \
				+ s3.getX() * s2.getY() + s2.getX() * s1.getY());
	if (area < 0)
		area *= -1;
	return (area / 2);

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area, a_tmp, b_tmp, c_tmp;

	if ((area = (is_area(a, b, c))) == 0)
		return (false);
	if ((a_tmp = is_area(point, b, c)) == 0)
		return (false);
	if ((b_tmp = is_area(a, point, c)) == 0)
		return (false);
	if ((c_tmp = is_area(a, b, point)) == 0)
		return (false);
	if (area == a_tmp + b_tmp + c_tmp)
		return (true);
	else
		return (false);
}
