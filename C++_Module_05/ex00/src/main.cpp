/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:31:43 by galambey          #+#    #+#             */
/*   Updated: 2024/03/08 10:21:15 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main( void ) {
	
	std::string title = "\e[1;34m";
	std::string title2 = "\e[1;36m";
	std::string reset = "\e[0m";
	
	std::cout << title << "CASE 1 : Nico's exception grade too high ( < 1 )" << reset << std::endl;
	try {
		Bureaucrat Claire("Claire", 1);
		Bureaucrat Maelle("Maelle", 150);
		Bureaucrat Nico("Nico", 0);
		Bureaucrat Claire_cpy(Claire);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire_cpy << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	std::cout << std::endl << title << "CASE 2 : Nico's exception grade too low ( > 150 )" << reset << std::endl;
	try {
		Bureaucrat Claire("Claire", 1);
		Bureaucrat Maelle("Maelle", 150);
		Bureaucrat Nico("Nico", 151);
		Bureaucrat Claire_cpy(Claire);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire_cpy << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	std::cout << std::endl << title << "CASE 3 : has to work" << reset << std::endl;
	try {
		Bureaucrat Claire("Claire", 1);
		Bureaucrat Maelle("Maelle", 150);
		Bureaucrat Nico("Nico", 65);

		std::cout << std::endl << title2 << "    1. Operator overloaded <<" << reset << std::endl;
		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		
		std::cout << std::endl << title2 << "    2. Sign and execute Form President" << reset << std::endl;
		try {
			Nico.decGrade();
			std::cout << Nico << std::endl;
		}
		catch (std::exception & e) { std::cerr << e.what() << std::endl; }
		try {
			Nico.incGrade();
			std::cout << Nico << std::endl;
		}
		catch (std::exception & e) { std::cerr << e.what() << std::endl; }
		try {
			Nico.incGrade();
			std::cout << Nico << std::endl;
		}
		catch (std::exception & e) { std::cerr << e.what() << std::endl; }
		try {
			Claire.incGrade();
			std::cout << Claire << std::endl;
		}
		catch (std::exception & e) { std::cerr << e.what() << std::endl; }
		try {
			Claire.decGrade();
			std::cout << Claire << std::endl;
		}
		catch (std::exception & e) { std::cerr << e.what() << std::endl; }
		try {
			Maelle.decGrade();
			std::cout << Maelle << std::endl;
		}
		catch (std::exception & e) { std::cerr << e.what() << std::endl; }
		try {
			Maelle.incGrade();
			std::cout << Maelle << std::endl;
		}
		catch (std::exception & e) { std::cerr << e.what() << std::endl; }

		std::cout << std::endl << title2 << "    3. Copy Constructor" << reset << std::endl;
		Bureaucrat 	Nico_cpy(Nico);
		Bureaucrat 	Claire_cpy(Claire);
		Bureaucrat 	Maelle_cpy(Maelle);

		std::cout << Nico_cpy << std::endl;
		std::cout << Claire_cpy << std::endl;
		std::cout << Maelle_cpy << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	/* 
	Si alloc dynamique dans le try, initialiser les pointeurs a NULL avant sinon
		Conditional jump dans le catch au moment de delete et si pas de delete
		dans le catch, leaks 
	*/
	std::cout << std::endl << title << "CASE 4 : Avec pointeur et allocation dynamique" << reset << std::endl;
	Bureaucrat *Claire = NULL;
	Bureaucrat *Maelle = NULL;
	Bureaucrat *Nico = NULL;
	Bureaucrat *Claire_cpy = NULL;
	try {
		Claire = new Bureaucrat("Claire", 1);
		Maelle = new Bureaucrat("Maelle", 150);
		Nico = new Bureaucrat("Nico", 12);
		Claire_cpy = new Bureaucrat(*Claire);

		std::cout << *Claire << std::endl;
		std::cout << *Maelle << std::endl;
		std::cout << *Nico << std::endl;
		std::cout << *Claire_cpy << std::endl;
		
		delete Claire;
		delete Maelle;
		delete Nico;
		delete Claire_cpy;
	}
	catch (std::exception & e) {
		
		std::cerr << e.what() << std::endl;
		delete Claire;
		delete Maelle;
		delete Nico;
		delete Claire_cpy;
	}
	return (0);
}