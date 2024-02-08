/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:55:37 by garance           #+#    #+#             */
/*   Updated: 2024/02/08 17:06:14 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

/* 
Dans le prototype on voit qu on recoit en parametre la reference de weapon (soit
	un alias de la weapon envoye par le main), soit le meme objet avec la meme adresse. 
	Si on avait ecrit Weapon weapon a la place, on aurait rappeler le constructeur
	par default (et donc creer un nouvel objet) qui lorsqu'il cree l'objet ne copiera 
	pas ce qui etait dans l objet envoye par le main

Human A a en attribut une reference sur weapon et non un pointeur car Human A aura
	toujours une arme, weapon ne sera donc jamais = a NULL.
*/
HumanA::HumanA(const std::string &n, Weapon &w) : name(n), weapon(w) {
    
    // this->name = name;
    // this->weapon = w; // PAS POSSIBLE D initialiser weapon de cette facon
						 // car c est une ref dans Human A, il faut donc l'initialiser
						 // a cote du prototype
    // std::cout << "HumanA " << this->name << " constructed" <<std::endl;
}

HumanA::~HumanA(void) {

    // std::cout << "HumanA destroyed" << std::endl;
}

void    HumanA::attack(void) {

if (this->weapon.getType().empty())
    std::cout << this->name << " attacks with their hands" << std::endl;
else
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
   