/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:45:46 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:18:41 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Ice::Ice() : AMateria("ice") {
	
	std::string yellow = "\e[33m";
	std::string reset = "\e[0m";

	std::cout << yellow << "Ice constructor" << reset << std::endl << std::endl;
	this->type = "ice";
}

Ice::Ice(Ice const & orig) : AMateria(orig.type) {

	std::string yellow = "\e[33m";
	std::string reset = "\e[0m";

	std::cout << yellow << "Ice constructor" << reset << std::endl << std::endl;
	*this = orig;
}

Ice::~Ice() {
	
	std::string yellow = "\e[33m";
	std::string reset = "\e[0m";

	std::cout << yellow << "Ice destructor" << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Ice & Ice::operator=(Ice const & rhs) {
	
	this->type = rhs.type;
	return *this;
}

void Ice::use(ICharacter& target) {
	
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}

AMateria* Ice::clone() const{

	return new Ice(*this);
}
