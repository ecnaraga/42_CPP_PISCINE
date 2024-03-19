/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:38:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:17 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DoubleConverter.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

DoubleConverter::DoubleConverter() : AConverter::AConverter() {}

DoubleConverter::DoubleConverter(double d) : AConverter::AConverter() {
	
	this->d = d;
	this->c_ok = 0;
	this->nb_ok = 0;
	toChar();
	toInt();
	toFloat();
}

DoubleConverter::DoubleConverter(DoubleConverter const & orig) : AConverter::AConverter() { (void) orig; }

DoubleConverter::~DoubleConverter() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

DoubleConverter & DoubleConverter::operator=(DoubleConverter const & rhs) {
	
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

bool	DoubleConverter::isRoundFloat() const {
	return (this->d - static_cast<int>(this->d) == 0);
}

void	DoubleConverter::toChar() {
	if (this->isRoundFloat() && static_cast<int>(this->d) >= 0 && static_cast<int>(this->d) <= 255)
		this->c = static_cast<char>(this->d);
}

void	DoubleConverter::toInt() {
	if (this->isRoundFloat())
		this->nb = static_cast<int>(this->d);
}

void	DoubleConverter::toFloat() {
	this->f = static_cast<float>(this->d);
}

void	DoubleConverter::toDouble() {}
