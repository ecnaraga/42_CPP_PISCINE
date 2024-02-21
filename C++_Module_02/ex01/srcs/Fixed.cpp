/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:46:10 by galambey          #+#    #+#             */
/*   Updated: 2024/02/21 16:01:44 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"


/* ************************ Constructor & Destructor *********************** */

Fixed::Fixed() : _rawBits(0) {
	
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & orig) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed::Fixed(int const integer) {

	std::cout << "Int constructor called" << std::endl;

	this->setRawBits(toRawBits(integer));
}

Fixed::Fixed(float const float_nb) {

	std::cout << "Float constructor called" << std::endl;
	
	this->setRawBits(toRawBits(float_nb));
}

Fixed::~Fixed() {
	
	std::cout << "Destructor called" << std::endl;
}

int const		Fixed::_bits = 8;


/* ******************************** Accessor ******************************* */

int				Fixed::getRawBits( void ) const {
	
	return _rawBits ;
}

void			Fixed::setRawBits( int const raw ) {

	this->_rawBits = raw;
}


/* ******************************* Conversion ****************************** */

float		Fixed::toFloat( void ) const {

	float tmp = static_cast<float> (this->getRawBits());
	return ( tmp / (1 << this->_bits ) );		// sens inverse : <=> diviser par 2^8
												// => On remet la virgule du float au bon endroit 
}

int				Fixed::toInt( void ) const {

	return ( this->getRawBits() >> this->_bits );
}

int				Fixed::toRawBits( int const integer ) const {
	
	return ( integer << this->_bits );
}

int			Fixed::toRawBits( float float_nb) const {
	
	float tmp = (float_nb) * ( 1 << this->_bits ); 		// <=> multiplier par 2^8
												// => on deplace tous les _bits premiers chiffres decimaux a gauche de la virgule
	return ( static_cast<int>(roundf(tmp)) );	// roundf nous permet d'arrondir au float le plus proche puis on caste en int x retourner le rawbits
}


/* ************************** Operator overloading ************************* */

Fixed &			Fixed::operator=(Fixed const & rhs) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	
	this->setRawBits(rhs._rawBits);
	return ( *this );
}

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs) {
	
	return (out << rhs.toFloat());
}
