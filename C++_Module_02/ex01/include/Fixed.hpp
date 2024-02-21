/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:05:46 by galambey          #+#    #+#             */
/*   Updated: 2024/02/21 15:42:51 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed {

	private:
		int	_rawBits;
		static int const	_bits;
			
	public:

		/* ******************** Constructor & Destructor ******************* */

		Fixed();
		Fixed(Fixed const & orig);
		Fixed(int const integer);
		Fixed(float const float_nb);
		~Fixed();
		
		/* **************************** Accessor *************************** */
		
		int			getRawBits(void) const;
		void		setRawBits( int const raw );

		/* *************************** Conversion ************************** */

		float 		toFloat( void )	const;
		int 		toInt( void )	const;
		int			toRawBits( float const integer ) const;
		int			toRawBits( int const integer ) const;

		/* ********************** Operator overloading ********************* */
		
		Fixed &		operator=(Fixed const & rhs);
} ;

std::ostream & 		operator<<(std::ostream & out, Fixed const & rhs);

#endif
