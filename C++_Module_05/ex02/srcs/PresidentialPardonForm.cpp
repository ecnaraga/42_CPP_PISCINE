/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:28:32 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 14:57:04 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", "", 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
: AForm("presidential pardon", target, 25, 5) {
	
	// std::cout << "PresidentialPardonForm's Default Conctructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & orig)
: AForm(orig) {
	
	// std::cout << "PresidentialPardonForm's Copy Conctructor called" << std::endl;
	(void) orig;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
	// std::cout << "PresidentialPardonForm's Default Destructor called" << std::endl;
}
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	
	(void) rhs;
	return *this;
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	
	try {
		this->check_exec_requirements(executor);
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch (std::exception & e) {
		throw ; //permet de renvoyer l'exception "en cascade"
	}
}
