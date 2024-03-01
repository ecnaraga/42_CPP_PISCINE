/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:52 by galambey          #+#    #+#             */
/*   Updated: 2024/02/28 12:25:18 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Dog::Dog() {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
	this->m_type = "Dog";
	std::cout << blue << "Default constructor create " << this->m_type << reset << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const & orig) {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	this->m_type = orig.m_type;
	std::cout << blue << "Copy constructor create " << this->m_type << reset << std::endl;
	this->_brain = new Brain(*(orig._brain));
}

Dog::~Dog() {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << blue << "Default destructor destroy a " << this->m_type << reset << std::endl;
	delete this->_brain;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Dog &	Dog::operator=(Dog const & rhs) {
	
	this->m_type = rhs.m_type;
	*this->_brain = *rhs._brain;
	return *this;
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

void	Dog::setBrain(std::string idea) {
	
	static int i = 0;
	
	if (i < 100) {
		
		this->_brain->setIdeas(idea, i);
		i++;
	}
}

void	Dog::printBrain( void ) const {
	
	this->_brain->printIdeas();
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void	Dog::makeSound( void ) const {
	
	std::cout << "Waf Waf" << std::endl;
}
