/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:52 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:18:41 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Dog::Dog() : Animal("Dog") {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
	std::cout << blue << "Default constructor create " << this->type << reset << std::endl << std::endl;
}

Dog::Dog(Dog const & orig) : Animal(orig) {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << blue << "Copy constructor create " << this->type << reset << std::endl << std::endl;
	*this = orig; 
}

Dog::~Dog() {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << blue << "Default destructor destroy a " << this->type << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Dog &	Dog::operator=(Dog const & rhs) {
	
	(void) rhs;
	return *this;
}

void	Dog::makeSound( void ) const {
	
	std::cout << "Waf Waf" << std::endl;
}
