/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:27 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 17:43:22 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

WrongAnimal::WrongAnimal() {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";
	
	if (this->m_type.empty())
		std::cout << cyan << "Default constructor create an WrongAnimal whose type's unknown" << reset << std::endl;
	else
		std::cout << cyan << "Default constructor create an WrongAnimal who's a " << this->m_type << reset << std::endl;
}

WrongAnimal::WrongAnimal(std::string const & type) : m_type(type) {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "Type constructor create an WrongAnimal who's a " << this->m_type << reset << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & orig) : m_type(orig.m_type) {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "Copy constructor create an WrongAnimal who's a " << this->m_type << reset << std::endl;
}

WrongAnimal::~WrongAnimal() {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	if (this->m_type.empty())
		std::cout << cyan << "Default destructor destroy an WrongAnimal who type's unknown" << reset << std::endl;
	else
		std::cout << cyan << "Default destructor destroy an WrongAnimal who used to be a " << this->m_type << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

WrongAnimal &				WrongAnimal::operator=(WrongAnimal const & rhs) {
	
	this->m_type = rhs.m_type;
	return *this;
}


/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const & 	WrongAnimal::getType( void ) const {
	
	return (this->m_type);
}


void	WrongAnimal::makeSound( void ) const {
	
	std::cout << "..." << std::endl;
}