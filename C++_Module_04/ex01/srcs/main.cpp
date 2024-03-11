/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:00 by galambey          #+#    #+#             */
/*   Updated: 2024/03/04 11:58:03 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int ft_error( const Animal *a, const Animal *b , Dog *c, Cat *d ) {
	
	std::cout << "Dynamic allocation failure" << std::endl;
	delete a;
	delete b;
	delete c;
	delete d;
	return (1);
}

int ft_error( Animal **AnimalTab ) {
	
	std::cout << "Dynamic allocation failure" << std::endl;
	if (AnimalTab)
		for (int i = 0; i < 10; i++)
			delete AnimalTab[i];
	delete[] AnimalTab;
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
		const Animal* j = NULL;
		const Animal* i = NULL;
		try {
			j = new Dog();
			if (!j)
				return (1);
			i = new Cat();
			if (!i)
				return (ft_error(i, j, NULL, NULL));
			delete j;//should not create a leak
			delete i;
		}
		catch (int e) {
			return (ft_error(i, j, NULL, NULL));
		}
	}
	std::cout << std::endl;
	/* TO TEST DEEP COPY */
	ft_title("To test deep copy");
	{
		Dog* j = NULL;
		Cat* i = NULL;
		Animal* h = NULL;
		Animal* k = NULL;
		
		try {
			j = new Dog();
			if (!j)
				return (1);
			i = new Cat();
			if (!i)
				return (ft_error(h, k, j, i));
			
			std::cout << "Dog's Idea" << std::endl;
			j->setBrain("I need water");
			j->setBrain("I need to run");
			j->printBrain();
			std::cout << "Cat's Idea" << std::endl;
			i->setBrain("I need food's cat");
			i->printBrain();
			
			h = new Dog(*j);
			if (!h)
				return (ft_error(h, k, j, i));
			k = new Cat(*i);
			if (!k)
				return (ft_error(h, k, j, i));
			Dog		l = Dog();
			Cat		m = Cat();
			
			l = *j;
			m = *i;
			delete j;
			j = NULL;
			delete i;
			i = NULL;
			
			std::cout << "Copy Dog's Idea" << std::endl;
			h->printBrain();
			l.printBrain();
			std::cout << "Copy Cat's Idea" << std::endl;
			k->printBrain();
			m.printBrain();
			
			std::cout << std::endl;
			delete h;
			h = NULL;
			delete k;
			k = NULL;

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
		catch (int e) {
			return (ft_error(h, k, j, i));
		}
	}
	std::cout << std::endl;
	/* ASKED TEST */
	ft_title("Asked Tests");
	{
		Animal **AnimalTab = NULL;
		try {
			AnimalTab = new Animal*[10];
			if (!AnimalTab)
				return (1);
			for (int i = 0; i < 10; i++)
				AnimalTab[i] = NULL;

			for (int i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					AnimalTab[i] = new Dog();
					if (!AnimalTab[i])
						return (ft_error(AnimalTab));	
				}
				else {
					AnimalTab[i] = new Cat();
					if (!AnimalTab[i])
						return (ft_error(AnimalTab));					
				}
			}
			std::cout << std::endl;
			for (int i = 0; i < 10; i++)
				AnimalTab[i]->makeSound();
			std::cout << std::endl;
			for (int i = 0; i < 10; i++)
				delete AnimalTab[i];
			delete[] AnimalTab;
		}
		catch (int e) {
			return (ft_error(AnimalTab));
		}
	}
	
	return 0;
}
