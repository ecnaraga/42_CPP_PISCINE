/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:38:53 by galambey          #+#    #+#             */
/*   Updated: 2024/03/01 12:25:47 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "AMateria Virtual constructor" << reset << std::endl;
	(void) type;
}

AMateria::~AMateria() {
	
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";

	std::cout << cyan << "AMateria Virtual destructor" << reset << std::endl << std::endl;
	}

std::string const & AMateria::getType() const {

	return (this->m_type);
}

void AMateria::use(ICharacter& target) {

	(void) target;
}

// void AMateria::throwMateria( AMateria * materia ) {

// 	if (materia)
// 		delete[] materia;
// }