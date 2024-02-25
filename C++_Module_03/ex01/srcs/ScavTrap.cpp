/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:37:34 by garance           #+#    #+#             */
/*   Updated: 2024/02/25 12:21:01 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"


/* ************************ Constructor & Destructor *********************** */

ScavTrap::ScavTrap() : ClapTrap() {

    std::cout << "Default Constructor create ScavTrap named " << this->getName() << std::endl;    
    this->setHitPoints(100);
    this->setAttackDamage(20);
    this->setEnergyPoints(50);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    
    std::cout << "Name Constructor create ScavTrap named " << this->getName() << std::endl;    
    this->setHitPoints(100);
    this->setAttackDamage(20);
    this->setEnergyPoints(50);
}

ScavTrap::ScavTrap(ScavTrap const & orig) : ClapTrap(orig.getName()) {
    
    std::cout << "Copy Constructor create ScavTrap named " << this->getName() << std::endl;    
    *this = orig;
}

ScavTrap::~ScavTrap() {
    
    std::cout << "Default constructor destroyed ScavTrap named " << this->getName() << std::endl;    
}


/* ************************** Assignment Operator  ************************* */

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
    
    this->setHitPoints(rhs.ClapTrap::getHitPoints());
    this->setAttackDamage(rhs.ClapTrap::getAttackDamage());
    this->setEnergyPoints(rhs.ClapTrap::getEnergyPoints());
    return (*this);
}


/* ******************************** Accessor ******************************* */

std::string ScavTrap::getName() const {
    
    return (ClapTrap::getName()) ;
}

int ScavTrap::getHitPoints() const {
    
    return ClapTrap::getHitPoints();
}

int ScavTrap::getEnergyPoints() const {
    
    return ClapTrap::getEnergyPoints();
}

int ScavTrap::getAttackDamage() const {
    
    return ClapTrap::getAttackDamage();
}


/* **************************** Action Function **************************** */

void   ScavTrap::attack(std::string const & target) {
    
    std::cout << "ScavTrap attack";
    this->ClapTrap::attack(target);
}

void    ScavTrap::guardGate( void ) {
    
    std::cout << "ScavTrap named " << ClapTrap::getName() << " is now in Gate keeper mode!" << std::endl;
}
