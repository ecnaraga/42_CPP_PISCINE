/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:36:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/18 13:16:27 by galambey         ###   ########.fr       */
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

// double isDouble(std::string & s, int *err) {

// 	int i;
	
// 	if (s == "-")
// 		return (*err = 1);
// 	for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
// 	while (s[i]) {
// 		if (s[i] == '.')
// 			break;
// 		if (!isdigit(s[i]))
// 			return (*err = 1);
// 		i++;
// 	}
// 	if (s[i] == '.')
// 		i++;
// 	while (s[i]) {
// 		if (!isdigit(s[i]))
// 			return (*err = 1);
// 		i++;
// 	}
// 	double d = atof(s.c_str());
// 	return d;
// }

double isDouble(std::string & s) {

	int i;
	std::istringstream fstream(s);
	
	if (s == "-")
		return (std::numeric_limits<double>::quiet_NaN());
	for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	while (s[i]) {
		if (s[i] == '.')
			break;
		if (!isdigit(s[i]))
			return (std::numeric_limits<double>::quiet_NaN());
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i]) {
		if (!isdigit(s[i]))
			return (std::numeric_limits<double>::quiet_NaN());
		i++;
	}
	// double d = atof(s.c_str()); // pas utilise car de char * a double et non de string a double
	double d;
	fstream >> d;
	if (fstream.fail())
		return (std::numeric_limits<double>::infinity());
	return d;
}

float isFloat(std::string & s)
{
	int i;
	std::istringstream fstream(s);
	
	if (s == "-")
		return (std::numeric_limits<float>::quiet_NaN());
	for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	while (s[i]) {
		if (s[i] == '.')
			break;
		if (!isdigit(s[i]))
			return (std::numeric_limits<float>::quiet_NaN());
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i]) {
		if (s[i] == 'f')
			break;
		if (!isdigit(s[i]))
			return (std::numeric_limits<float>::quiet_NaN());
		i++;
	}
	// float f = strtof(s.c_str(), NULL);
	float f;
	fstream >> f;
	if (fstream.fail() /* || f > std::numeric_limits<float>::max() */)
		return (std::numeric_limits<float>::infinity());
	return f;
}

void ScalarConverter::convert(std::string s) {
	
	// int err = 0;
	// int n = isInt(s, &err);
	// std::cout << "n = " << n << std::endl;
	
	// double d = isDouble(s);
	// std::cout << "d = " << d << std::endl;
	
	float f = isFloat(s);
	
	// std::cout << "f = " << f << std::endl;
	std::cout << std::numeric_limits<double>::max() << " " << std::numeric_limits<double>::min() << " " << std::numeric_limits<double>::lowest() << std::endl;
	// std::cout << std::numeric_limits<double>::max() << std::endl;
	// std::cout << std::numeric_limits<float>::infinity() << std::endl;
	// std::cout << std::numeric_limits<float>::has_infinity << std::endl;
	// // 1. isInt?
	
	// // 2. isChar?

	// int err = 0
	// int n = isInt
	// if (err = 0)
	// AConverter* = new AConverter(n)
	
}

