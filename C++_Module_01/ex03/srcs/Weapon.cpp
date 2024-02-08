/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:01:19 by garance           #+#    #+#             */
/*   Updated: 2024/02/08 17:05:02 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) {
    
    this->type = type;
    // std::cout << "Weapon " << type << " created" << std::endl;
}

Weapon::Weapon(void) {

    // std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon(void) {

    // std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}

void     Weapon::setType(std::string new_type) {
    
    this->type = new_type;
}

const std::string    &Weapon::getType(void) const {
    
    return (this->type);
}
