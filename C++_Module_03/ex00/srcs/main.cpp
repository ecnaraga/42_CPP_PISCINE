/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:18 by garance           #+#    #+#             */
/*   Updated: 2024/02/26 17:29:42 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void) {
    
	std::string cyan = "\e[36m";
	std::string yellow = "\e[33m";
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
    ClapTrap Bob("Bob");
    ClapTrap Bob1(Bob);
    ClapTrap Zelda("Zelda");

    std::cout << std::endl;
    Bob.attack("Zelda");
    Zelda.takeDamage(Bob.getAttackDamage());
    Zelda.beRepaired(12);
    Zelda.attack("Bob1");
    Bob1.takeDamage(Zelda.getAttackDamage());
    Zelda.attack("Bob1");
    Bob1.takeDamage(Zelda.getAttackDamage());

    std::cout << std::endl << yellow <<  "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         SCORES                         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << reset << std::endl << std::endl;
    
    std::cout << Bob.getName() << " has " << green << Bob.getHitPoints() << reset << " points of hit and " << cyan << Bob.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Bob1.getName() << " has " << green << Bob1.getHitPoints() << reset << " points of hit and " << cyan << Bob1.getEnergyPoints() << reset << " points of energy left" << std::endl;
    std::cout << Zelda.getName() << " has " << green << Zelda.getHitPoints() << reset << " points of hit and " << cyan << Zelda.getEnergyPoints() << reset << " points of energy left" << std::endl << std::endl;
    
    return 0;
}
