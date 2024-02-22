/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:00:34 by galambey          #+#    #+#             */
/*   Updated: 2024/02/22 17:35:09 by galambey         ###   ########.fr       */
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
	// std::cout << float_nb << "donne en rawbits : " << this->getRawbits() << std::endl;
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
	
	if (*this == rhs)
		return (*this);
	this->setRawBits(rhs.getRawbits());
	return (*this);
}

/* ********************** Stream Extraction Operator  ********************** */

std::ostream & 	operator<<(std::ostream & lhs, Fixed const & rhs) {
	
	return (lhs << rhs.toFloat());
}

/* ************************** Arithmetic Operator  ************************* */

Fixed	Fixed::operator+(Fixed const & rhs) {
	
	int tmp = this->getRawbits() + rhs.getRawbits();
	return (Fixed(tofloat(tmp)));
}

Fixed Fixed::operator-(Fixed const & rhs) {
	
	int tmp = this->getRawbits() - rhs.getRawbits();
	return (Fixed(tofloat(tmp)));
}

Fixed Fixed::operator*(Fixed const & rhs) {
	
	int tmp = (this->getRawbits() * rhs.getRawbits()) >> this->_bits ; // Comme on multiplie deux rawbits, qui on chacun ete decale vers la gauche et que le rawbit ne doit etre decale qu une fois, il faut redecaler vers la droite pour equilibre et recuperer le res en rawbit
	return (Fixed(tofloat(tmp)));
	// return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs) {
	
	
	int tmp = (this->getRawbits() << this->_bits) / (rhs.getRawbits());  // Comme on divise deux rawbits, les decalages qu on avait fait s annule, il faut redecaler vers la gauche pour recuperer le res en rawbit
	return (Fixed(tofloat(tmp)));
	// return (Fixed(this->toFloat() / rhs.toFloat()));
}

/* ************************** Comparison Operator  ************************* */

bool		Fixed::operator>(Fixed const & rhs) const {
	
	if (this->getRawbits() > rhs.getRawbits())
		return 1;
	return 0 ;
}

bool		Fixed::operator<(Fixed const & rhs) const {
	
	if (this->getRawbits() < rhs.getRawbits())
		return 1;
	return 0 ;
}

bool		Fixed::operator>=(Fixed const & rhs) const {
	
	if (this->getRawbits() >= rhs.getRawbits())
		return 1;
	return 0 ;
}

bool		Fixed::operator<=(Fixed const & rhs) const {
	
	if (this->getRawbits() <= rhs.getRawbits())
		return 1;
	return 0 ;
}

bool		Fixed::operator==(Fixed const & rhs) const {
	
	if (this->getRawbits() == rhs.getRawbits())
		return 1;
	return 0 ;
}

bool		Fixed::operator!=(Fixed const & rhs) const {
	
	if (this->getRawbits() != rhs.getRawbits())
		return 1;
	return 0 ;
}

/*
ϵ tel que 1 + ϵ > 1
Le symbole "ε" représente le plus petit nombre positif qui peut être
	représenté par le système à virgule flottante. Dans d'autres termes, c'est
	la plus petite différence entre deux nombres représentables dans ce système.
 */
/* ************************* Increment & Decrement  ************************ */

