/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:21:30 by galambey          #+#    #+#             */
/*   Updated: 2024/03/08 10:17:28 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <typeinfo>
# include <exception>

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
		
		/* en private car 1 attribut constant => je veux donc utiliser le = pour
			le constructeur par copie mais pas dans le main */
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
} ;

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs);

#endif