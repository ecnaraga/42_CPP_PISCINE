/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:31:43 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 13:56:55 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main( void ) {
	
	std::string title = "\e[1;34m";
	std::string title2 = "\e[1;36m";
	std::string reset = "\e[0m";
	
	std::cout << title << "CASE 1 : Bureaucrate Nico's exception grade too high ( < 1 )" << reset << std::endl;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 0);
		Bureaucrat 	Claire_cpy(Claire);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire_cpy << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	std::cout << std::endl << title << "CASE 2 : Bureaucrate Nico's exception grade too low ( > 150 )" << reset << std::endl;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 151);
		Bureaucrat 	Claire_cpy(Claire);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire_cpy << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	std::cout << std::endl << title << "CASE 3 : Form DeathSentence's exception grade too high ( < 1 )" << reset << std::endl;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 65);
		Form	 	Armistice ("Armistice", 10, 10);
		Form	 	DeathSentence ("DeathSentence", -1, 10);
		Form	 	LifeImprisonment ("LifeImprisonment", 1, 10);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	std::cout << std::endl << title << "CASE 4 : Form DeathSentence's exception grade ttoo low ( > 150 )" << reset << std::endl;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 65);
		Form	 	Armistice ("Armistice", 10, 10);
		Form	 	DeathSentence ("DeathSentence", 151, 10);
		Form	 	LifeImprisonment ("LifeImprisonment", 1, 10);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }

	std::cout << std::endl << title << "CASE 5 : has to work" << reset << std::endl;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 65);
		Form	 	Armistice ("Armistice", 10, 10);
		Form	 	LifeImprisonment ("LifeImprisonment", 67, 10);
		Form	 	Visit ("Visit", 150, 10);

		std::cout << std::endl << title2 << "    1. Operator overloaded << for Bureaucrat" << reset << std::endl;
		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Armistice << std::endl;
		std::cout << LifeImprisonment << std::endl;
		std::cout << Visit << std::endl;
		
		std::cout << std::endl << title2 << "    2. Sign Form" << reset << std::endl;
		Maelle.signForm(LifeImprisonment);
		Nico.signForm(LifeImprisonment);
		Claire.signForm(LifeImprisonment);
		Maelle.signForm(Visit);
		Nico.signForm(Visit);
		Claire.signForm(Visit);
		Maelle.signForm(Armistice);
		Nico.signForm(Armistice);
		Claire.signForm(Armistice);
		
		std::cout << std::endl << title2 << "    2. Copy constructor" << reset << std::endl;
		Bureaucrat 	Claire_cpy(Claire);
		Form	 	Armistice_cpy(Armistice);
		
		std::cout << Claire_cpy << std::endl;
		std::cout << Armistice_cpy << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }

	std::cout << std::endl << title << "CASE 6 : has to work" << reset << std::endl;
	try {
		Bureaucrat 	Nico("Nico", 65);
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Form	 	LifeImprisonment ("LifeImprisonment", 64, 10);

		std::cout << std::endl << title2 << "    1. Operator overloaded << for Bureaucrat" << reset << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << LifeImprisonment << std::endl;
		
		std::cout << std::endl << title2 << "    2. IncGrade and DecGrade" << reset << std::endl;
		Nico.signForm(LifeImprisonment);
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
		Nico.signForm(LifeImprisonment);
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
		std::cout << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	return (0);
}