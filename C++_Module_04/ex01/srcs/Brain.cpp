/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:00:00 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 13:03:23 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Brain::Brain() {
	
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
	std::cout << green << "Default constructor create a Brain" << reset << std::endl << std::endl;
}

Brain::Brain(Brain const & orig) {
	
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
	std::cout << green << "Copy constructor create a Brain" << reset << std::endl << std::endl;
	*this = orig;
}

Brain::~Brain() {
	
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
	std::cout << green << "Default destructor destroy a Brain" << reset << std::endl;
}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Brain &	Brain::operator=(Brain const & rhs) {

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

void	Brain::setIdeas(std::string idea) {
	
	for (int i = 0; i < 100; i++) {
		if (this->_ideas[i].empty()) {
			this->_ideas[i] = idea;
			return ;
		}	
	}
	std::cout << "My Brain's already full of ideas" << std::endl;
}

void	Brain::printIdeas( void ) const {
	
	for (int i = 0; i < 100 ; i++) {
		if (_ideas[i].empty())
			continue ;
		std::cout << _ideas[i] << std::endl;
	}
}
