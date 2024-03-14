/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:36:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/14 17:05:51 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

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

int isInt(std::string & s, int *err)
{
	long int 	n;
	int 		digit = 0;
	int 		i;
	
	if (s == "-")
		return (*err = 1);
	for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	while (s[i]) {
		if (!isdigit(s[i]))
			return (*err = 1);
		digit++;
		i++;
	}
	std::istringstream(s) >> n;
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max() || digit > 10)
		return (*err = 1);
	return (static_cast<int>(n));
}

char isChar(std::string & s, int *err)
{
	if (s.length() > 1)
		return (*err = 1);
	return (s[0]);
}

double isDouble(std::string & s, int *err)
{
	double d;
	// int 		digit = 0;
	// int 		i;
	
	// if (s == "-")
	// 	return (*err = 1);
	// for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	// while (s[i]) {
	// 	if (!isdigit(s[i]))
	// 		return (*err = 1);
	// 	i++;
	// }
	// while (s[i]) {
	// 	if (!isdigit(s[i]))
	// 		return (*err = 1);
	// 	i++;
	// }
	try {
	std::istringstream(s) >> d;
	// if (d < std::numeric_limits<double>::lowest() || d > std::numeric_limits<double>::max())
	// 	return (*err = 1);
	return (static_cast<double>(d));
	}
	catch (std::exception &e) 
	{
		std::cout << "bad double" << std::endl;
		return (*err = 1);
	}
}

float isFloat(std::string & s, int *err)
{
	float d;
	// int 		digit = 0;
	// int 		i;
	
	// if (s == "-")
	// 	return (*err = 1);
	// for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	// while (s[i]) {
	// 	if (!isdigit(s[i]))
	// 		return (*err = 1);
	// 	i++;
	// }
	// while (s[i]) {
	// 	if (!isdigit(s[i]))
	// 		return (*err = 1);
	// 	i++;
	// }
	try {
	std::istringstream(s) >> d;
	// if (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max())
	// 	return (*err = 1);
	d = 4.3;
	return (static_cast<float>(d));
	}
	catch (std::exception &e) 
	{
		std::cout << "bad float" << std::endl;
		return (*err = 1);
	}
}

void ScalarConverter::convert(std::string s) {
	
	int err = 0;
	int n = isInt(s, &err);
	err = 0;
	err = 0;
	double d = isDouble(s, &err);
	err = 0;
	float f = isFloat(s, &err);
	
	std::cout << "n = " << n << " et err = " << err << std::endl;
	std::cout << "d = " << d << " et err = " << err << std::endl;
	std::cout << "f = " << f << " et err = " << err << std::endl;
	std::cout << std::numeric_limits<float>::max() << " et err = " << err << std::endl;
	// 1. isInt?
	
	// 2. isChar?
	err = 0;
}

