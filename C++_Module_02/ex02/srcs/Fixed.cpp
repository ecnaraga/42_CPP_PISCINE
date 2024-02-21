/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:00:34 by galambey          #+#    #+#             */
/*   Updated: 2024/02/21 17:58:00 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"


/* ************************ Constructor & Destructor *********************** */

Fixed::Fixed() : _rawBits(0) {
	
}

Fixed::Fixed(Fixed const & orig) {

	*this = orig;
}

Fixed::Fixed(int const integer) {
	
	this->setRawBits(toRawBits(integer));
}

Fixed::Fixed(float const float_nb) {

	this->setRawBits(toRawBits(float_nb));
}

Fixed::~Fixed() {}

int const Fixed::_bits = 8;


/* ******************************** Accessor ******************************* */

int		Fixed::getRawbits( void ) const {
	
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	
	this->_rawBits = raw;
}


/* ******************************* Conversion ****************************** */

int		Fixed::toInt( void ) const {
	
	return (this->getRawbits() >> this->_bits);
}

float	Fixed::toFloat( void ) const {
	
	float tmp = static_cast<float>(this->_rawBits);
	return (tmp / (1 << this->_bits));
}

int		Fixed::toRawBits( int const integer ) const {
	
	return ( integer << this->_bits );
}

int		Fixed::toRawBits( float float_nb ) const {

	float_nb = float_nb * (1 << this->_bits);
	return (static_cast<int>(roundf(float_nb)));
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Fixed &			Fixed::operator=(Fixed const & rhs) {
	
	this->setRawBits(rhs.getRawbits());
	return (*this);
}

/* ********************** Stream Extraction Operator  ********************** */

std::ostream & 	operator<<(std::ostream & lhs, Fixed const & rhs) {
	
	return (lhs << rhs.toFloat());
}

/* ************************** Arithmetic Operator  ************************* */

float	Fixed::operator+(Fixed const & rhs) {
	
	// (this->getRawbits() + rhs.getRawbits());
	// float	tmp = this->toFloat() + rhs.toFloat();
	// this->setRawBits(this->toRawBits(tmp));
	return (this->toFloat() + rhs.toFloat());
}

Fixed &	Fixed::operator-(Fixed const & rhs) {
	
	this->setRawBits(this->getRawbits() - rhs.getRawbits());
	return (*this);
}

Fixed &	Fixed::operator*(Fixed const & rhs) {
	
	this->setRawBits(this->getRawbits() * rhs.getRawbits());
	return (*this);
}

Fixed &	Fixed::operator/(Fixed const & rhs) {
	
	this->setRawBits(this->getRawbits() / rhs.getRawbits());
	return (*this);
}

/* ************************** Comparison Operator  ************************* */

int		Fixed::operator>(Fixed const & rhs) const {
	
	if (this->getRawbits() > rhs.getRawbits())
		return 1;
	return 0 ;
}

int		Fixed::operator<(Fixed const & rhs) const {
	
	if (this->getRawbits() < rhs.getRawbits())
		return 1;
	return 0 ;
}

int		Fixed::operator>=(Fixed const & rhs) const {
	
	if (this->getRawbits() >= rhs.getRawbits())
		return 1;
	return 0 ;
}

int		Fixed::operator<=(Fixed const & rhs) const {
	
	if (this->getRawbits() <= rhs.getRawbits())
		return 1;
	return 0 ;
}

int		Fixed::operator==(Fixed const & rhs) const {
	
	if (this->getRawbits() == rhs.getRawbits())
		return 1;
	return 0 ;
}

int		Fixed::operator!=(Fixed const & rhs) const {
	
	if (this->getRawbits() != rhs.getRawbits())
		return 1;
	return 0 ;
}

/* ************************* Increment & Decrement  ************************ */

