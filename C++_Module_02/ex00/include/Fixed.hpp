/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:15:07 by galambey          #+#    #+#             */
/*   Updated: 2024/02/21 10:27:11 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class 	Fixed {
	
	private : 
		int _RawBits;
		static const int _NbBits;

	public :
		Fixed();								// Constructeur par default
		Fixed(Fixed const & original); 			// Constructeur de recopie
		Fixed & operator=(Fixed const & rhs);
		~Fixed();								// Destructeur
		int 	getRawBits( void ) const; 		// Accessor
		void	setRawBits( int const raw ); 	// Accessor
} ;

#endif