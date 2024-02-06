/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:05:03 by garance           #+#    #+#             */
/*   Updated: 2024/02/05 15:43:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) {
    
    this->name = name;
	this->weapon = NULL;
    std::cout << "HumanB " << this->name << " constructed" <<std::endl;
}

HumanB::~HumanB(void) {

    std::cout << "HumanB destroyed" << std::endl;
    // this->weapon.~Weapon();
}

void    HumanB::attack(void) {

    if (!this->weapon)
        std::cout << this->name << " attacks unarmed" << std::endl;
    else {
    	std::string type = this->weapon->getType();
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}

/* 
Dans le prototype on voit qu on recoit en parametre la reference de weapon (soit
	un alias de la weapon envoye par le main), soit le meme objet avec la meme adresse. 
	Si on avait ecrit Weapon weapon a la place, on aurait rappeler le constructeur
	par default (et donc creer un nouvel objet) qui lorsqu'il cree l'objet ne copiera 
	pas ce qui etait dans l objet envoye par le main 
*/
void    HumanB::setWeapon(Weapon &weapon) {
    
    this->weapon = &weapon;
}