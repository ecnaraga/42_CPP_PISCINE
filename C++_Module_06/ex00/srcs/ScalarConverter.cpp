/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:36:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/20 16:48:52 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/IntConverter.hpp"
#include "../includes/CharConverter.hpp"
#include "../includes/DoubleConverter.hpp"
#include "../includes/FloatConverter.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & orig) { (void) orig; }

ScalarConverter::~ScalarConverter() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) {
	
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void ScalarConverter::convert(std::string s) {
	
	if (s.empty())
		return;
	try {
		AConverter *convert = new CharConverter(AConverter::isChar(s));
		std::cout << convert;
		delete convert;
		return ;
	}
	catch (std::exception & e) {}
	try {
		AConverter *convert = new IntConverter(AConverter::isInt(s));
		std::cout << convert;
		delete convert;
		return ;
	}
	catch (std::exception & e) {}
	try {
		AConverter *convert = new FloatConverter(AConverter::isFloat(s));
		std::cout << convert;
		delete convert;
		return ;
	}
	catch (std::exception & e) {}
	AConverter *convert = new DoubleConverter(AConverter::isDouble(s));
	std::cout << convert;
	delete convert;
}
