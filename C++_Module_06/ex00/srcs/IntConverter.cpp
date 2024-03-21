/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:38:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/20 13:51:03 by galambey         ###   ########.fr       */
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
	if (nb >= std::numeric_limits<char>::min() && nb <= std::numeric_limits<char>::max()) {
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
