/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:42:18 by galambey          #+#    #+#             */
/*   Updated: 2024/02/21 17:55:24 by galambey         ###   ########.fr       */
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
		/* ******************** Constructor & Destructor ******************* */
		
		Fixed();
		Fixed(Fixed const & orig);
		Fixed(int const integer);
		Fixed(float const float_nb);
		~Fixed();

		/* **************************** Accessor *************************** */
		
		int		getRawbits( void ) const;
		void	setRawBits( int const raw );

		/* *************************** Conversion ************************** */
		
		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		toRawBits( int const integer ) const;
		int		toRawBits( float float_nb ) const;

		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */


		/* ********************** Assignment Operator  ********************* */
		
		Fixed & operator=(Fixed const & rhs);

		/* ********************** Arithmetic Operator  ********************* */

		float operator+(Fixed const & rhs);
		Fixed & operator-(Fixed const & rhs);
		Fixed & operator*(Fixed const & rhs);
		Fixed & operator/(Fixed const & rhs);

		/* ********************** Comparison Operator  ********************* */
		
		int		operator>(Fixed const & rhs) const;
		int		operator<(Fixed const & rhs) const;
		int		operator>=(Fixed const & rhs) const;
		int		operator<=(Fixed const & rhs) const;
		int		operator==(Fixed const & rhs) const;
		int		operator!=(Fixed const & rhs) const;
		
		/* ********************* Increment & Decrement  ******************** */
	
} ;

std::ostream &	operator<<(std::ostream & lhs, Fixed const & rhs);

#endif
