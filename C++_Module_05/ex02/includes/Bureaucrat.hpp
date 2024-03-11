/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:21:30 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 11:19:01 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"


class Bureaucrat {
	
	private :
		std::string const _name;
		int _grade;
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		Bureaucrat();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Bureaucrat & operator=(Bureaucrat const & rhs);
		
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & orig);
		~Bureaucrat();

		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */
		
		class	GradeTooHighException : public std::exception {
			public :
				const char * what() const throw();
		};
		
		class	GradeTooLowException : public std::exception {
			public :
				const char * what() const throw();
		};
		
		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		std::string const &	getName() const; 
		int		getGrade() const;
		void	incGrade() ;
		void	decGrade() ;

		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void signForm(AForm & form) const;
		void executeForm(AForm const & form) const;
} ;

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs);

#endif