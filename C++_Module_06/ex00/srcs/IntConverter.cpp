/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:38:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:17 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IntConverter.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

IntConverter::IntConverter() : AConverter::AConverter() {}

IntConverter::IntConverter(int n) : AConverter::AConverter() {
	
	this->c_ok = 0;
	this->nb_ok = 1;
	this->nb = n;
	toChar();
	toFloat();
	toDouble();
}

IntConverter::IntConverter(IntConverter const & orig) : AConverter::AConverter() { (void) orig; }

IntConverter::~IntConverter() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

IntConverter & IntConverter::operator=(IntConverter const & rhs) {
	
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

bool	IntConverter::isRoundFloat() const {
	return (1);
}

void	IntConverter::toChar() {
	if (nb >= 0 && nb <= 255) {
		this->c = static_cast<char>(this->nb);
		this->c_ok = 1;
	}
}

void	IntConverter::toInt() {}

void	IntConverter::toFloat() {
	this->f = static_cast<float>(this->nb);
}

void	IntConverter::toDouble() {
	this->d = static_cast<double>(this->nb);
}
