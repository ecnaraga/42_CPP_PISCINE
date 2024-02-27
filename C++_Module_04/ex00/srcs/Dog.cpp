/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:52 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 10:59:14 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Dog::Dog() : Animal("Dog") {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
	std::cout << blue << "Default constructor create " << this->m_type << reset << std::endl;
}

Dog::Dog(Dog const & orig) : Animal(orig.m_type) {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << blue << "Copy constructor create " << this->m_type << reset << std::endl;
}

Dog::~Dog() {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << blue << "Default destructor destroy a " << this->m_type << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Dog &	Dog::operator=(Dog const & rhs) {
	
	this->m_type = rhs.m_type;
	return *this;
}

void	Dog::makeSound( void ) const {
	
	std::cout << "Waf Waf" << std::endl;
}
