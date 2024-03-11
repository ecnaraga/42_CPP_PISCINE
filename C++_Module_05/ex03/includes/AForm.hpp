/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:21:30 by galambey          #+#    #+#             */
/*   Updated: 2024/03/11 10:25:44 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <typeinfo>
# include <exception>

class Bureaucrat;

class AForm {
	
	private :
		std::string const _name;
		std::string _target;
		bool _sign;
		int const _gradeSign;
		int const _gradeExec;
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		AForm();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		AForm & operator=(AForm const & rhs);
		
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		AForm(std::string const & name, std::string const & target, int const gradeSign, int const gradeExec);
		AForm(AForm const & orig);
		virtual ~AForm();

		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */
		
		class TooHighGradeException : public std::exception {
			public :
				const char * what() const throw();
		} ;

		class TooLowSignGradeException : public std::exception {
			public :
				const char * what() const throw();
		} ;

		class AlreadySignedException : public std::exception {
			public :
				const char * what() const throw();
		} ;

		class NotSignedException : public std::exception {
			public :
				const char * what() const throw();
		} ;

		class TooLowExecuteGradeException : public std::exception {
			public :
				const char * what() const throw();
		} ;
		
		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		std::string const &	getName() const;
		std::string const &	getTarget() const;
		bool		getSign() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void beSigned(Bureaucrat const & bureaucrate);
		void check_exec_requirements(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
} ;

std::ostream & operator<<(std::ostream & os, AForm const & rhs);

#endif