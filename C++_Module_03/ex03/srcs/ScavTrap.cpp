/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:37:34 by garance           #+#    #+#             */
/*   Updated: 2024/02/26 17:13:25 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/* ************************ Constructor & Destructor *********************** */

ScavTrap::ScavTrap() : ClapTrap() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

    std::cout << purple << "Default Constructor create ScavTrap named " << this->getName() << reset << std::endl;    
    this->setHitPoints();
    this->setAttackDamage();
    this->setEnergyPoints();
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
    
    std::string purple = "\e[35m";
	std::string reset = "\e[0m";

    std::cout << purple << "Name Constructor create ScavTrap named " << this->getName() << reset << std::endl;    
    this->setHitPoints();
    this->setAttackDamage();
    this->setEnergyPoints();
}

ScavTrap::ScavTrap( ScavTrap const & orig ) : ClapTrap(orig.getName()) {
    
    std::string purple = "\e[35m";
	std::string reset = "\e[0m";

    std::cout << purple << "Copy Constructor create ScavTrap named " << this->getName() << reset << std::endl;    
    *this = orig;
}

ScavTrap::~ScavTrap() {
    
    std::string purple = "\e[35m";
	std::string reset = "\e[0m";

    std::cout << purple << "Default constructor destroyed ScavTrap named " << this->getName() << reset << std::endl;    
}


/* ************************** Assignment Operator  ************************* */

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
    
    this->ClapTrap::setHitPoints(rhs.ClapTrap::getHitPoints());
    this->ClapTrap::setAttackDamage(rhs.ClapTrap::getAttackDamage());
    this->ClapTrap::setEnergyPoints(rhs.ClapTrap::getEnergyPoints());
    return (*this);
}


/* ******************************** Accessor ******************************* */

int    ScavTrap::getHitPoints( void ) const {

    return this->ClapTrap::getHitPoints();
}

int    ScavTrap::getEnergyPoints( void ) const {

    return this->ClapTrap::getEnergyPoints();
}

int    ScavTrap::getAttackDamage( void ) const {

    return this->ClapTrap::getAttackDamage();
}

void    ScavTrap::setHitPoints( void ) {

    this->ClapTrap::setHitPoints(100);    
}

void    ScavTrap::setEnergyPoints( void ) {

    this->ClapTrap::setEnergyPoints(50);    
}

void    ScavTrap::setAttackDamage( void ) {

    this->ClapTrap::setAttackDamage(20);
}

/* **************************** Action Function **************************** */

void   ScavTrap::attack( std::string const & target ) {
    
	this->ClapTrap::attack_action("ScavTrap ", target);
}

void    ScavTrap::guardGate( void ) const {
    
    std::cout << "ScavTrap named " << ClapTrap::getName() << " is now in Gate keeper mode!" << std::endl;
}
