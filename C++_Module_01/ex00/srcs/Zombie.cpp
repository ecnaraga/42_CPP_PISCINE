/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:33:26 by galambey          #+#    #+#             */
/*   Updated: 2024/02/02 15:26:56 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void) {
	
	//std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(void) {
	
	//std::cout << "Zombie destroyed" << std::endl;
}

void Zombie::name_zombie(std::string name) {
	
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}