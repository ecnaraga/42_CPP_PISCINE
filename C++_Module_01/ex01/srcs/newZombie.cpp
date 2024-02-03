/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:39:15 by galambey          #+#    #+#             */
/*   Updated: 2024/02/03 12:23:21 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* Zombie::newZombie(std::string name) {
	
	Zombie* A = new Zombie(name);
	
	return (A);
}

Zombie* Zombie::zombieHorde(int N, std::string name) {
	
	Zombie *A;
	Zombie *tmp;

	A = (Zombie*) :: operator new(sizeof(Zombie) * N);
	tmp = A;
	if (!name.empty()) {
		for (int i = 0; i < N; i++) {
			A->name = name;
			A++;
		}
	}
	A = tmp;
	return (A);
}