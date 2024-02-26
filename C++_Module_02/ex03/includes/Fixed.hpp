/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:38:15 by galambey          #+#    #+#             */
/*   Updated: 2024/02/23 12:08:40 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	
	private :
		int _rawBits;
		static int const _bits;
	
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		Fixed();
		Fixed(Fixed const & orig);
		Fixed(int const integer);
		Fixed(float const float_nb);
		~Fixed();

		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */
		
		int						getRawbits( void ) const;
		void					setRawBits( int const raw );

		/* ***************************************************************** */
		/* *************************** Conversion ************************** */
		/* ***************************************************************** */
		
		int						toInt( void ) const;
		float					toFloat( void ) const;
		static float 			toFloat(int raw);
		int						toRawBits( int const integer ) const;
		int						toRawBits( float float_nb ) const;

		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Fixed & 				operator=(Fixed const & rhs);

		/* ********************** Arithmetic Operator ********************** */

		Fixed 					operator+(Fixed const & rhs);
		Fixed 					operator-(Fixed const & rhs);
		Fixed 					operator*(Fixed const & rhs);
		Fixed 					operator/(Fixed const & rhs);

		/* ********************** Comparison Operator ********************** */
		
		bool					operator>(Fixed const & rhs) const;
		bool					operator<(Fixed const & rhs) const;
		bool					operator>=(Fixed const & rhs) const;
		bool					operator<=(Fixed const & rhs) const;
		bool					operator==(Fixed const & rhs) const;
		bool					operator!=(Fixed const & rhs) const;
		
		/* ********************* Increment & Decrement ********************* */
		
		Fixed &					operator++();
		Fixed 					operator++(int);
		Fixed &					operator--();
		Fixed 					operator--(int);

		/* ***************************************************************** */
		/* ********************** Overloaded Functions ********************* */
		/* ***************************************************************** */

		static Fixed & 			min(Fixed & A, Fixed & B);
		static Fixed const & 	min(Fixed const & A, Fixed const & B);
		static Fixed & 			max(Fixed & A, Fixed & B);
		static Fixed const & 	max(Fixed const & A, Fixed const & B);

		/* ***************************************************************** */
		/* ***************************** Other ***************************** */
		/* ***************************************************************** */

} ;

std::ostream &	operator<<(std::ostream & lhs, Fixed const & rhs);

#endif
