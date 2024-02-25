/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:18 by garance           #+#    #+#             */
/*   Updated: 2024/02/25 12:12:15 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

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
    
    return 0;
}
