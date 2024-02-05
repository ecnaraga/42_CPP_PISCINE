/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:39:15 by galambey          #+#    #+#             */
/*   Updated: 2024/02/04 10:52:52 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name) {
	
	Zombie *A;

	A = new Zombie[N];

	/* Incrementation de l'index */
	if (!name.empty()) {
		for (int i = 0; i < N; i++) {
			A[i].name = name;
		}
	}

	/* Incrementation du pointeur */
	// Zombie *tmp;
	// tmp = A;
	// if (!name.empty()) {
	// 	for (int i = 0; i < N; i++) {
	// 		A->name = name;
	// 		A++;
	// 	}
	// }
	// A = tmp;
	
	return (A);
}
