/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:52:59 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 12:39:31 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/* ************************ Constructor & Destructor *********************** */

FragTrap::FragTrap() : ClapTrap() {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << blue << "Default Constructor create a FragTrap named " << this->getName() << reset << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( std::string const & name ) : ClapTrap(name) {
	
    std::string blue = "\e[34m";
	std::string reset = "\e[0m";

	std::cout << blue << "Name Constructor create a FragTrap named " << this->_name << reset << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const & orig ) : ClapTrap(orig._name) {
	
    std::string blue = "\e[34m";
	std::string reset = "\e[0m";

    std::cout << blue << "Copy Constructor create a FragTrap named " << this->_name << reset << std::endl;
	*this = orig;
}

FragTrap::~FragTrap() {
	
    std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
    std::cout << blue << "Default constructor destroyed FragTrap named " << this->_name << reset << std::endl;
}

/* ************************** Assignment Operator  ************************* */

FragTrap & 	FragTrap::operator=( FragTrap const & rhs ) {
	
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

/* ******************************** Accessor ******************************* */

void    FragTrap::setHitPoints( void ) {

    this->_hitPoints = 100;    
}

void    FragTrap::setEnergyPoints( void ) {

    this->_energyPoints = 100;    
}

void    FragTrap::setAttackDamage( void ) {

    this->_attackDamage = 30;
}

/* **************************** Action Function **************************** */

void 		FragTrap::highFivesGuys( void ) const {
	
	std::cout << "FragTrap " << this->_name << " ask for HighFive!" << std::endl;
}


