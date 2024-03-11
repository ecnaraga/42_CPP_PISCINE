/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:31:43 by galambey          #+#    #+#             */
/*   Updated: 2024/03/11 10:24:17 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main( void ) {
	
	std::string title = "\e[1;34m";
	std::string title2 = "\e[1;36m";
	std::string reset = "\e[0m";
	
	std::cout << title << "CASE 1 : Nico's exception grade too high ( < 1 )" << reset << std::endl;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 0);
		Bureaucrat 	Claire_cpy(Claire);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire_cpy << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	std::cout << std::endl << title << "CASE 2 : Nico's exception grade too low ( > 150 )" << reset << std::endl;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 151);
		Bureaucrat 	Claire_cpy(Claire);

		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire_cpy << std::endl;
	}
	catch (std::exception & e) { std::cerr << e.what() << std::endl; }
	
	std::cout << std::endl << title << "CASE 3 : has to work" << reset << std::endl;
	AForm*	 	President = NULL;
	AForm*	 	Robot = NULL;
	AForm*	 	Tree = NULL;
	AForm*	 	A0 = NULL;
	AForm*	 	A1 = NULL;
	AForm*	 	A2 = NULL;
	AForm*	 	A3 = NULL;
	try {
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);
		Bureaucrat 	Nico("Nico", 65);
		Bureaucrat 	Claire_cpy(Claire);
		President = new PresidentialPardonForm("Cacao");
		Robot = new RobotomyRequestForm("Robot");
		Tree = new ShrubberyCreationForm("home");
		
		
		std::cout << std::endl << title2 << "    0. Creation Form by an Intern + sign and execute" << reset << std::endl;
		Intern randomIntern;
		A0 = randomIntern.makeForm("presidential pardon", "Marie");
		A1 = randomIntern.makeForm("robotomy request", "Aurore");
		A2 = randomIntern.makeForm("shrubbery creation", "apple_tree");
		// A3 = randomIntern.makeForm("presidential pardonn", "Marie"); // To test creation of a non existing form
		std::cout << std::endl << *A0 << std::endl;
		Claire.signForm(*A0);
		Claire.executeForm(*A0);
		std::cout << std::endl << *A1 << std::endl;
		Claire.signForm(*A1);
		Claire.executeForm(*A1);
		std::cout << std::endl << *A2 << std::endl;
		Claire.signForm(*A2);
		Claire.executeForm(*A2);
		// std::cout << *A3 << std::endl;
		// Claire.signForm(*A3);
		// Claire.executeForm(*A3);
		
		std::cout << std::endl << title2 << "    1. Operator overloaded << for Bureaucrat & AForm" << reset << std::endl;
		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire_cpy << std::endl;
		std::cout << *President << std::endl;
		std::cout << *Robot << std::endl;
		std::cout << *Tree << std::endl << std::endl;
		
		std::cout << std::endl << title2 << "    2. Sign and execute Form President" << reset << std::endl;
		Claire.executeForm(*President);
		Maelle.executeForm(*President);
		Nico.executeForm(*President);
		Nico.signForm(*President);
		Maelle.signForm(*President);
		Claire.signForm(*President);
		Nico.executeForm(*President);
		Maelle.executeForm(*President);
		Claire.executeForm(*President);
		
		std::cout << std::endl << title2 << "    3. Sign and execute Form Robot" << reset << std::endl;
		Claire.executeForm(*Robot);
		Maelle.executeForm(*Robot);
		Nico.executeForm(*Robot);
		Nico.signForm(*Robot);
		Maelle.signForm(*Robot);
		Claire.signForm(*Robot);
		Nico.executeForm(*Robot);
		Maelle.executeForm(*Robot);
		Claire.executeForm(*Robot);
		Claire.executeForm(*Robot);
		Claire.executeForm(*Robot);
		Claire_cpy.executeForm(*Robot);
		
		std::cout << std::endl << title2 << "    4. Sign and execute Form Tree" << reset << std::endl;
		Claire.executeForm(*Tree);
		Maelle.executeForm(*Tree);
		Nico.executeForm(*Tree);
		Nico.signForm(*Tree);
		Maelle.signForm(*Tree);
		Claire.signForm(*Tree);
		Nico.executeForm(*Tree);
		Maelle.executeForm(*Tree);
		Claire.executeForm(*Tree);
		
		std::cout << std::endl << title2 << "    5. Copy constructors on signed Form : execution has to be ok" << reset << std::endl;
		PresidentialPardonForm B01("B01");
		Claire.signForm(B01);
		PresidentialPardonForm B01_cpy(B01);
		Claire.executeForm(B01_cpy);
		
		RobotomyRequestForm B02("B02");
		Claire.signForm(B02);
		RobotomyRequestForm B02_cpy(B02);
		Claire.executeForm(B02_cpy);

		ShrubberyCreationForm B03("B03");
		Claire.signForm(B03);
		ShrubberyCreationForm B03_cpy(B03);
		Claire.executeForm(B03_cpy);
		std::cout << std::endl;
		delete President;
		delete Robot;
		delete Tree;
		delete A0;
		delete A1;
		delete A2;
		delete A3;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		delete President;
		delete Robot;
		delete Tree;
		delete A0;
		delete A1;
		delete A2;
		delete A3;
	}
	President = NULL;
	Robot = NULL;
	Tree = NULL;
	
	std::cout << std::endl << title << "CASE 4 : has to work" << reset << std::endl;
	try {
		Bureaucrat 	Claire_grade26("Claire_grade26", 26);
		Bureaucrat 	Claire_grade25("Claire_grade25", 25);
		Bureaucrat 	Claire_grade6("Claire_grade6", 6);
		Bureaucrat 	Claire_grade5("Claire_grade5", 5);
		Bureaucrat 	Maelle_grade73("Maelle_grade73", 73);
		Bureaucrat 	Maelle_grade72("Maelle_grade72", 72);
		Bureaucrat 	Maelle_grade46("Maelle_grade46", 46);
		Bureaucrat 	Maelle_grade45("Maelle_grade45", 45);
		Bureaucrat 	Nico_grade146("Nico_grade146", 146);
		Bureaucrat 	Nico_grade145("Nico_grade145", 145);
		Bureaucrat 	Nico_grade138("Nico_grade138", 138);
		Bureaucrat 	Nico_grade137("Nico_grade137", 137);
		President = new PresidentialPardonForm("A00");
		Robot = new RobotomyRequestForm("B00");
		Tree = new ShrubberyCreationForm("C00");
		
		std::cout << std::endl << title2 << "    1. Operator overloaded << for Bureaucrat" << reset << std::endl;
		std::cout << Claire_grade26 << std::endl;
		std::cout << Claire_grade25 << std::endl;
		std::cout << Claire_grade6 << std::endl;
		std::cout << Claire_grade5 << std::endl;
		std::cout << Maelle_grade73 << std::endl;
		std::cout << Maelle_grade72 << std::endl;
		std::cout << Maelle_grade46 << std::endl;
		std::cout << Maelle_grade45 << std::endl;
		std::cout << Nico_grade146 << std::endl;
		std::cout << Nico_grade145 << std::endl;
		std::cout << Nico_grade138 << std::endl;
		std::cout << Nico_grade137 << std::endl;
		
		std::cout << std::endl << title2 << "    2. Sign and execute Form President" << reset << std::endl;
		Claire_grade26.signForm(*President);
		Claire_grade25.signForm(*President);
		Claire_grade6.executeForm(*President);
		Claire_grade5.executeForm(*President);
		
		std::cout << std::endl << title2 << "    3. Sign and execute Form Robot" << reset << std::endl;
		Maelle_grade73.signForm(*Robot);
		Maelle_grade72.signForm(*Robot);
		Maelle_grade46.executeForm(*Robot);
		Maelle_grade45.executeForm(*Robot);
		
		std::cout << std::endl << title2 << "    4. Sign and execute Form Tree" << reset << std::endl;
		Nico_grade146.signForm(*Tree);
		Nico_grade145.signForm(*Tree);
		Nico_grade138.executeForm(*Tree);
		Nico_grade137.executeForm(*Tree);
		std::cout << std::endl;
		delete President;
		delete Robot;
		delete Tree;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		delete President;
		delete Robot;
		delete Tree;
	}

	std::cout << std::endl << title << "CASE 5 : Bureaucrate " << reset << std::endl;
	try {
		Bureaucrat 	Nico("Nico", 74);
		Bureaucrat 	Claire("Claire", 1);
		Bureaucrat 	Maelle("Maelle", 150);

		std::cout << std::endl << title2 << "    1. Operator overloaded <<" << reset << std::endl;
		std::cout << Nico << std::endl;
		std::cout << Claire << std::endl;
		std::cout << Maelle << std::endl;
		
		std::cout << std::endl << title2 << "    2. IncGrade and DecGrade" << reset << std::endl;
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
	std::cout << std::endl;
	return (0);
}
