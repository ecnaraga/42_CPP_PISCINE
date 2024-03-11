/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:32:12 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 14:57:42 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", "", 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
: AForm("robotomy request", target, 72, 45) {
	
	// std::cout << "RobotomyRequestForm's Default Conctructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & orig)
: AForm(orig) {
	
	// std::cout << "RobotomyRequestForm's Copy Conctructor called" << std::endl;
	(void) orig;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
	// std::cout << "RobotomyRequestForm's Default Destructor called" << std::endl;
}
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	
	(void) rhs;
	return *this;
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	
	static int i = 0;

	try {
		this->check_exec_requirements(executor);
		std::cout << "THWACK..THWACK.THUNK.....THWACK" << std::endl;
		if (i % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "robotomy's " << this->getTarget() << " has failed" << std::endl;
		i++;
	}
	catch (std::exception & e) {
		throw; 
	}
		
}
