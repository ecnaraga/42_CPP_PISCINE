/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:02:40 by galambey          #+#    #+#             */
/*   Updated: 2024/03/11 10:18:11 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		Intern();
		Intern(Intern const & orig);
		~Intern();

		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Intern & operator=(Intern const & rhs);

		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class NonExistingForm : public std::exception {
			public :
				const char * what() const throw();
		};

		class FailedAllocationForm : public std::exception {
			public:
				const char * what() const throw();
		};
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		AForm*	makePresidential(std::string target) const;
		AForm*	makeRobot(std::string target) const;
		AForm*	makeShruberry(std::string target) const;
		AForm* 	makeForm(std::string name, std::string target);
};

#endif