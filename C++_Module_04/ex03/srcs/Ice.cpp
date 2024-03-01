/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:45:46 by galambey          #+#    #+#             */
/*   Updated: 2024/02/29 17:51:51 by galambey         ###   ########.fr       */
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
	this->m_type = "ice";
}

Ice::Ice(Ice const & orig) : AMateria(orig.m_type) {

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
	
	this->m_type = rhs.m_type;
	return *this;
}

void Ice::use(ICharacter& target) {
	
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}

AMateria* Ice::clone() const{

	return new Ice(*this);
}
