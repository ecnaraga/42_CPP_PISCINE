/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:38:40 by galambey          #+#    #+#             */
/*   Updated: 2024/02/23 16:46:27 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Fixed.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

int const Fixed::_bits = 8;

Fixed::Fixed() : _rawBits(0) {
	
}

Fixed::Fixed(Fixed const & orig) {

	this->_rawBits = orig._rawBits;
}

Fixed::Fixed(int const integer) {
	
	this->setRawBits(toRawBits(integer));
}

Fixed::Fixed(float const float_nb) {

	this->setRawBits(toRawBits(float_nb));
}

Fixed::~Fixed() {}


/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

int		Fixed::getRawbits( void ) const {
	
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	
	this->_rawBits = raw;
}


/* ************************************************************************* */
/* ******************************* Conversion ****************************** */
/* ************************************************************************* */

int		Fixed::toInt( void ) const {
	
	return (this->getRawbits() >> this->_bits);
}

float	Fixed::toFloat( void ) const {
	
	float tmp = static_cast<float>(this->_rawBits);
	return (tmp / (1 << this->_bits));
}

float	Fixed::toFloat( int raw ) {
	
	float tmp = static_cast<float>(raw);
	return (tmp / (1 << _bits));
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

Fixed &	Fixed::operator=(Fixed const & rhs) {
	
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

// return en commentaire : operation sur les floats directement et non sur int 
// 		=> perte de l'avantage des fixed number

Fixed	Fixed::operator+(Fixed const & rhs) {
	
	int tmp = this->getRawbits() + rhs.getRawbits();
	return (Fixed(toFloat(tmp)));
	// return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & rhs) {
	
	int tmp = this->getRawbits() - rhs.getRawbits();
	return (Fixed(toFloat(tmp)));
	// return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed 	Fixed::operator*(Fixed const & rhs) {
	
	int tmp = (this->getRawbits() * rhs.getRawbits()) >> this->_bits ; // Comme on multiplie deux rawbits, qui on chacun ete decale vers la gauche et que le rawbit ne doit etre decale qu une fois, il faut redecaler vers la droite pour equilibre et recuperer le res en rawbit
	return (Fixed(toFloat(tmp)));
	// return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed 	Fixed::operator/(Fixed const & rhs) {
	
	if (rhs.getRawbits() == 0)
		throw ("Error : Divisor is equal to 0");
	int tmp = (this->getRawbits() << this->_bits) / (rhs.getRawbits());  // Comme on divise deux rawbits, les decalages qu on avait fait s annule, il faut redecaler vers la gauche pour recuperer le res en rawbit
	return (Fixed(toFloat(tmp)));
	// return (Fixed(this->toFloat() / rhs.toFloat()));
}

/* ************************** Comparison Operator  ************************* */

bool	Fixed::operator>(Fixed const & rhs) const {
	
	if (this->getRawbits() > rhs.getRawbits())
		return 1;
	return 0 ;
}

bool	Fixed::operator<(Fixed const & rhs) const {
	
	if (this->getRawbits() < rhs.getRawbits())
		return 1;
	return 0 ;
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	
	if (this->getRawbits() >= rhs.getRawbits())
		return 1;
	return 0 ;
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	
	if (this->getRawbits() <= rhs.getRawbits())
		return 1;
	return 0 ;
}

bool	Fixed::operator==(Fixed const & rhs) const {
	
	if (this->getRawbits() == rhs.getRawbits())
		return 1;
	return 0 ;
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	
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

Fixed &	Fixed::operator++() {
	
	this->setRawBits(this->_rawBits + 1);
	return (*this);
}

Fixed 	Fixed::operator++(int) {
	
	Fixed old(*this);

	++(*this);
	return (old);
}

Fixed &	Fixed::operator--() {
	
	this->setRawBits(this->_rawBits - 1);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	
	Fixed old(*this);
	
	--(*this);
	return (old);
}

/* ************************************************************************* */
/* ************************** OVERLOADED FUNCTIONS ************************* */
/* ************************************************************************* */

Fixed &	Fixed::min(Fixed & A, Fixed & B) {
	
	// std::cout << "min non const : " ;
	if (A < B)
	 	return (A);
	return (B);
}

Fixed const &	Fixed::min(Fixed const & A, Fixed const & B) {
	
	// std::cout << "min const : " ;
	if (A < B)
	 	return (A);
	return (B);
}

Fixed &	Fixed::max(Fixed & A, Fixed & B) {
	
	// std::cout << "max non const : " ;
	if (A > B)
	 	return (A);
	return (B);
}

Fixed const &	Fixed::max(Fixed const & A, Fixed const & B) {
	
	// std::cout << "max const : " ;
	if (A > B)
	 	return (A);
	return (B);
}
