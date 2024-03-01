/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:18 by garance           #+#    #+#             */
/*   Updated: 2024/02/27 15:52:46 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main(void) {
    
	std::string cyan = "\e[36m";
	std::string yellow = "\e[33m";
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
    ClapTrap Bob("Bob");
    std::cout << std::endl;
    ClapTrap Bob1(Bob);
    std::cout << std::endl;
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
    std::cout << std::endl;
    ScavTrap ST2(ST1);
    std::cout << std::endl;
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
    
    std::cout << std::endl << yellow <<  "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << reset << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << green << Bob.getHitPoints() << reset << " points of hit and " << cyan << Bob.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << green << Bob1.getHitPoints() << reset << " points of hit and " << cyan << Bob1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << green << Zelda.getHitPoints() << reset << " points of hit and " << cyan << Zelda.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST1.getName() << " has " << green <<  ST1.getHitPoints() << reset << " points of hit and " << cyan << ST1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST2.getName() << " has " << green <<  ST2.getHitPoints() << reset << " points of hit and " << cyan << ST2.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST3.getName() << " has " << green <<  ST3.getHitPoints() << reset << " points of hit and " << cyan << ST3.getEnergyPoints() << reset << " points of energy left" << std::endl << std::endl;

	FragTrap FT1;
    std::cout << std::endl;
	FragTrap FT2(FT1);
    std::cout << std::endl;
	FragTrap FT3("Monter");
    std::cout << std::endl;
	
	FT1.attack(Zelda.getName());
	Zelda.takeDamage(FT1.getAttackDamage());
	ST2.attack(FT1.getName());
	FT1.takeDamage(ST1.getAttackDamage());
	FT1.beRepaired(10);
	FT3.attack(FT2.getName());
	FT2.takeDamage(FT3.getAttackDamage());
	
    
    std::cout << std::endl << yellow <<  "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << reset << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << green << Bob.getHitPoints() << reset << " points of hit and " << cyan << Bob.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << green << Bob1.getHitPoints() << reset << " points of hit and " << cyan << Bob1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << green << Zelda.getHitPoints() << reset << " points of hit and " << cyan << Zelda.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST1.getName() << " has " << green <<  ST1.getHitPoints() << reset << " points of hit and " << cyan << ST1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST2.getName() << " has " << green <<  ST2.getHitPoints() << reset << " points of hit and " << cyan << ST2.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST3.getName() << " has " << green <<  ST3.getHitPoints() << reset << " points of hit and " << cyan << ST3.getEnergyPoints() << reset << " points of energy left" << std::endl;
	std::cout << FT1.getName() << " has " << green << FT1.getHitPoints() << reset << " points of hit and " << cyan << FT1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << FT2.getName() << " has " << green << FT2.getHitPoints() << reset << " points of hit and " << cyan << FT2.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << FT3.getName() << " has " << green << FT3.getHitPoints() << reset << " points of hit and " << cyan << FT3.getEnergyPoints() << reset << " points of energy left" << std::endl << std::endl;
    
	DiamondTrap DT1;
    std::cout << std::endl;
	DiamondTrap DT2("Diamond");
    std::cout << std::endl;

    std::cout << DT1.getName() << " has " << DT1.getHitPoints() << " points of hit and " << DT1.getEnergyPoints() << " points of energy left" << std::endl << std::endl;
	DT2.whoAmI();
	DT2.highFivesGuys();
	DT2.guardGate();
	DT2.attack(DT1.getName());
	DT1.takeDamage(DT2.getAttackDamage());
	FT3.attack(DT1.getName());
	DT1.takeDamage(FT3.getAttackDamage());

    std::cout << std::endl;
	
	DiamondTrap DT3(DT1);
    std::cout << std::endl;
	ClapTrap CT1(DT3);
	
    std::cout << std::endl << yellow <<  "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << reset << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << green << Bob.getHitPoints() << reset << " points of hit and " << cyan << Bob.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << green << Bob1.getHitPoints() << reset << " points of hit and " << cyan << Bob1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << green << Zelda.getHitPoints() << reset << " points of hit and " << cyan << Zelda.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST1.getName() << " has " << green <<  ST1.getHitPoints() << reset << " points of hit and " << cyan << ST1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST2.getName() << " has " << green <<  ST2.getHitPoints() << reset << " points of hit and " << cyan << ST2.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << ST3.getName() << " has " << green <<  ST3.getHitPoints() << reset << " points of hit and " << cyan << ST3.getEnergyPoints() << reset << " points of energy left" << std::endl;
	std::cout << FT1.getName() << " has " << green << FT1.getHitPoints() << reset << " points of hit and " << cyan << FT1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << FT2.getName() << " has " << green << FT2.getHitPoints() << reset << " points of hit and " << cyan << FT2.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << FT3.getName() << " has " << green << FT3.getHitPoints() << reset << " points of hit and " << cyan << FT3.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << DT1.getName() << " has " << green << DT1.getHitPoints() << reset << " points of hit and " << cyan << DT1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << DT2.getName() << " has " << green << DT2.getHitPoints() << reset << " points of hit and " << cyan << DT2.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << DT3.getName() << " has " << green << DT3.getHitPoints() << reset << " points of hit and " << cyan << DT3.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << CT1.getName() << " has " << green << CT1.getHitPoints() << reset << " points of hit and " << cyan << CT1.getEnergyPoints() << reset << " points of energy left" << std::endl << std::endl;
	
    return 0;
}
