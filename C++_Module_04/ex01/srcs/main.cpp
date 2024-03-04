/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:00 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 13:04:18 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int ft_error( void ) {
	
	std::cout << "Dynamic allocation failure" << std::endl;
	return (1);
}

void	ft_title(std::string const & title) {

	std::string format = "\e[1;6;34m";
	std::string reset = "\e[0m";

	std::cout << format << title << reset << std::endl;
}

int main() {
	
	/* MAIN TEST */
	ft_title("Subject main test");
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	/* TO TEST DEEP COPY */
	ft_title("To test deep copy");
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
		Dog		l = Dog();
		Cat		m = Cat();
		
		l = *j;
		m = *i;
		delete j;
		delete i;
		
		std::cout << "Copy Dog's Idea" << std::endl;
		h->printBrain();
		l.printBrain();
		std::cout << "Copy Cat's Idea" << std::endl;
		k->printBrain();
		m.printBrain();
		
		std::cout << std::endl;
		delete h;
		delete k;

		Dog basic = Dog();
		basic.setBrain("Should still exist");
		basic.printBrain();
		std::cout << std::endl;
		{
			Dog tmp = Dog(basic);
			tmp.printBrain();
			std::cout << std::endl;
		}
		basic.printBrain();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	/* ASKED TEST */
	ft_title("Asked Tests");
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
