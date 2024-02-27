/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:27 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 17:35:40 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Animal::Animal() {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";
	
	if (this->m_type.empty())
		std::cout << cyan << "Default constructor create an Animal whose type's unknown" << reset << std::endl;
	else
		std::cout << cyan << "Default constructor create an Animal who's a " << this->m_type << reset << std::endl;
}

Animal::Animal(std::string const & type) : m_type(type) {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "Type constructor create an Animal who's a " << this->m_type << reset << std::endl;
}

Animal::Animal(Animal const & orig) : m_type(orig.m_type) {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "Copy constructor create an Animal who's a " << this->m_type << reset << std::endl;
}

Animal::~Animal() {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	if (this->m_type.empty())
		std::cout << cyan << "Default destructor destroy an Animal who type's unknown" << reset << std::endl;
	else
		std::cout << cyan << "Default destructor destroy an Animal who used to be a " << this->m_type << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Animal &				Animal::operator=(Animal const & rhs) {
	
	this->m_type = rhs.m_type;
	return *this;
}


/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const & 	Animal::getType( void ) const {
	
	return (this->m_type);
}

void	Animal::makeSound( void ) const {
	
	std::cout << "..." << std::endl;
}