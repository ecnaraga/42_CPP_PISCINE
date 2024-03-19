/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:38:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/18 14:40:54 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DoubleConverter.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

IntConverter::IntConverter() {}

IntConverter::IntConverter(int n) {
	
	this->nb = n;
	toChar();
	toFloat();
	toDouble();
}

IntConverter::IntConverter(IntConverter const & orig) { (void) orig; }

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

void	IntConverter::toChar() {
	if (nb >= 0 && nb <= 255)
		this->c = static_cast<char>(this->nb);
}

void	IntConverter::toInt() {}

void	IntConverter::toFloat() {
	this->f = static_cast<float>(this->nb);
}

void	IntConverter::toDouble() {
	this->d = static_cast<double>(this->nb);
}
