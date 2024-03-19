/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:38:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:17 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CharConverter.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

CharConverter::CharConverter() : AConverter::AConverter() {}

CharConverter::CharConverter(char c) : AConverter::AConverter() {
	
	this->c = c;
	this->c_ok = 1;
	toInt();
	this->nb_ok = 1;
	toFloat();
	toDouble();
}

CharConverter::CharConverter(CharConverter const & orig) : AConverter::AConverter() { (void) orig; }

CharConverter::~CharConverter() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

CharConverter & CharConverter::operator=(CharConverter const & rhs) {
	
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

bool	CharConverter::isRoundFloat() const {
	return (1);
}

void	CharConverter::toChar() {}

void	CharConverter::toInt() {
	this->nb = static_cast<int>(this->c);
}

void	CharConverter::toFloat() {
	this->f = static_cast<float>(this->c);
}

void	CharConverter::toDouble() {
	this->d = static_cast<double>(this->c);
}
