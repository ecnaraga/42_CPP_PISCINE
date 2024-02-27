/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:09:00 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 12:37:46 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"


/* ************************ Constructor & Destructor *********************** */

DiamondTrap::DiamondTrap() : ClapTrap("Robot_clap_name"), ScavTrap(), _name("Robot") {

	std::string red = "\e[31m";
	std::string reset = "\e[0m";
	
    std::cout << red << "Default Constructor create a DiamondTrap named " << this->_name << reset << std::endl;
	this->FragTrap::setHitPoints();
	this->ScavTrap::setEnergyPoints();
	this->FragTrap::setAttackDamage();
}

DiamondTrap::DiamondTrap( std::string const & name ) : ClapTrap(name + "_clap_name"), _name(name) {
	
    std::string red = "\e[31m";
	std::string reset = "\e[0m";
	
    std::cout << red << "Name Constructor create a DiamondTrap named " << this->_name << reset << std::endl;
	this->FragTrap::setHitPoints();
	this->ScavTrap::setEnergyPoints();
	this->FragTrap::setAttackDamage();
}

DiamondTrap::DiamondTrap( DiamondTrap const & orig ) : ClapTrap(orig._name + "_clap_name"), _name(orig._name) {
	
    std::string red = "\e[31m";
	std::string reset = "\e[0m";
	
    std::cout << red << "Copy Constructor create a DiamondTrap named " << this->_name << reset << std::endl;
	*this = orig;
}

DiamondTrap::~DiamondTrap() {
	
    std::string red = "\e[31m";
	std::string reset = "\e[0m";
	
    std::cout << red << "Default constructor destroyed DiamondTrap named " << this->_name << reset << std::endl;
}


/* ************************** Assignment Operator  ************************* */

DiamondTrap & 	DiamondTrap::operator=( DiamondTrap const & rhs ) {
	
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}


/* ******************************** Accessor ******************************* */

std::string		DiamondTrap::getName( void ) const {
	
	return this->_name;
}

/* **************************** Action Function **************************** */

void DiamondTrap::whoAmI( void ) const {
	
	std::cout << this->_name << " has a ClapTrap named " << this->ClapTrap::getName() << " !!" << std::endl; 
}