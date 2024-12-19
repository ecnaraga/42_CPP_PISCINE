/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:38:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/20 13:50:13 by galambey         ###   ########.fr       */
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
	if (this->isRoundFloat() && static_cast<int>(this->d) >= std::numeric_limits<char>::min()
		&& static_cast<int>(this->d) <= std::numeric_limits<char>::max())
	{
		this->c = static_cast<char>(this->d);
		this->c_ok = 1;
	}
}

void	DoubleConverter::toInt() {
	if (this->isRoundFloat()) {
		this->nb = static_cast<int>(this->d);
		this->nb_ok = 1;
	}
}

void	DoubleConverter::toFloat() {
	this->f = static_cast<float>(this->d);
}

void	DoubleConverter::toDouble() {}
