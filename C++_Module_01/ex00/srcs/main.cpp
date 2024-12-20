/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:15:42 by galambey          #+#    #+#             */
/*   Updated: 2024/02/03 10:53:31 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main()
{
	Zombie* A;

	/* Zombie alloue sur la stack */
	randomChump("Dead");
	std::cout << std::endl;
	
	/* Zombie alloue sur la heap */
	A = newZombie("ARG");
	A->announce();
	delete A;
	std::cout << std::endl;
	
	/* Autre facon d'allouer sur la heap en utilisant directement un constructeur */
	// A = new Zombie("Grr");
	// A->announce();
	// delete A;
	// std::cout << std::endl;
	
	return (0);
}
