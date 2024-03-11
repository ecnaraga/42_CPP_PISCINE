/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:57:36 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 11:14:02 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstring>

class ShrubberyCreationForm : public AForm {
	
	private :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		ShrubberyCreationForm();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & orig);
		~ShrubberyCreationForm();

		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */
		
		class FileNotOpenException : public std::exception {
			public :
				const char * what() const throw();
		};
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void execute(Bureaucrat const & executor) const;
} ;

#endif
