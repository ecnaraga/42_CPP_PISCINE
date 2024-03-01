/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:01:19 by galambey          #+#    #+#             */
/*   Updated: 2024/02/29 17:52:28 by galambey         ###   ########.fr       */
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
	this->m_type = "cure";
}

Cure::Cure(Cure const & orig) : AMateria(orig.m_type) {

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
	
	this->m_type = rhs.m_type;
	return *this;
}

void Cure::use(ICharacter& target) {
	
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}

AMateria* Cure::clone() const {
	
	return new Cure(*this);
}