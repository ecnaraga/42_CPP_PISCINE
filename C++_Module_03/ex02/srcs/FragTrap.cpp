/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:52:59 by galambey          #+#    #+#             */
/*   Updated: 2024/02/26 17:21:09 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/* ************************ Constructor & Destructor *********************** */

FragTrap::FragTrap() : ClapTrap() {

    std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
    std::cout << blue << "Default Constructor create a FragTrap named " << this->getName() << reset << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap( std::string const & name ) : ClapTrap(name) {
	
    std::string blue = "\e[34m";
	std::string reset = "\e[0m";
	
    std::cout << blue << "Name Constructor create a FragTrap named " << this->getName() << reset << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
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
	
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}


/* **************************** Action Function **************************** */

void 		FragTrap::highFivesGuys( void ) const {
	
	std::cout << "FragTrap " << this->getName() << " ask for HighFive!" << std::endl;
}


