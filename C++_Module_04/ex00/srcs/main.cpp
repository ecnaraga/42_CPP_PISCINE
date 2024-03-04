/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:00 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:29:25 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

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
	
	/* Pour qu'une methode fonctionne correctement, il faut que l objet est ete declare dynamiquement */
	/* Cas 1 : Pointeur et methode */
	ft_title("Test Animal Dog and Cat class");
	{
		const Animal* meta = new Animal();
		if (!meta)
			return ft_error();
		const Animal* j = new Dog();
		if (!j)
			return (delete meta, ft_error());
		const Animal* i = new Cat();
		if (!i)
			return (delete meta, delete j, ft_error());
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		std::cout << std::endl;
		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	/* Cas 2 : Pointeur et declaration statique de la fonction membre */
	ft_title("Test Wrong Animal and Wrong Cat class");
	{
		const WrongAnimal* meta = new WrongAnimal();
		if (!meta)
			return ft_error();
		const WrongAnimal* i = new WrongCat();
		if (!i)
			return (delete meta, ft_error());
		const WrongCat* j = new WrongCat();
		if (!j)
			return (delete meta, delete i, ft_error());
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound(); //will output the wrongAnimal sound!
		j->makeSound(); //will output the wrongCat sound!
		
		std::cout << std::endl;
		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	/* Cas suivants : pour illustrer la necessite d utiliser des pointeurs  : le cri, 
		mais surtout le non appel du destructeur de dog ou de cat dans le cas ou pas 
		d alloc dynamique :*/
	// /* Cas 3 : Objet statique et methode */
	// ft_title("Same tests with Static object");
	// {
	// 	const Animal meta = Animal();
	// 	const Animal j = Dog();
	// 	const Animal i = Cat();
		
	// 	std::cout << j.getType() << " " << std::endl;
	// 	std::cout << i.getType() << " " << std::endl;
	// 	i.makeSound(); //will output the cat sound!
	// 	j.makeSound();
	// 	meta.makeSound();
	// 	std::cout << std::endl;
	// }
	// std::cout << std::endl;
	// /* Cas 4 : Objet statique et declaration statique de la fonction membre */
	// {
	// 	const WrongAnimal meta = WrongAnimal();
	// 	const WrongAnimal i = WrongCat();
		
	// 	std::cout << i.getType() << " " << std::endl;
	// 	i.makeSound(); //will output the wrongAnimal sound!
	// 	meta.makeSound();
	// 	std::cout << std::endl;
	// }
	std::cout << std::endl;
	/* Copy constructor test */
	ft_title("Copy constructor");
	{
		const Dog A = Dog();
		const Dog B = Dog (A);
		
		std::cout << A.getType() << " " << std::endl;
		std::cout << B.getType() << " " << std::endl;
		A.makeSound();
		B.makeSound();
		
		const Cat C = Cat();
		const Cat D = Cat (C);
		
		std::cout << C.getType() << " " << std::endl;
		std::cout << D.getType() << " " << std::endl;
		C.makeSound();
		D.makeSound();

		const WrongCat E = WrongCat();
		const WrongCat F = WrongCat (E);
		
		std::cout << E.getType() << " " << std::endl;
		std::cout << F.getType() << " " << std::endl;
		E.makeSound();
		F.makeSound();

		Animal* G = new Dog(A);
		if (!G)
			return (ft_error());
		std::cout << G->getType() << " " << std::endl;
		G->makeSound();
		
		std::cout << std::endl;
		delete G;

		Animal* H = new Cat(C);
		if (!H)
			return (ft_error());
		G = H;
		std::cout << G->getType() << " " << std::endl;
		G->makeSound();
		std::cout << H->getType() << " " << std::endl;
		H->makeSound();
		
		std::cout << std::endl;
		delete H;
	}
	return 0;
}
