/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:59 by galambey          #+#    #+#             */
/*   Updated: 2024/02/28 12:25:23 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Cat::Cat() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";
	
	this->m_type = "Cat";
	std::cout << purple << "Default constructor create " << this->m_type << reset << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const & orig) {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	this->m_type = orig.m_type;
	std::cout << purple << "Copy constructor create " << this->m_type << reset << std::endl;
	this->_brain = new Brain(*(orig._brain));
}

Cat::~Cat() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Default destructor destroy a " << this->m_type << reset << std::endl;
	delete this->_brain;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Cat &	Cat::operator=(Cat const & rhs) {
	
	this->m_type = rhs.m_type;
	*this->_brain = *rhs._brain;
	return *this;
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

void	Cat::setBrain(std::string idea) {
	
	static int i = 0;
	
	if (i < 100) {
		
		this->_brain->setIdeas(idea, i);
		i++;
	}
}

void	Cat::printBrain( void ) const {
	
	this->_brain->printIdeas();
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void	Cat::makeSound( void ) const {
	
	std::cout << "Miaou" << std::endl;
}
