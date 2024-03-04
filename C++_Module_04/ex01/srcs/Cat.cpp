/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:25:59 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 13:04:53 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Cat::Cat() : Animal("Cat") {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";
	
	std::cout << purple << "Default constructor create " << this->type << reset << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const & orig) : Animal(orig) {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Copy constructor create " << this->type << reset << std::endl;
	this->_brain = new Brain(*(orig._brain));
}

Cat::~Cat() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Default destructor destroy a " << this->type << reset << std::endl;
	delete this->_brain;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Cat &	Cat::operator=(Cat const & rhs) {
	
	this->type = rhs.type;
	*this->_brain = *rhs._brain;
	return *this;
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

void	Cat::setBrain(std::string idea) {
	
	this->_brain->setIdeas(idea);
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
