/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:59 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:18:41 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

WrongCat::WrongCat() : WrongAnimal("WrongCat") {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";
	
	std::cout << purple << "Default constructor create " << this->type << reset << std::endl << std::endl;
}

WrongCat::WrongCat(WrongCat const & orig) : WrongAnimal(orig) {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Copy constructor create " << this->type << reset << std::endl << std::endl;
	*this = orig;
}

WrongCat::~WrongCat() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Default destructor destroy a " << this->type << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

WrongCat &	WrongCat::operator=(WrongCat const & rhs) {
	
	(void) rhs;
	return *this;
}

void	WrongCat::makeSound( void ) const {
	
	std::cout << "Miaou" << std::endl;
}