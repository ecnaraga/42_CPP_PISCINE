/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:39:15 by galambey          #+#    #+#             */
/*   Updated: 2024/02/03 10:27:43 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* newZombie(std::string name) {

	Zombie *new_zombie;

	new_zombie = new Zombie(name); // il faudra utiliser delete lorsqu on aura plus besoin de l'objet pour liberer la memoire.
	return (new_zombie);
}
