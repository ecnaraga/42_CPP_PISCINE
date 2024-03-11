/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:00:58 by galambey          #+#    #+#             */
/*   Updated: 2024/03/06 11:26:47 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Form::Form() : _gradeSign(0), _gradeExec(0) {};

Form::Form(std::string const & name, int const gradeSign, int const gradeExec)
: _name(name) , _gradeSign(gradeSign), _gradeExec(gradeExec) {
	
	// std::cout << "Form's Default Conctructor called" << std::endl;
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	this->_sign = 0;
}

Form::Form(Form const & orig)
: _name(orig._name) , _gradeSign(orig._gradeSign), _gradeExec(orig._gradeExec) {
	
	// std::cout << "Form's Copy Conctructor called" << std::endl;
	if (orig._gradeSign > 150 || orig._gradeExec > 150)
		throw GradeTooLowException();
	if (orig._gradeSign < 1 || orig._gradeExec < 1)
		throw GradeTooHighException();
	*this = orig;
}

Form::~Form() {
	
	// std::cout << "Form's Default Destructor called" << std::endl;
}
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Form & Form::operator=(Form const & rhs) {
	
	this->_sign = rhs._sign;
	return *this;
}

std::ostream & operator<<(std::ostream & os, Form const & rhs) {
	
	return (os << rhs.getName() << ", sign grade " << rhs.getGradeSign() << ", exec grade " << rhs.getGradeExec() << ", sign " << rhs.getSign() << ".");
}
		
/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

const char * Form::GradeTooHighException::what() const throw() {
	
	return ("\e[31mgrade's too high to sign or execute\e[0m");	
}

const char * Form::GradeTooLowException::what() const throw() {
	
	return ("\e[31mgrade's too low to sign or execute\e[0m");	
}

const char *Form::FormAlreadySignedException::what() const throw () {
	
	return ("form's already signed");
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const &	Form::getName() const {
	
	return this->_name;
}

bool	Form::getSign() const {
	
	return this->_sign;
}

int		Form::getGradeSign() const {
	
	return this->_gradeSign;
}

int		Form::getGradeExec() const {
	
	return this->_gradeExec;
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void Form::beSigned(Bureaucrat const & bureaucrat) {

	if (this->_sign)
		throw FormAlreadySignedException();
	if (this->_gradeSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_sign = 1;
}
