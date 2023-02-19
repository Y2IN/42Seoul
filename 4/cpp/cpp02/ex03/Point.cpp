/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:02:43 by yje               #+#    #+#             */
/*   Updated: 2023/02/19 20:31:44 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point:: Point(): _x(0), _y(0){
}

Point::Point(const float x, const float y) :_x(x), _y(y) {
}

Point::Point(const Point& point) : _x(point.getX()), _y(point.getY()){
}

float	Point::getX() const {
	return this->_x.toFloat();
}

float	Point::getY() const {
	return this->_y.toFloat();
}

Point& Point::operator=(const Point& point) {
	(void)point;
	return *this;
}

Point::~Point(){

}

std::ostream& operator<<(std::ostream& ofs, const Point& point) {
  return ofs << "( " << point.getX() << ", " << point.getY() << " )";
}
