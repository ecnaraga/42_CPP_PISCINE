/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:38:53 by galambey          #+#    #+#             */
/*   Updated: 2024/03/05 12:03:47 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

AMateria::AMateria() {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "AMateria Virtual Default Constructor" << reset << std::endl;
}

AMateria::AMateria(AMateria const & orig) {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "AMateria Virtual Copy Constructor" << reset << std::endl;
	*this = orig;
}

AMateria::AMateria(std::string const & type) {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "AMateria Virtual Type Constructor" << reset << std::endl;
	(void) type;
}

AMateria::~AMateria() {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "AMateria Virtual Destructor" << reset << std::endl << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

AMateria & AMateria::operator=(AMateria const & rhs) {
	
	(void) rhs;
	return (*this);
}


/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const & AMateria::getType() const {

	return (this->type);
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void AMateria::use(ICharacter& target) {

	(void) target;
}
