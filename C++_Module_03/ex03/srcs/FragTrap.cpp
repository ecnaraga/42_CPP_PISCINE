/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:52:59 by galambey          #+#    #+#             */
/*   Updated: 2024/02/26 17:20:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/* ************************ Constructor & Destructor *********************** */

FragTrap::FragTrap() : ClapTrap() {

	std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
    std::cout << blue << "Default Constructor create a FragTrap named " << this->getName() << reset << std::endl;
	this->setHitPoints();
	this->setEnergyPoints();
	this->setAttackDamage();
}

FragTrap::FragTrap( std::string const & name ) : ClapTrap(name) {
	
    std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
    std::cout << blue << "Name Constructor create a FragTrap named " << this->getName() << reset << std::endl;
	this->setHitPoints();
	this->setEnergyPoints();
	this->setAttackDamage();
}

FragTrap::FragTrap( FragTrap const & orig ) : ClapTrap(orig.getName()) {
	
    std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
    std::cout << blue << "Copy Constructor create a FragTrap named " << this->getName() << reset << std::endl;
	*this = orig;
}

FragTrap::~FragTrap() {
	
    std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
    std::cout << blue << "Default constructor destroyed FragTrap named " << this->getName() << reset << std::endl;
}

/* ************************** Assignment Operator  ************************* */

FragTrap & 	FragTrap::operator=( FragTrap const & rhs ) {
	
	this->ClapTrap::setHitPoints(rhs.ClapTrap::getHitPoints());
	this->ClapTrap::setEnergyPoints(rhs.ClapTrap::getEnergyPoints());
	this->ClapTrap::setAttackDamage(rhs.ClapTrap::getAttackDamage());
	return *this;
}

/* ******************************** Accessor ******************************* */

int    FragTrap::getHitPoints( void ) const {

    return this->ClapTrap::getHitPoints();
}

int    FragTrap::getEnergyPoints( void ) const {

    return this->ClapTrap::getEnergyPoints();
}

int    FragTrap::getAttackDamage( void ) const {

    return this->ClapTrap::getAttackDamage();
}

void    FragTrap::setHitPoints( void ) {

    this->ClapTrap::setHitPoints(100);    
}

void    FragTrap::setEnergyPoints( void ) {

    this->ClapTrap::setEnergyPoints(100);    
}

void    FragTrap::setAttackDamage( void ) {

    this->ClapTrap::setAttackDamage(30);
}

/* **************************** Action Function **************************** */

void 		FragTrap::highFivesGuys( void ) const {
	
	std::cout << "FragTrap " << this->getName() << " ask for HighFive!" << std::endl;
}


