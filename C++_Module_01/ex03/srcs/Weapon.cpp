/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:01:19 by garance           #+#    #+#             */
/*   Updated: 2024/02/05 14:21:16 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) {
    
    this->type = type;
    std::cout << "Weapon " << type << " created" << std::endl;
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

std::string    Weapon::getType(void) const {
    
    // std::string type_ref = this->type;
    // std::cout << "string " << type_ref << std::endl;
    // std::cout << &type_ref << std::endl;
    return (this->type);
}
