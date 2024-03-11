/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:27 by galambey          #+#    #+#             */
/*   Updated: 2024/03/05 12:02:45 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

/* ************************************************************************* */
/* ****************************** Destructor ******************************* */
/* ************************************************************************* */

AAnimal::AAnimal() {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";
	
	if (this->type.empty())
		std::cout << cyan << "Default constructor create an AAnimal whose type's unknown" << reset << std::endl;
	else
		std::cout << cyan << "Default constructor create an AAnimal who's a " << this->type << reset << std::endl;
}

AAnimal::AAnimal(std::string const & type) : type(type) {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "Type constructor create an AAnimal who's a " << this->type << reset << std::endl;
}

AAnimal::AAnimal(AAnimal const & orig) : type(orig.type) {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "Copy constructor create an AAnimal who's a " << this->type << reset << std::endl;
}

AAnimal::~AAnimal() {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "Virtual destructor destroy an AAnimal who used to be a " << this->type << reset << std::endl << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs) {
	
	(void) rhs;
	return (*this);
}
/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const & 	AAnimal::getType( void ) const {
	
	return (this->type);
}
