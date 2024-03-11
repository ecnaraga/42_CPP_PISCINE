/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:51:34 by galambey          #+#    #+#             */
/*   Updated: 2024/03/11 10:25:27 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Intern::Intern() {
	
	// std::cout << "Intern's Default Conctructor called" << std::endl;
}

Intern::Intern(Intern const & orig) {
	
	// std::cout << "Intern's Copy Conctructor called" << std::endl;
	*this = orig;
}

Intern::~Intern() {
	
	// std::cout << "Intern's Destructor called" << std::endl;
}

		
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Intern & Intern::operator=(Intern const & rhs) {
	
	(void) rhs;
	return *this;
}


/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

const char * Intern::NonExistingForm::what() const throw() {
	
	return ("\e[31mform doesn't exist\e[0m");
}

const char * Intern::FailedAllocationForm::what() const throw() {
	
	return ("\e[31mdynamic allocation's form failed\e[0m");
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */
AForm*	Intern::makePresidential(std::string target) const {
	
	return (new PresidentialPardonForm(target));
}
AForm*	Intern::makeRobot(std::string target) const {
	
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeShruberry(std::string target) const {
	
	return (new ShrubberyCreationForm(target));
}
		
AForm* Intern::makeForm(std::string name, std::string target) {
	
	std::string form[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (Intern::*f[3])(std::string) const = {&Intern::makePresidential, &Intern::makeRobot, &Intern::makeShruberry};
	int i;
	
	for (i = 0; i < 3; i++)
		if (name == form[i]) {
			AForm* creation = (this->*f[i])(target);
			if (!creation)
				throw FailedAllocationForm();
			std::cout << "Intern creates " << *creation << std::endl;
			return creation;
		}
	throw (NonExistingForm());
}

