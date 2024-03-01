/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:00 by galambey          #+#    #+#             */
/*   Updated: 2024/02/28 12:31:03 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
	
	/* MAIN TEST */
	{
		const A_Animal* j = new Dog();
		const A_Animal* i = new Cat();
		(void)j;
		(void) i;
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
		A_Animal* h = new Dog(*j);
		A_Animal* k = new Cat(*i);
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
		A_Animal **A_AnimalTab = new A_Animal*[10];

		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0)
				A_AnimalTab[i] = new Dog();
			else
				A_AnimalTab[i] = new Cat();
		}
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			A_AnimalTab[i]->makeSound();
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete A_AnimalTab[i];
		delete[] A_AnimalTab;
	}
	
	return 0;
}
