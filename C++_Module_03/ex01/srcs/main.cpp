/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:18 by garance           #+#    #+#             */
/*   Updated: 2024/02/27 13:31:54 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
    
    std::string cyan = "\e[36m";
	std::string yellow = "\e[33m";
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
    ClapTrap Bob("Bob");
    ClapTrap Bob1(Bob);
    ClapTrap Zelda("Zelda");

    std::cout << std::endl;
    Bob.attack(Zelda.getName());
    Zelda.takeDamage(Bob.getAttackDamage());
    Zelda.beRepaired(12);
    Zelda.attack(Bob1.getName());
    Bob1.takeDamage(Zelda.getAttackDamage());
    Zelda.attack(Bob1.getName());
    Bob1.takeDamage(Zelda.getAttackDamage());

    std::cout << std::endl << yellow <<  "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << reset << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << green << Bob.getHitPoints() << reset << " points of hit and " << cyan << Bob.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << green << Bob1.getHitPoints() << reset << " points of hit and " << cyan << Bob1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << green << Zelda.getHitPoints() << reset << " points of hit and " << cyan << Zelda.getEnergyPoints() << reset << " points of energy left" << std::endl << std::endl;
    
	ScavTrap ST1("HELLLO");
    ScavTrap ST2(ST1);
    ScavTrap ST3("Ouille");
    std::cout << std::endl;
	
	ST1.attack(Zelda.getName());
    Zelda.takeDamage(ST1.getAttackDamage());
    ST1.guardGate();
    ST1.beRepaired(10);
	ST2.attack(ST3.getName());
	ST3.takeDamage(ST2.getAttackDamage());
	ST2.attack(ST3.getName());
	ST3.takeDamage(ST2.getAttackDamage());
	ST2.attack(ST3.getName());
	ST3.takeDamage(ST2.getAttackDamage());
	for (int i = 0; i < 51; i++)
		ST3.beRepaired(1);
	ST3.attack(Zelda.getName());
    
    std::cout << std::endl << yellow <<  "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << reset << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << green << Bob.getHitPoints() << reset << " points of hit and " << cyan << Bob.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << green << Bob1.getHitPoints() << reset << " points of hit and " << cyan << Bob1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << green << Zelda.getHitPoints() << reset << " points of hit and " << cyan << Zelda.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST1.getName() << " has " << green <<  ST1.getHitPoints() << reset << " points of hit and " << cyan << ST1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST2.getName() << " has " << green <<  ST2.getHitPoints() << reset << " points of hit and " << cyan << ST2.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST3.getName() << " has " << green <<  ST3.getHitPoints() << reset << " points of hit and " << cyan << ST3.getEnergyPoints() << reset << " points of energy left" << std::endl << std::endl;

    return 0;
}
