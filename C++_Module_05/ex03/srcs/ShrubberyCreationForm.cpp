/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:13:11 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 14:58:31 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", "", 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
: AForm("shrubbery creation", target, 145, 137) {
	
	// std::cout << "ShrubberyCreationForm's Default Conctructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & orig)
: AForm(orig) {
	
	// std::cout << "ShrubberyCreationForm's Copy Conctructor called" << std::endl;
	(void) orig;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
	// std::cout << "ShrubberyCreationForm's Default Destructor called" << std::endl;
}
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	
	(void) rhs;
	return *this;
}

/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

const char * ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	
	return ("file failed to open");
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
	try {
		this->check_exec_requirements(executor);
		std::ofstream tree_file;
		std::string tmp = this->getTarget() + "_shrubbery";
		
		tree_file.open(tmp.c_str());
		if (!tree_file.is_open())
			throw (FileNotOpenException());
		tree_file << "         # #### ####" << std::endl
<< "      ### \\/#|### |/####" << std::endl
<< "     ##\\/#/ \\||/##/_/##/_#" << std::endl
<< "   ###  \\/###|/ \\/ # ###" << std::endl
<< " ##_\\_#\\_\\## | #/###_/_####" << std::endl
<< "## #### # \\ #| /  #### ##/##" << std::endl
<< " __#_--###`  |{,###---###-~" << std::endl
<< "           \\ }{" << std::endl
<< "            }}{" << std::endl
<< "            }}{" << std::endl
<< "            {{}" << std::endl
<< "      , -=-~{ .-^- _" << std::endl
<< "            `}" << std::endl
<< "             {" << std::endl;
		tree_file.close();
	}
	catch (std::exception & e) {
		throw ;
	}
}
