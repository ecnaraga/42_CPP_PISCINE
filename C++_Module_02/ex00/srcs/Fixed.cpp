/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:15:00 by galambey          #+#    #+#             */
/*   Updated: 2024/02/20 15:27:17 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

/* ***************************** CONSTRUCTEURS ***************************** */

Fixed::Fixed() {
	
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed& original) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

/* ************************** SURCHARGE OPERATEUR ************************** */

Fixed & Fixed::operator=(Fixed const & rhs) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	this->_RawBits = rhs.getRawBits();
	return (*this);
}

/* ****************************** DESTRUCTEURS ***************************** */

Fixed::~Fixed() {
	
	std::cout << "Destructor called" << std::endl;
}


/* ************************************************************************* */

const int	Fixed::_NbBits = 8; // Declaration d un attribut non membre

/* **************************** MEMBER FUNCTION **************************** */

int	Fixed::getRawBits(void) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_RawBits);
}

void Fixed::setRawBits(int const raw) {
	
	this->_RawBits = raw;
}