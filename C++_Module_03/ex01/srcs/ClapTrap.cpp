/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:24:43 by garance           #+#    #+#             */
/*   Updated: 2024/02/25 12:10:09 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/* ************************ Constructor & Destructor *********************** */

ClapTrap::ClapTrap() : _Name("Robot") {

    std::cout << "Default Constructor create a ClassTrap named " << this->_Name << std::endl;
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string const & name) : _Name(name) {

    std::cout << "Name Constructor create a ClassTrap named " << this->_Name << std::endl;
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & orig) : _Name(orig.getName()) {

    std::cout << "Copy Constructor create a ClassTrap named " << this->_Name << std::endl;
    *this = orig;
}

ClapTrap::~ClapTrap() {
    
    std::cout << this->_Name << " has been destroyed" << std::endl;
}


/* ************************** Assignment Operator  ************************* */

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
    
    this->_HitPoints = rhs.getHitPoints();
    this->_EnergyPoints = rhs.getEnergyPoints();
    this->_AttackDamage = rhs.getAttackDamage();
    
    return (*this);
}


/* ******************************** Accessor ******************************* */

void    ClapTrap::setHitPoints(int hit) {

    this->_HitPoints = hit;    
}

void    ClapTrap::setEnergyPoints(int energy) {

    this->_EnergyPoints = energy;    
}

void    ClapTrap::setAttackDamage(int attack) {

    this->_AttackDamage = attack;
}

std::string ClapTrap::getName(void) const {
    
    return this->_Name;
}

int    ClapTrap::getHitPoints(void) const {

    return this->_HitPoints;
}

int    ClapTrap::getEnergyPoints(void) const {

    return this->_EnergyPoints;
}

int    ClapTrap::getAttackDamage(void) const {

    return this->_AttackDamage;
}


/* **************************** Action Function **************************** */

void    ClapTrap::attack(const std::string & target) {
    
    if (this->_EnergyPoints > 0) {
        this->_EnergyPoints--;
        std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
    }   
    else
        throw (this->_Name);
}

void    ClapTrap::takeDamage(unsigned int amount) {
   
    if (this->_HitPoints > amount) 
        this->_HitPoints -= amount;
    else
        this->_HitPoints = 0;
    std::cout << "ClapTrap " << this->_Name << " has lost " << amount << " points of hit!" << std::endl;
    
}
void    ClapTrap::beRepaired(unsigned int amount) {
    
    if (this->_EnergyPoints > 0) { 
        std::cout << "ClapTrap has recovered "  << amount << "points of hit! He lost 1 point of energy..." << std::endl;
        this->_EnergyPoints--;
        this->_HitPoints += amount;
    }
    else
        throw (this->_Name);
}
