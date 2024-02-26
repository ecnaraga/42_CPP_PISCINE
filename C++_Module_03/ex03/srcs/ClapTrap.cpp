/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:24:43 by garance           #+#    #+#             */
/*   Updated: 2024/02/26 17:44:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/* ************************ Constructor & Destructor *********************** */

ClapTrap::ClapTrap() : _name("Robot") {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";
	
    std::cout << cyan << "Default Constructor create a ClapTrap named " << this->_name << reset << std::endl;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap( std::string const & name ) : _name(name) {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";
	
    std::cout << cyan << "Name Constructor create a ClapTrap named " << this->_name << reset << std::endl;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap( ClapTrap const & orig ) : _name(orig.getName()) {

	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";
	
    std::cout << cyan << "Copy Constructor create a ClapTrap named " << this->_name << reset << std::endl;
    *this = orig;
}

ClapTrap::~ClapTrap() {
    
	std::string cyan = "\e[36m";
	std::string reset = "\e[0m";
	
    std::cout << cyan << "Default constructor destroyed ClapTrap named " << this->_name << reset << std::endl;
}


/* ************************** Assignment Operator  ************************* */

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {
    
    this->_hitPoints = rhs.getHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_attackDamage = rhs.getAttackDamage();
    
    return (*this);
}


/* ******************************** Accessor ******************************* */

void    ClapTrap::setHitPoints( int hit ) {

    this->_hitPoints = hit;    
}

void    ClapTrap::setEnergyPoints( int energy ) {

    this->_energyPoints = energy;    
}

void    ClapTrap::setAttackDamage( int attack ) {

    this->_attackDamage = attack;
}

std::string ClapTrap::getName( void ) const {
    
    return this->_name;
}

int    ClapTrap::getHitPoints( void ) const {

    return this->_hitPoints;
}

int    ClapTrap::getEnergyPoints( void ) const {

    return this->_energyPoints;
}

int    ClapTrap::getAttackDamage( void ) const {

    return this->_attackDamage;
}


/* **************************** Action Function **************************** */

void	ClapTrap::attack_action( std::string const & message, std::string const & target ) {
	
	if (this->_energyPoints > 0) {
        this->_energyPoints--;
        std::cout << message << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }   
    else
        std::cout << message << this->_name << " couldn't attack " << target << " due to a lack of energy points" << std::endl;
}

void    ClapTrap::attack( std::string const & target ) {
    
	this->attack_action("ClapTrap ", target);
}

void    ClapTrap::takeDamage( unsigned int amount ) {
   
    if (this->_hitPoints > amount) {
        std::cout << "ClapTrap " << this->_name << " has lost " << amount << " points of hit!" << std::endl;
        this->_hitPoints -= amount;
    }
    else {
        std::cout << "ClapTrap " << this->_name << " has lost " << this->_hitPoints << " points of hit!" << std::endl;
        this->_hitPoints = 0;
    }
}

void    ClapTrap::beRepaired( unsigned int amount ) {
    
    if (this->_energyPoints > 0) { 
        std::cout << "ClapTrap " << this->_name << " has recovered "  << amount << " points of hit! He lost 1 point of energy..." << std::endl;
        this->_energyPoints--;
        this->_hitPoints += amount;
    }
    else
        std::cout << "ClapTrap " << this->_name << " couldn't repair himself due to a lack of energy points" << std::endl;
}
