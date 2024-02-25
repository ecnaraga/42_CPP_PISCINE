/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:18 by garance           #+#    #+#             */
/*   Updated: 2024/02/25 12:35:56 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main(void) {
    
    ClapTrap Bob("Bob");
    ClapTrap Bob1(Bob);
    ClapTrap Zelda("Zelda");

    std::cout << std::endl;
    Bob.attack("Zelda");
    Zelda.takeDamage(Bob.getAttackDamage());
    Zelda.beRepaired(12);
    // Zelda.setAttackDamage(6);
    Zelda.attack("Bob1");
    Bob1.takeDamage(Zelda.getAttackDamage());
    Zelda.attack("Bob1");
    Bob1.takeDamage(Zelda.getAttackDamage());

    std::cout << std::endl << "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << Bob.getHitPoints() << " points of hit and " << Bob.getEnergyPoints() << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << Bob1.getHitPoints() << " points of hit and " << Bob1.getEnergyPoints() << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << Zelda.getHitPoints() << " points of hit and " << Zelda.getEnergyPoints() << " points of energy left" << std::endl << std::endl;

    // /* ScavTrap a herite de ClapTrap en public : */
    // ClapTrap* CT1;
    // ScavTrap* ST1 = new ScavTrap("HELLLO");
    // ScavTrap* ST2 = new ScavTrap(*ST1);
    
    // CT1 = ST2;
    // ST1->attack("Zelda");
    // Zelda.takeDamage(CT1->getAttackDamage());

    /* ScavTrap a herite de ClapTrap en protege  ou public : */
    ScavTrap* ST1 = new ScavTrap("HELLLO");
    ScavTrap* ST2 = new ScavTrap(*ST1);
    
    ST1->attack("Zelda");
    Zelda.takeDamage(ST1->getAttackDamage());
    ST1->guardGate();
    // ST1->ClapTrap::beRepaired(); // ne marche pas si protege
    
    std::cout << std::endl << "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << Bob.getHitPoints() << " points of hit and " << Bob.getEnergyPoints() << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << Bob1.getHitPoints() << " points of hit and " << Bob1.getEnergyPoints() << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << Zelda.getHitPoints() << " points of hit and " << Zelda.getEnergyPoints() << " points of energy left" << std::endl;
    std::cout << ST1->getName() << " has " <<  ST1->getHitPoints() << " points of hit and " << ST1->getEnergyPoints() << " points of energy left" << std::endl;
    std::cout << ST2->getName() << " has " <<  ST2->getHitPoints() << " points of hit and " << ST2->getEnergyPoints() << " points of energy left" << std::endl << std::endl;
    
    delete ST1;
    delete ST2;
    return 0;
}
