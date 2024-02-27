/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:59 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 13:58:48 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

WrongCat::WrongCat() : WrongAnimal("WrongCat") {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";
	
	std::cout << purple << "Default constructor create " << this->m_type << reset << std::endl;
}

WrongCat::WrongCat(WrongCat const & orig) : WrongAnimal(orig.m_type) {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Copy constructor create " << this->m_type << reset << std::endl;
}

WrongCat::~WrongCat() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Default destructor destroy a " << this->m_type << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

WrongCat &	WrongCat::operator=(WrongCat const & rhs) {
	
	this->m_type = rhs.m_type;
	return *this;
}

void	WrongCat::makeSound( void ) const {
	
	std::cout << "Miaou" << std::endl;
}