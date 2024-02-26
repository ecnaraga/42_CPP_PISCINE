/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:09:03 by galambey          #+#    #+#             */
/*   Updated: 2024/02/23 17:53:46 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Point::Point() : _x(0), _y(0) {
	
}

Point::Point(float x, float y) : _x(x), _y(y) {
	
}

Point::Point(int x, int y) : _x(x), _y(y) {
	
}

Point::Point(Point const & orig) : _x(orig.getPoint_x()), _y(orig.getPoint_y()){
	
}

Point::~Point() {

}


/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

Fixed	Point::getPoint_x() const {
	
	return (this->_x);
}

Fixed	Point::getPoint_y() const {
	
	return (this->_y);
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* Impossible de faire un Point A = B car les attributs de Points sont constants */
Point & Point::operator=(Point const & rhs) {
	
	(void) rhs;	
	return (*this);
}

bool	Point::operator==(Point const & rhs) const {
	
	if (this->getPoint_x() == rhs.getPoint_x() && this->getPoint_y() == rhs.getPoint_y())
		return (1);
	return (0);
}

/* ************************************************************************* */
/* ************************** Overloaded Functions ************************* */
/* ************************************************************************* */

short int Point::get_sign_comp_z(Point const & a, Point const & b, Point const & m) {
			
	Fixed z;

	z = (a.getPoint_x() - m.getPoint_x()) * (b.getPoint_y() - m.getPoint_y()) - (a.getPoint_y() - m.getPoint_y()) * (b.getPoint_x() - m.getPoint_x());
	if (z < 0)
		return (-1);
	if (z > 0)
		return (1);
	return (0);
}
