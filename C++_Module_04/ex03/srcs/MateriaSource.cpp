/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:03:06 by galambey          #+#    #+#             */
/*   Updated: 2024/03/01 15:38:27 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/MateriaSource.hpp"
# include "../includes/Ice.hpp"
# include "../includes/Cure.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

MateriaSource::MateriaSource() {
	
	std::string red = "\e[31m";
	std::string reset = "\e[0m";

	std::cout << red << "MateriaSource constructor" << reset << std::endl << std::endl;
	this->_known = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->_known[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & orig) {
	
	std::string red = "\e[31m";
	std::string reset = "\e[0m";

	std::cout << red << "MateriaSource constructor" << reset << std::endl << std::endl;
	this->_known = new AMateria*[4];
	*this = orig;
}

MateriaSource::~MateriaSource() {
	
	std::string red = "\e[31m";
	std::string reset = "\e[0m";

	std::cout << red << "MateriaSource destructor" << reset << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_known[i];
	delete[] _known;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	
	for(int i = 0; i < 4; i++)
		this->_known[i] = rhs._known[i]->clone();
	return *this;
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void MateriaSource::learnMateria(AMateria* materia) {
	
	static int i = 0;
	
	if (i < 4) {
		std::string const tmp = materia->getType();
		this->_known[i] = materia->clone();
		i++;
	}
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	
	for (int i = 0; i < 4; i++) {
		if (this->_known[i] && this->_known[i]->getType() == type)
			return (this->_known[i]->clone());
	}
	return NULL;
}
