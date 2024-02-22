/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:42:18 by galambey          #+#    #+#             */
/*   Updated: 2024/02/22 17:04:21 by galambey         ###   ########.fr       */
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

		Fixed operator+(Fixed const & rhs);
		Fixed operator-(Fixed const & rhs);
		Fixed operator*(Fixed const & rhs);
		Fixed operator/(Fixed const & rhs);

		/* ********************** Comparison Operator  ********************* */
		
		bool		operator>(Fixed const & rhs) const;
		bool		operator<(Fixed const & rhs) const;
		bool		operator>=(Fixed const & rhs) const;
		bool		operator<=(Fixed const & rhs) const;
		bool		operator==(Fixed const & rhs) const;
		bool		operator!=(Fixed const & rhs) const;
		
		/* ********************* Increment & Decrement  ******************** */
	
} ;

std::ostream &	operator<<(std::ostream & lhs, Fixed const & rhs);

float	tofloat( int raw );

#endif













// #ifndef FIXED_HPP
// # define FIXED_HPP

// #include <iostream>
// #include <cmath>

// class Fixed
// {
// 	public:
// 		Fixed(void);
// 		Fixed(Fixed const &fixed);
// 		~Fixed(void);
// 		Fixed(int const nb);
// 		Fixed(float const nb);

// 		Fixed &operator=(Fixed const &nb);
// 		Fixed operator+(Fixed const &nb);
// 		Fixed operator-(Fixed const &nb);
// 		Fixed operator*(Fixed const &nb);
// 		Fixed operator/(Fixed const &nb);

// 		Fixed &operator++(void);
// 		Fixed operator++(int);
// 		Fixed &operator--(void);
// 		Fixed operator--(int);
		
// 		bool operator<(Fixed const &nb) const;
// 		bool operator>(Fixed const &nb) const;
// 		bool operator>=(Fixed const &nb) const;
// 		bool operator<=(Fixed const &nb) const;
// 		bool operator==(Fixed const &nb) const;
// 		bool operator!=(Fixed const &nb) const;

// 		int 	getRawBits(void) const;
// 		void	setRawBits(int const raw);
// 		float 	toFloat(void) const;
// 		int 	toInt(void) const;
		
// 		Fixed static &min(Fixed &n1, Fixed &n2);
// 		Fixed const static &min(Fixed const &n1, Fixed const &n2);
// 		Fixed static &max(Fixed &n1, Fixed &n2);
// 		Fixed const static &max(Fixed const &n1, Fixed const &n2);
// 	private:
// 		int _fixed;
// 		int const static _frac;
// };

// std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

// #endif
