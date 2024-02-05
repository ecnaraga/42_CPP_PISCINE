/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:33:26 by galambey          #+#    #+#             */
/*   Updated: 2024/02/04 10:35:09 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void) {
	
	//std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(std::string name) {
	
	this->name = name;
}

Zombie::~Zombie(void) {
	
	std::cout << "Zombie named " << this->name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
