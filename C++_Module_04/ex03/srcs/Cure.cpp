/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:01:19 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:18:41 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Cure::Cure() : AMateria("cure") {
	
	std::string green = "\e[32m";
	std::string reset = "\e[0m";

	std::cout << green << "Cure constructor" << reset << std::endl << std::endl;
	this->type = "cure";
}

Cure::Cure(Cure const & orig) : AMateria(orig.type) {

	std::string green = "\e[32m";
	std::string reset = "\e[0m";

	std::cout << green << "Cure constructor" << reset << std::endl << std::endl;
	*this = orig;
}

Cure::~Cure() {
	
	std::string green = "\e[32m";
	std::string reset = "\e[0m";

	std::cout << green << "Cure destructor" << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Cure & Cure::operator=(Cure const & rhs) {
	
	this->type = rhs.type;
	return *this;
}

void Cure::use(ICharacter& target) {
	
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}

AMateria* Cure::clone() const {
	
	return new Cure(*this);
}