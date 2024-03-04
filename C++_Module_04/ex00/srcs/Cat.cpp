/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:59 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:18:41 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Cat::Cat() : Animal("Cat") {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";
	
	std::cout << purple << "Default constructor create " << this->type << reset << std::endl << std::endl;
}

Cat::Cat(Cat const & orig) : Animal(orig) {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Copy constructor create " << this->type << reset << std::endl << std::endl;
	*this = orig;
}

Cat::~Cat() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Default destructor destroy a " << this->type << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Cat &	Cat::operator=(Cat const & rhs) {
	
	(void) rhs;
	return *this;
}

void	Cat::makeSound( void ) const {
	
	std::cout << "Miaou" << std::endl;
}
