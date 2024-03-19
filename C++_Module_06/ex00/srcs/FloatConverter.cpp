/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:38:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:51:40 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FloatConverter.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

FloatConverter::FloatConverter() : AConverter::AConverter() {}

FloatConverter::FloatConverter(float f) : AConverter::AConverter() {
	
	this->f = f;
	std::cout << f << std::endl;
	this->c_ok = 0;
	this->nb_ok = 0;
	toChar();
	toInt();
	toDouble();
}

FloatConverter::FloatConverter(FloatConverter const & orig) : AConverter::AConverter() { (void) orig; }

FloatConverter::~FloatConverter() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

FloatConverter & FloatConverter::operator=(FloatConverter const & rhs) {
	
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

bool	FloatConverter::isRoundFloat() const {
	return (this->f - static_cast<int>(this->f) == 0);
}

void	FloatConverter::toChar() {
	if (this->isRoundFloat() && static_cast<int>(this->f) >= 0 && static_cast<int>(this->f) <= 255) {
		this->c = static_cast<char>(this->f);
		this->c_ok = 1;
	}
}

void	FloatConverter::toInt() {
	if (this->isRoundFloat()) {
		this->nb = static_cast<int>(this->f);
		this->nb_ok = 1;
	}
}

void	FloatConverter::toFloat() {}

void	FloatConverter::toDouble() {
	if (this->f >= (std::numeric_limits<double>::max()) * -1 && this->f <= std::numeric_limits<double>::max())
		this->d = static_cast<double>(this->f);
}
