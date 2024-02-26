/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:42:44 by galambey          #+#    #+#             */
/*   Updated: 2024/02/26 09:52:57 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	
	private :
		Fixed const _x;
		Fixed const _y;

	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		Point();
		Point(float const x, float const y);
		Point(int x, int y);
		Point(Point const &);
		~Point();

		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		Fixed	getPoint_x() const;
		Fixed	getPoint_y() const;
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		Point & operator=(Point const & rhs);
		bool	operator==(Point const & rhs) const;

		/* ***************************************************************** */
		/* ********************** Overloaded Functions ********************* */
		/* ***************************************************************** */

		// static Fixed *min_x(Point const & a, Point const & b, Point const & c);
		// static Fixed *min_y(Point const & a, Point const & b, Point const & c);
		// static Fixed *max_x(Point const & a, Point const & b, Point const & c);
		// static Fixed *max_y(Point const & a, Point const & b, Point const & c);

		/* Determine orientation de l 'angle A⃗MB */
		static short int get_sign_comp_z(Point const & a, Point const & b, Point const & m);
} ;

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
