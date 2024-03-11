/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:00:58 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 14:13:09 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _gradeSign(0), _gradeExec(0) {};
		
/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

AForm::AForm(std::string const & name, std::string const & target, int const gradeSign, int const gradeExec)
: _name(name) , _target(target) , _gradeSign(gradeSign), _gradeExec(gradeExec) {
	
	// std::cout << "AForm's Default Conctructor called" << std::endl;
	if (gradeSign > 150)
		throw TooLowSignGradeException();
	if (gradeExec > 150)
		throw TooLowExecuteGradeException();
	if (gradeSign < 1 || gradeExec < 1)
		throw TooHighGradeException();
	this->_sign = 0;
}

AForm::AForm(AForm const & orig)
: _name(orig._name) , _gradeSign(orig._gradeSign), _gradeExec(orig._gradeExec) {
	
	// std::cout << "AForm's Copy Conctructor called" << std::endl;
	if (orig._gradeSign > 150)
		throw TooLowSignGradeException();
	if (orig._gradeExec > 150)
		throw TooLowExecuteGradeException();
	if (orig._gradeSign < 1 || orig._gradeExec < 1)
		throw TooHighGradeException();
	*this = orig;
}

AForm::~AForm() {
	
	// std::cout << "AForm's Default Destructor called" << std::endl;
}
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

AForm & AForm::operator=(AForm const & rhs) {
	
	this->_target = rhs._target;
	this->_sign = rhs._sign;
	return *this;
}

std::ostream & operator<<(std::ostream & os, AForm const & rhs) {
	
	return (os << rhs.getName() << ", target " << rhs.getTarget() << ", sign grade " << rhs.getGradeSign() << ", exec grade " << rhs.getGradeExec() << ", sign " << rhs.getSign() << ".");
}
		
/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

const char * AForm::TooHighGradeException::what() const throw() {
	
	return ("\e[31msign or execute grade can't be higher than 1\e[0m");
}

const char * AForm::TooLowSignGradeException::what() const throw() {
	
	return ("\e[31msign grade is too low to sign\e[0m");
}

const char * AForm::AlreadySignedException::what() const throw() {
	
	return ("\e[31mform is already signed\e[0m");
}

const char * AForm::NotSignedException::what() const throw() {
	
	return ("\e[31mform hasn't been signed yet\e[0m");
}

const char * AForm::TooLowExecuteGradeException::what() const throw() {
	
	return ("\e[31mexecute grade is too low to execute\e[0m");
}


/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const &	AForm::getName() const {
	
	return this->_name;
}

std::string const &	AForm::getTarget() const {
	
	return this->_target;
}

bool	AForm::getSign() const {
	
	return this->_sign;
}

int		AForm::getGradeSign() const {
	
	return this->_gradeSign;
}

int		AForm::getGradeExec() const {
	
	return this->_gradeExec;
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void AForm::beSigned(Bureaucrat const & bureaucrat) {

	if (this->_sign)
		throw AlreadySignedException();
	if (this->_gradeSign < bureaucrat.getGrade())
		throw TooLowSignGradeException();
	this->_sign = 1;
}

void AForm::check_exec_requirements(Bureaucrat const & executor) const {
	
	if (!this->getSign())
		throw(NotSignedException());
	if (executor.getGrade() > this->getGradeExec())
		throw(TooLowExecuteGradeException());
}
