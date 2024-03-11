/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:21:30 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 11:15:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <typeinfo>
# include <exception>

class Bureaucrat;

class Form {
	
	private :
		std::string const _name;
		bool _sign;
		int const _gradeSign;
		int const _gradeExec;
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		Form();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Form & operator=(Form const & rhs);
		
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		Form(std::string const & name, int const gradeSign, int const gradeExec);
		Form(Form const & orig);
		~Form();

		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */
		
		class GradeTooHighException : public std::exception {
			public :
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				const char * what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public :
				const char * what() const throw();
		};
		
		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		std::string const &	getName() const; 
		bool		getSign() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void beSigned(Bureaucrat const & bureaucrate);
} ;

std::ostream & operator<<(std::ostream & os, Form const & rhs);

#endif