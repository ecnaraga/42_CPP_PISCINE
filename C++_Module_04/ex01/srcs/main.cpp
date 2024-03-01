/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:00 by galambey          #+#    #+#             */
/*   Updated: 2024/02/28 14:10:04 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
	
	/* MAIN TEST */
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
		std::cout << std::endl;
	/* TO TEST DEEP COPY */
	{
		Dog* j = new Dog();
		Cat* i = new Cat();
		
		std::cout << "Dog's Idea" << std::endl;
		j->setBrain("I need water");
		j->setBrain("I need to run");
		j->printBrain();
		std::cout << "Cat's Idea" << std::endl;
		i->setBrain("I need food's cat");
		i->printBrain();
		Animal* h = new Dog(*j);
		Animal* k = new Cat(*i);
		std::cout << "Copy Dog's Idea" << std::endl;
		h->printBrain();
		std::cout << "Copy Cat's Idea" << std::endl;
		k->printBrain();
		delete j;//should not create a leak
		delete i;
		delete h;
		delete k;
	}
		std::cout << std::endl;
	/* ASKED TEST */
	{
		Animal **AnimalTab = new Animal*[10];

		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0)
				AnimalTab[i] = new Dog();
			else
				AnimalTab[i] = new Cat();
		}
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			AnimalTab[i]->makeSound();
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete AnimalTab[i];
		delete[] AnimalTab;
	}
	
	return 0;
}
