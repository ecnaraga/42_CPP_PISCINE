/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:36:29 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:56:22 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AConverter.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

AConverter::AConverter() {};

AConverter::AConverter(AConverter const & orig) { (void) orig; }

AConverter::~AConverter() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

AConverter & AConverter::operator=(AConverter const & rhs) {
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

bool AConverter::getCharOk() const {
		return (this->c_ok);
}

bool AConverter::getIntOk() const {
		return (this->nb_ok);
}

char AConverter::getChar() const {
		return (this->c);
}

int AConverter::getInt() const {
	return (this->nb);	
}

float AConverter::getFloat() const {
	return (this->f);
}

double AConverter::getDouble() const {
	return (this->d);
}
		
/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

char AConverter::isChar( std::string const & s, int *err) {
	if (s.length() > 1)
		return (*err = 1);
	return (s[0]);
}

int AConverter::isInt( std::string const & s, int *err ) {
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

float AConverter::isFloat( std::string const & s) { // REVOIR LES LIMITES
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
	std::cout << f << std::endl;
	if (fstream.fail() /* || f > std::numeric_limits<float>::max() */)
		return (std::numeric_limits<float>::infinity());
	std::cout << f << std::endl;
	return f;
}

double AConverter::isDouble( std::string const & s) { // REVOIR LES LIMITES
	
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

std::ostream & operator<<(std::ostream & oo, AConverter *rhs) {

	
	if (rhs->getCharOk())
	{
		char c = rhs->getChar();
		if (isprint(c))
			oo << "char : " << c << std::endl;
		else
			oo << "char : Non displayable"<< std::endl;
	}
	else
		oo << "char : impossible"<< std::endl;
	if (rhs->getIntOk())
		oo << "int : " << rhs->getInt() << std::endl;
	else
		oo << "int : impossible"<< std::endl;
	if (rhs->isRoundFloat())
		oo << "double : " << rhs->getDouble() << ".0" << std::endl;
	// else
	// 	oo << "double : " << rhs->getDouble() << std::endl; // CONDITIONAL JUMP
	if (rhs->isRoundFloat())
		oo << "float : " << rhs->getFloat() << ".0f" << std::endl;
	else
		oo << "float : " << rhs->getFloat() << "f" << std::endl;
	return(oo);
}
