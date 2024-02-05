/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:05:03 by garance           #+#    #+#             */
/*   Updated: 2024/02/04 18:51:51 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) {
    
    this->name = name;
    // std::cout << "HumanB " << this->name << " constructed" <<std::endl;
}

HumanB::~HumanB(void) {

    // std::cout << "HumanB destroyed" << std::endl;
    // this->weapon.~Weapon();
}

void    HumanB::attack(void) {

    std::string &type = this->weapon.getType();
    if (type.empty())
        std::cout << this->name << " attacks unarmed" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void    HumanB::setWeapon(Weapon weapon) {
    
    this->weapon = weapon;
}