/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:01:19 by garance           #+#    #+#             */
/*   Updated: 2024/02/04 19:16:12 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) {
    
    this->type = type;
    // std::cout << "Weapon " << type << " created" << std::endl;
}

Weapon::Weapon(void) {

    // std::cout << "Weapon destroyed" << std::endl;
}

Weapon::~Weapon(void) {

    std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}

void     Weapon::setType(std::string new_type) {
    
    this->type = new_type;
}

std::string&    Weapon::getType(void) {
    
    std::string &type_ref = this->type;
    std::cout << type_ref << std::endl;
    return (type_ref);
}
