/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:00 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 17:49:21 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main() {
	
	/* Pour qu'une methode fonctionne correctement, il faut que l objet est ete declare dynamiquement */
	/* Cas 1 : Pointeur et methode */
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	/* Cas 2 : Pointeur et declaration statique de la fonction membre */
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the wrongAnimal sound!
		meta->makeSound();
		
		delete meta;
		delete i; // 
	}
	std::cout << std::endl;
	/* Cas suivants : pour illustrer la necessite d utiliser des pointeurs  : le cri, 
		mais surtout le non appel du destructeur de dog ou de cat dans le cas ou pas 
		d alloc dynamique :*/
	// /* Cas 3 : Objet statique et methode */
	// {
	// 	const Animal meta = Animal();
	// 	const Animal j = Dog();
	// 	const Animal i = Cat();
		
	// 	std::cout << j.getType() << " " << std::endl;
	// 	std::cout << i.getType() << " " << std::endl;
	// 	i.makeSound(); //will output the cat sound!
	// 	j.makeSound();
	// 	meta.makeSound();
	// }
	// std::cout << std::endl;
	// /* Cas 4 : Objet statique et declaration statique de la fonction membre */
	// {
	// 	const WrongAnimal meta = WrongAnimal();
	// 	const WrongAnimal i = WrongCat();
		
	// 	std::cout << i.getType() << " " << std::endl;
	// 	i.makeSound(); //will output the wrongAnimal sound!
	// 	meta.makeSound();
	// }
	
	return 0;
}
