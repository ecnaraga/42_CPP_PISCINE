/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:55:37 by garance           #+#    #+#             */
/*   Updated: 2024/02/05 13:53:16 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) {
    
    this->name = name;
    // std::cout << "HumanA " << this->name << " constructed" <<std::endl;
    this->weapon = &weapon;
}

HumanA::~HumanA(void) {

    // std::cout << "HumanA destroyed" << std::endl;
    // this->weapon.~Weapon();
}

void    HumanA::attack(void) {

    Weapon *w;

    // w = this->weapon;
    // std::string s = (*w).getType();
    // std::cout << s << std::endl;
    
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
   