/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:36:29 by galambey          #+#    #+#             */
/*   Updated: 2024/03/20 17:16:42 by galambey         ###   ########.fr       */
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
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

char const * AConverter::NotThatTypeException::what() const throw() {
	return ("Wrong Type");
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

char AConverter::isChar( std::string const & s) {
	if (s.length() > 1)
		throw (NotThatTypeException());
	return (s[0]);
}

int AConverter::isInt( std::string const & s ) {
	long int 	n;
	int 		digit = 0;
	int 		i;
	
	for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	while (s[i]) {
		if (!isdigit(s[i]))
			throw (NotThatTypeException());
		digit++;
		i++;
	}
	std::istringstream(s) >> n;
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max() || digit > 10)
		throw (NotThatTypeException());
	return (static_cast<int>(n));
}

/*
un float sous sa forme literale doit se terminer par un f et si il y a un point doit avoir des chiffres soit avant soit apres le point soit les deux
*/
float AConverter::isFloat( std::string const & s) {
	int i;
	int sg = 1;
	std::istringstream fstream(s);
	
	if (s == "-inff")
		return (std::numeric_limits<float>::infinity() * -1);
	if (s == "+inff")
		return (std::numeric_limits<float>::infinity());
	if (s == "nan" || s == "+inf" || s == "-inf")
		throw (NotThatTypeException());
	if (s[0] == '-')
		sg = -1;
	for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	while (s[i]) {
		if (s[i] == '.' && (isdigit(s[i - 1]) || isdigit(s[i + 1])))
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
	if (!s[i])
		throw (NotThatTypeException());
	if (s[i + 1])
		return (std::numeric_limits<float>::quiet_NaN());
	float f;
	fstream >> f;
	if (fstream.fail())
		return (std::numeric_limits<float>::infinity() * sg);
	return f;
}

/*
un double sous sa forme literale doit avoir un point et des chiffres soit avant soit apres le point soit les deux
*/
double AConverter::isDouble( std::string const & s ) {
	
	int i;
	int sg = 1;
	std::istringstream fstream(s);
	
	if (s == "-inf")
		return (std::numeric_limits<double>::infinity() * -1);
	if (s == "+inf")
		return (std::numeric_limits<double>::infinity());
	if (s[0] == '-')
		sg = -1;
	for (i = 1 * (s[0] == '-'); s[i] == '0'; i++) {}
	while (s[i]) {
		if (s[i] == '.' && (isdigit(s[i - 1]) || isdigit(s[i + 1])))
			break;
		if (!isdigit(s[i]))
			return (std::numeric_limits<double>::quiet_NaN());
		i++;
	}
	if (s[i] != '.')
		return (std::numeric_limits<double>::quiet_NaN());
	i++;
	while (s[i]) {
		if (!isdigit(s[i]))
			return (std::numeric_limits<double>::quiet_NaN());
		i++;
	}
	double d;
	fstream >> d;
	if (fstream.fail())
		return (std::numeric_limits<float>::infinity() * sg);
	return d;
}

std::ostream & operator<<(std::ostream & oo, AConverter *rhs) {

	if (rhs->getCharOk())
	{
		char c = rhs->getChar();
		if (isprint(c))
			oo << "char : '" << c << "'" << std::endl;
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
		oo << "float : " << rhs->getFloat() << ".0f" << std::endl;
	else
		oo << "float : " << rhs->getFloat() << "f" << std::endl;
	if (rhs->isRoundFloat())
		oo << "double : " << rhs->getDouble() << ".0" << std::endl;
	else
		oo << "double : " << rhs->getDouble() << std::endl; // CONDITIONAL JUMP si string
	return(oo);
}
