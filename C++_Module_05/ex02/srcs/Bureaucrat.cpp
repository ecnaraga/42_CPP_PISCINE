/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:00:12 by galambey          #+#    #+#             */
/*   Updated: 2024/03/08 10:11:20 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){};
		
/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name) {
	
	// std::cout << "Bureaucrat's Default Conctructor called" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & orig) : _name(orig._name) {
	
	// std::cout << "Bureaucrat's Copy Conctructor called" << std::endl;
	*this = orig;
}

Bureaucrat::~Bureaucrat() {
	
	// std::cout << "Bureaucrat's Default Destructor called" << std::endl;
}
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	
	this->_grade = rhs._grade;
	return (*this);
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs) {
	
	return (os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".");
}
		
/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */
		
const char *	Bureaucrat::GradeTooHighException::what() const throw() {
	
	return("\e[31mgrade can't be higher than 1\e[0m");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw(){
	
	return ("\e[31mgrade can't be lower than 150\e[0m");
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const &	Bureaucrat::getName() const {
	
	return (this->_name);
}

int		Bureaucrat::getGrade() const {
	
	return (this->_grade);
}

void	Bureaucrat::incGrade() {
	
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}
void	Bureaucrat::decGrade() {
	
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}
/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void Bureaucrat::signForm(AForm & form) const {
	
	std::string red = "\e[31m";
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
	try {
		form.beSigned(*this);
		std::cout << green << this->_name << " signed " << form.getName() << "." << reset << std::endl;
	}
	catch (AForm::AlreadySignedException & e) {
		std::cerr << red << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << reset << std::endl;
	}
	catch (AForm::TooLowSignGradeException & e) {
		std::cerr << red << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << reset << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
	
	std::string red = "\e[31m";
	std::string green = "\e[32m";
	std::string reset = "\e[0m";
	
	try {
		form.check_exec_requirements(*this);
		form.execute(*this);
		std::cout << green << this->getName() << " executed " << form.getName() << reset << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << red << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << reset << std::endl;
	}
}
