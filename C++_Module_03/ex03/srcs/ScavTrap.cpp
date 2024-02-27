/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:37:34 by garance           #+#    #+#             */
/*   Updated: 2024/02/27 12:40:05 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/* ************************ Constructor & Destructor *********************** */

ScavTrap::ScavTrap() : ClapTrap() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Default Constructor create ScavTrap named " << this->_name << reset << std::endl;    
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
    
    std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Name Constructor create ScavTrap named " << this->_name << reset << std::endl;    
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap const & orig ) : ClapTrap(orig.getName()) {
    
    std::string purple = "\e[35m";
	std::string reset = "\e[0m";

    std::cout << purple << "Copy Constructor create ScavTrap named " << this->_name << reset << std::endl;    
    *this = orig;
}

ScavTrap::~ScavTrap() {
    
    std::string purple = "\e[35m";
	std::string reset = "\e[0m";

    std::cout << purple << "Default constructor destroyed ScavTrap named " << this->_name << reset << std::endl;    
}


/* ************************** Assignment Operator  ************************* */

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {

	this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return (*this);
}


/* ******************************** Accessor ******************************* */

void    ScavTrap::setHitPoints( void ) {

    this->_hitPoints = 100;    
}

void    ScavTrap::setEnergyPoints( void ) {

    this->_energyPoints = 50;    
}

void    ScavTrap::setAttackDamage( void ) {

    this->_attackDamage = 20;
}

/* **************************** Action Function **************************** */

void   ScavTrap::attack( std::string const & target ) {
    
	this->attack_action("ScavTrap ", target);
}

void    ScavTrap::guardGate( void ) const {
    
    std::cout << "ScavTrap named " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
